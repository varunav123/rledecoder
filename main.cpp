#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
	ifstream fileout;
	fileout.open("fileout.txt");
	string s;
	stringstream ss;
	ss << fileout.rdbuf();
	s = ss.str();
	fileout.close();
	int j = 1;
	ofstream file;
	file.open("file.txt");
	int i = 0;
	while ( i < s.size())
	{
		int j = 1;
		for (; j > 0; j++)
		{
			if (isdigit(s[i + j]))
			{
				continue;
			}
			else break;
		}
		int k = j;
		string sub = s.substr(i + 1, j-1);
		int len = stoi(sub);
		for (; len > 0; len--)
		{
			file << s[i];
		}
		i = i + k;
	}
	file.close();
}
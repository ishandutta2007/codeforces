#include<iostream>
#include<string>
using namespace std;
string s[22];
bool check()
{
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (i<6 && s[i][j]==s[i+1][j] && s[i+1][j]==s[i+2][j] &&
			s[i+2][j]==s[i+3][j] && s[i+3][j]==s[i+4][j] && s[i][j]=='X') return 1;
			if (j<6 && s[i][j]==s[i][j+1] && s[i][j+1]==s[i][j+2] &&
			s[i][j+2]==s[i][j+3] && s[i][j+3]==s[i][j+4] && s[i][j]=='X') return 1;
			if (i<6 && j<6 && s[i][j]==s[i+1][j+1] && s[i][j]==s[i+2][j+2]
			&& s[i][j]==s[i+3][j+3] && s[i][j]==s[i+4][j+4] && s[i][j]=='X') return 1;
			if (i<6 && j>=4 && s[i][j]==s[i+1][j-1] && s[i][j]==s[i+2][j-2]
			&& s[i][j]==s[i+3][j-3] && s[i][j]==s[i+4][j-4] && s[i][j]=='X') return 1;
		}
	}
	return 0;
}
int main()
{
	for (int i=0;i<10;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if (s[i][j]!='.') continue;
			s[i][j]='X';
			if (check()) 
			{
				cout<<"YES"<<endl;
				return 0;
			}
			s[i][j]='.';
		}
	}
	cout<<"NO"<<endl;
	return 0; 
}
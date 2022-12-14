#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
map<string,string> mp;
string str;
string grid;
char s[2]={'0','X'};
bool check(int x)
{
	int i=x/3,j=x%3;
	if (grid[i*3]==grid[i*3+1] && grid[i*3]==grid[i*3+2] && grid[i*3]!='.') return 1;
	if (grid[j]==grid[j+3] && grid[j]==grid[j+6] && grid[j]!='.') return 1;
	if (grid[4]=='.') return 0;
	if (grid[0]==grid[4] && grid[4]==grid[8]) return 1;
	if (grid[2]==grid[4] && grid[4]==grid[6]) return 1;
	return 0;
}
void Search(int x)
{
	if (x==10) 
	{
		mp[grid]="draw";
		return;
	}
	if (x==1) mp[grid]="first";
	for (int i=0;i<9;i++) 
	{
		if (grid[i]=='.')
		{
			grid[i]=s[x%2];
			if (check(i)) 
			{
				if (x&1) mp[grid]="the first player won";
				else mp[grid]="the second player won";
				grid[i]='.';
				continue;
			} 
			if (x&1) mp[grid]="second";
			else mp[grid]="first";
			Search(x+1);
			grid[i]='.';
		}
	}
}
int main()
{
	for (int i=0;i<9;i++) grid.push_back('.');
	grid[9]=0;
	Search(1);
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			char c=getchar();
			str.push_back(c); 
		}
		getchar();
	}
	if (mp.find(str)==mp.end()) cout<<"illegal"<<endl;
	else cout<<mp[str]<<endl;
	return 0;
}
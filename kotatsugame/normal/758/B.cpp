#include<iostream>
using namespace std;
int ci(char a)
{
	if(a=='R')return 0;
	else if(a=='B')return 1;
	else if(a=='Y')return 2;
	else if(a=='G')return 3;
	else return 4;
}
char cc(int a)
{
	if(a==0)return 'R';
	else if(a==1)return 'B';
	else if(a==2)return 'Y';
	else if(a==3)return 'G';
	else return '!';
}
string s;
int n,c[4];
bool dfs(int u)
{
	if(u==n)
	{
		cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
		return true;
	}
	if(s[u]!='!')return dfs(u+1);
	bool flag[4]={};
	for(int i=u-3;i<=u+3;i++)
	{
		if(i<0||s[i]=='!')continue;
		flag[ci(s[i])]=true;
	}
	for(int i=0;i<4;i++)
	{
		if(flag[i])continue;
		s[u]=cc(i);
		c[i]++;
		if(dfs(u+1))return true;
		c[i]--;
		s[u]='!';
	}
	return false;
}
main()
{
	cin>>s;
	n=s.size();
	dfs(0);
}
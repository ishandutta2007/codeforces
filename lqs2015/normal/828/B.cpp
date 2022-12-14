#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[111][111];
int n,m,mxr,mxc,cnt,edge,num,st,en;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='B') num++;
		}
	}
	st=1e9;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (s[i][j]=='B')
			{
				st=min(st,j);
				en=max(en,j);
			}
		}
	}
	mxr=en-st+1;
	st=1e9;en=0;
	for (int j=0;j<m;j++)
	{
		for (int i=0;i<n;i++)
		{
			if (s[i][j]=='B')
			{
				st=min(st,i);
				en=max(en,i);
			}
		}
	}
	mxc=en-st+1;
	if (st==1e9) 
	{
		cout<<1<<endl;
		return 0;
	}
	edge=max(mxc,mxr);
	if (edge==0) edge=1;
	if (edge>n || edge>m) printf("-1\n");
	else printf("%d\n",edge*edge-num);
	return 0;
}
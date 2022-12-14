#include<iostream>
#include<cstdio>
using namespace std;
int n,m,i,j;
char a[1111][1111];
int pp,p;
bool f,flag;
int r[1111111],s[1111111],t;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if (a[i][j]=='*')
			{
				r[++t]=i;
				s[t]=j;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		f=flag=0;
		for (j=1;j<=t;j++)
		{
			if (flag) continue;
			if (r[j]!=i)
			{
				if (f && pp!=s[j]) flag=1;
				pp=s[j];
				f=1;
			}
		}
		if (flag) continue;
		for (j=1;j<=m;j++)
		{
			p=0;
			for (int k=1;k<=n;k++)
			{
				if (a[k][j]=='*') p++;
			}
			for (int k=1;k<=m;k++)
			{
				if (a[i][k]=='*') p++;
			}
			if (a[i][j]=='*') p-=1;
			if (p==t) 
			{
				cout<<"YES"<<endl<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
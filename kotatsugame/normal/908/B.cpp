#include<iostream>
using namespace std;
int n,m;
string s;
string ma[99];
int sx,sy;
bool f(int a,int b,int c,int d)
{
	int dx[4],dy[4];
	dx[a]=-1,dy[a]=0;
	dx[b]=1,dy[b]=0;
	dx[c]=0,dy[c]=-1;
	dx[d]=0,dy[d]=1;
	int nx=sx,ny=sy;
	for(int i=0;i<s.size();i++)
	{
		int now=s[i]-'0';
		nx+=dx[now],ny+=dy[now];
		if(ma[nx][ny]=='#')return false;
		else if(ma[nx][ny]=='E')return true;
	}
	return false;
}
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ma[i];
		ma[i]="#"+ma[i]+"#";
	}
	for(int i=0;i<=m+1;i++)ma[0]+="#",ma[n+1]+="#";
	n+=2,m+=2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]=='S')
			{
				sx=i,sy=j;
			}
		}
	}
	cin>>s;int cnt=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<4;l++)
				{
					if(i==j||i==k||i==l||j==k||j==l||k==l)continue;
					if(f(i,j,k,l))cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
}
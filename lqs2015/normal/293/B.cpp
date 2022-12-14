#include<iostream>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
long long n,m,k,filled[15][15];
long long a[15][15],b[15][15];
long long p[15];
bool appe[15];
long long Count()
{
	memset(p,-1,sizeof(p));
	memset(appe,0,sizeof(appe));
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (filled[i][j]!=-1)
			{
				int x=filled[i][j];
				int y=a[i][j];
				if (p[y]!=-1 && p[y]!=x) return 0;
				p[y]=x;
			}
		}
	}
	for (int i=0;i<k;i++)
	{
		for (int j=0;j<i;j++)
		if (p[i]==p[j] && p[i]!=-1) return 0;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		appe[a[i][j]]=1;
	}
	long long n=k,t=0;
	for (int i=0;i<k;i++)
	{
		if (p[i]!=-1) n--;
		if (p[i]==-1 && appe[i]) t++;
	}
	long long ans=1;
	for (int i=0;i<t;i++)
	{
		ans=ans*(n-i)%mod;
	}
	return ans;
}
bool check(int x,int y)
{
	b[x][y]=0;
	if (x>0) b[x][y]|=b[x-1][y];
	if (y>0) b[x][y]|=b[x][y-1];
	if (b[x][y]&(1<<a[x][y])) return 0;
	b[x][y]|=(1<<a[x][y]);
	return 1;
}
long long dfs(int x,int y,int used)
{
	if (x==n) return Count();
	long long xx=x,yy=y+1;
	if (yy==m) 
	{
		yy=0;
		xx++;
	}
	long long ans=0;
	for (int i=0;i<=used;i++)
	{
		if (i<k)
		{
			a[x][y]=i;
			if (check(x,y))
			{
				ans+=dfs(xx,yy,max(used,i+1));
				if (ans>=mod) ans-=mod;
			}
			a[x][y]=-1;
		}
	}
	return ans;
}
int main()
{
	cin>>n>>m>>k;
	if (n+m>k+1)
	{
		cout<<0<<endl;
		return 0;
	}
	memset(a,-1,sizeof(a));
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>filled[i][j];
			filled[i][j]--;
		}
	}
	cout<<dfs(0,0,0)<<endl;
	return 0;
}
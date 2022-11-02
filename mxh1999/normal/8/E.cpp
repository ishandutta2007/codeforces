//mjy.. good luck ..
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(ll &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 51
ll n,m;
int a[maxn];
ll f[maxn][2][2];

ll check(int t)
{
	memset(f[0],0,sizeof(f[0]));
	f[0][0][0]=1;
	for (int i=1;i<=(n+1)/2;i++)
	{
		int x,y;
		memset(f[i],0,sizeof(f[i]));
		if (i<=t && n-i+1<=t)
		{
			x=a[i],y=a[n-i+1];
			if (x==0 && y==0)	f[i][0][1]+=f[i-1][0][0]+f[i-1][0][1],f[i][1][1]+=f[i-1][1][0]+f[i-1][1][1];
			if (x==1 && y==0)	f[i][1][0]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			if (x==0 && y==1)	f[i][1][0]+=f[i-1][0][0]+f[i-1][1][0],f[i][1][1]+=f[i-1][0][1]+f[i-1][1][1];
			if (x==1 && y==1)	f[i][0][1]+=f[i-1][0][1],f[i][1][1]+=f[i-1][1][1];
		}	else
		if (i<=t)
		{
			x=a[i];
			for (y=0;y<2;y++)
			{
			if (x==0 && y==0)	f[i][0][1]+=f[i-1][0][0]+f[i-1][0][1],f[i][1][1]+=f[i-1][1][0]+f[i-1][1][1];
			if (x==1 && y==0)	f[i][1][0]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			if (x==0 && y==1)	f[i][1][0]+=f[i-1][0][0]+f[i-1][1][0],f[i][1][1]+=f[i-1][0][1]+f[i-1][1][1];
			if (x==1 && y==1)	f[i][0][1]+=f[i-1][0][1],f[i][1][1]+=f[i-1][1][1];
			}
		}	else
		if (n-i+1<=t)
		{
			y=a[n-i+1];
			for (x=0;x<2;x++)
			{
			if (x==0 && y==0)	f[i][0][1]+=f[i-1][0][0]+f[i-1][0][1],f[i][1][1]+=f[i-1][1][0]+f[i-1][1][1];
			if (x==1 && y==0)	f[i][1][0]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			if (x==0 && y==1)	f[i][1][0]+=f[i-1][0][0]+f[i-1][1][0],f[i][1][1]+=f[i-1][0][1]+f[i-1][1][1];
			if (x==1 && y==1)	f[i][0][1]+=f[i-1][0][1],f[i][1][1]+=f[i-1][1][1];
			}
		}	else
		if (n&1 && i==(n+1)/2)
		{
			for (x=0;x<2;x++)
			{
			y=x;
			if (x==0 && y==0)	f[i][0][1]+=f[i-1][0][0]+f[i-1][0][1],f[i][1][1]+=f[i-1][1][0]+f[i-1][1][1];
			if (x==1 && y==0)	f[i][1][0]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			if (x==0 && y==1)	f[i][1][0]+=f[i-1][0][0]+f[i-1][1][0],f[i][1][1]+=f[i-1][0][1]+f[i-1][1][1];
			if (x==1 && y==1)	f[i][0][1]+=f[i-1][0][1],f[i][1][1]+=f[i-1][1][1];
			}
		}	else
		{
			for (x=0;x<2;x++)
			for (y=0;y<2;y++)
			{
			if (x==0 && y==0)	f[i][0][1]+=f[i-1][0][0]+f[i-1][0][1],f[i][1][1]+=f[i-1][1][0]+f[i-1][1][1];
			if (x==1 && y==0)	f[i][1][0]+=f[i-1][1][0],f[i][1][1]+=f[i-1][1][1];
			if (x==0 && y==1)	f[i][1][0]+=f[i-1][0][0]+f[i-1][1][0],f[i][1][1]+=f[i-1][0][1]+f[i-1][1][1];
			if (x==1 && y==1)	f[i][0][1]+=f[i-1][0][1],f[i][1][1]+=f[i-1][1][1];
			}
		}
	}
	return f[(n+1)/2][0][0]+f[(n+1)/2][0][1]+f[(n+1)/2][1][0]+f[(n+1)/2][1][1];
}
int main()
{
	read(n),read(m);
	m++;
	ll q=check(1);
	if (q<m)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=2;i<=n;i++)
	{
		a[i]=0;
		ll q=check(i);
		if (q<m)	m-=q,a[i]=1;
	}
	for (int i=1;i<=n;i++)	printf("%d",a[i]);
	printf("\n");
	return 0;
}
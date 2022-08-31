#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<17;

int n,m;
int a[MaxN],b[MaxN];
int v[MaxN<<1],u[MaxN<<1];

void add(int k,int L,int R,int x,int y,int p)
{
	if (L==x&&R==y)
	{
		v[k]=p;
		u[k]=1;
		return;
	}
	if (u[k])
	{
		v[k<<1]=v[k<<1|1]=v[k];
		u[k<<1]=u[k<<1|1]=1;
		u[k]=0;
	}
	int m=(L+R)>>1;
	if (y<=m)
		add(k<<1,L,m,x,y,p);
	else if (x>m)
		add(k<<1|1,m+1,R,x,y,p);
	else
	{
		add(k<<1,L,m,x,m,p);
		add(k<<1|1,m+1,R,m+1,y,p);
	}
}

int get(int k,int L,int R,int x)
{
	if (u[k]) return v[k];
	if (L==R) return -1000000000;
	int m=(L+R)>>1;
	if (x<=m)
		return get(k<<1,L,m,x);
	else
		return get(k<<1|1,m+1,R,x);
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for (int i=1;i<(MaxN<<1);++i)
		v[i]=-1000000000;
	while (m--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			add(1,1,MaxN,y,y+k-1,x-y);
		}
		else
		{
			int x;
			scanf("%d",&x);
			int p=get(1,1,MaxN,x);
			if (p==-1000000000)
				printf("%d\n",b[x]);
			else
				printf("%d\n",a[x+p]);
		}
	}
	return 0;
}
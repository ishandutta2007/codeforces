#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=210;
const int MaxM=MaxN*MaxN;
const int INF=1000000000;

int n,m;
int x[MaxM],y[MaxM],w[MaxM];
int d[MaxN][MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (i!=j) d[i][j]=INF;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		w[i]*=2;
		d[x[i]][y[i]]=d[y[i]][x[i]]=min(d[x[i]][y[i]],w[i]);
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

pii p[MaxN];

void work()
{
	int ans=INF;
	for (int k=1;k<=m;++k)
	{
		for (int i=1;i<=n;++i)
			p[i]=pii(d[i][x[k]],d[i][y[k]]);
		sort(p+1,p+n+1);
		ans=min(ans,p[n].X);
		int j=n;
		for (int i=n-1;i>=1;--i)
		{
			if (p[i].Y<=p[j].Y) continue;
			ans=min(ans,(w[k]+p[i].X+p[j].Y)/2);
			j=i;
		}
		ans=min(ans,p[j].Y);
	}
	cout<<ans*0.5<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
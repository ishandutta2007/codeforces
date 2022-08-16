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

const int MaxN=510;
const int INF=1000000000;

int n;
int a[MaxN][MaxN],d[MaxN][MaxN];
int u[MaxN],x[MaxN];
ll ans[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			d[i][j]=a[x[n-i+1]][x[n-j+1]];
	/*
	for (int kk=n;kk>=1;--kk)
	{
		int k=x[kk];
		u[k]=1;
		for (int i=1;i<=n;++i) if (u[i])
		{
			d[i][k]=a[i][k];
			d[k][i]=a[k][i];
		}
		for (int i=1;i<=n;++i) if (u[i])
			for (int j=1;j<=n;++j) if (u[j])
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				ans[kk]+=d[i][j];
			}
	}
	*/
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				if (i<=k&&j<=k) ans[n-k+1]+=d[i][j];
			}
	for (int i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
	return 0;
}
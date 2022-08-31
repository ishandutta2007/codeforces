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
const int MaxM=10010;

int n,m;
int x[MaxM],y[MaxM];
int F[MaxN];
int L[MaxM][MaxN],R[MaxM][MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;++i)
		L[0][i]=R[m+1][i]=i;
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=n;++j)
			F[j]=L[i-1][j];
		F[father(x[i])]=father(y[i]);
		for (int j=1;j<=n;++j)
			L[i][j]=F[j];
	}
	for (int i=m;i>=1;--i)
	{
		for (int j=1;j<=n;++j)
			F[j]=R[i+1][j];
		F[father(x[i])]=father(y[i]);
		for (int j=1;j<=n;++j)
			R[i][j]=F[j];
	}
	int T;
	cin>>T;
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for (int i=1;i<=n;++i)
			F[i]=L[x-1][i];
		vector<pii> v;
		for (int i=1;i<=n;++i)
			v.push_back(pii(i,father(i)));
		for (int i=1;i<=n;++i)
			F[i]=R[y+1][i];
		for (int i=0;i<n;++i)
			F[father(v[i].X)]=father(v[i].Y);
		int ans=0;
		for (int i=1;i<=n;++i)
			if (father(i)==i) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
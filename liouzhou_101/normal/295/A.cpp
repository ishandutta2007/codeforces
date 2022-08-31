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

const int MaxN=100010;

int n,m,k;
int a[MaxN],l[MaxN],r[MaxN],d[MaxN];
ll v[MaxN],w[MaxN];

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
		scanf("%d%d%d",&l[i],&r[i],&d[i]);
	for (int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x]+=1;
		v[y+1]-=1;
	}
	for (int i=1;i<=m;++i)
	{
		v[i]+=v[i-1];
		w[l[i]]+=(ll)v[i]*d[i];
		w[r[i]+1]-=(ll)v[i]*d[i];
	}
	for (int i=1;i<=n;++i)
	{
		w[i]+=w[i-1];
		printf("%I64d ",w[i]+a[i]);
	}
	return 0;
}
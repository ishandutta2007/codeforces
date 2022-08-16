#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=(1<<20)+10;

int n;
int a[MaxN],b[MaxN];
ll v[MaxN<<1],w[MaxN<<1];

void build(int k,int L,int R)
{
	if (L==R)
	{
		b[L]=a[L];
		return;
	}
	int m=(L+R)>>1;
	build(k+1,L,m);
	build(k+1,m+1,R);
	for (int x=L,y=m+1,i=L;x<=m;++x)
	{
		while (y<=R&&a[y]<=a[x])
		{
			b[i++]=a[y];
			++y;
		}
		b[i++]=a[x];
		v[k]+=R-y+1;
	}
	for (int x=L,y=m+1;x<=m;++x)
	{
		while (y<=R&&a[y]<a[x])
			++y;
		w[k]+=y-m-1;
	}
	for (int i=L;i<=R;++i)
		a[i]=b[i];
}

int main()
{
	cin>>n;
	for (int i=1;i<=1<<n;++i)
		scanf("%d",&a[i]);
	build(0,1,1<<n);
	int m;
	cin>>m;
	while (m--)
	{
		int x;
		scanf("%d",&x);
		x=n-x;
		for (int i=x;i<=n;++i)
			swap(v[i],w[i]);
		ll ans=0;
		for (int i=0;i<=n;++i)
			ans+=w[i];
		printf("%I64d\n",ans);
	}
	return 0;
}
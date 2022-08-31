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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1010;
const ll INF=1000000000000000000LL;

ll n,m,k,p;
int a[MaxN][MaxN];
ll sx[MaxN],sy[MaxN];
ll ansx[MaxN*MaxN],ansy[MaxN*MaxN];

int main()
{
	cin>>n>>m>>k>>p;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			sx[i]+=a[i][j];
			sy[j]+=a[i][j];
		}
	sort(sx+1,sx+n+1); reverse(sx+1,sx+n+1);
	sort(sy+1,sy+m+1); reverse(sy+1,sy+m+1);
	ll ans=-INF;
	{
		priority_queue<ll> H;
		for (int i=1;i<=n;++i) H.push(sx[i]);
		for (int x=1;x<=k;++x)
		{
			auto t=H.top();
			H.pop();
			ansx[x]=ansx[x-1]+t;
			H.push(t-p*m);
		}
	}
	{
		priority_queue<ll> H;
		for (int i=1;i<=m;++i) H.push(sy[i]);
		for (int y=1;y<=k;++y)
		{
			auto t=H.top();
			H.pop();
			ansy[y]=ansy[y-1]+t;
			H.push(t-p*n);
		}
	}
	for (int x=0;x<=k;++x)
	{
		int y=k-x;
		ll tmp=ansx[x]+ansy[y];
		{
			ll a=x,b=y;
			if (a>b) swap(a,b);
			tmp=tmp-(1+a)*a/2*p;
			tmp=tmp-(a-1)*a/2*p;
			b=b-a;
			if (b>0) tmp=tmp-a*b*p;
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}
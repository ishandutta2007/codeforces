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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<17;

int n,k;
int s[MaxN];
vector<pii> v[MaxN];
int a[MaxN<<1],r[MaxN<<1];

void rev(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
	{
		a[k]=R-L+1-a[k];
		r[k]^=1;
		return;
	}
	int m=(L+R)>>1,Lc=k<<1,Rc=k<<1|1;
	if (r[k])
	{
		r[Lc]^=1;
		a[Lc]=m-L+1-a[Lc];
		r[Rc]^=1;
		a[Rc]=R-m-a[Rc];
		r[k]=0;
	}
	if (y<=m)
		rev(Lc,L,m,x,y);
	else if (x>m)
		rev(Rc,m+1,R,x,y);
	else
	{
		rev(Lc,L,m,x,m);
		rev(Rc,m+1,R,m+1,y);
	}
	a[k]=a[Lc]+a[Rc];
}

int get(int k,int L,int R,int x)
{
	if (L==R)
		return a[k];
	int m=(L+R)>>1,Lc=k<<1,Rc=k<<1|1;
	if (r[k])
	{
		r[Lc]^=1;
		a[Lc]=m-L+1-a[Lc];
		r[Rc]^=1;
		a[Rc]=R-m-a[Rc];
		r[k]=0;
	}
	if (x<=m)
		return get(Lc,L,m,x);
	else
		return get(Rc,m+1,R,x);
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for (int i=1;i<=k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=lower_bound(s+1,s+n+1,x)-s;
		y=upper_bound(s+1,s+n+1,y)-s-1;
		if (x>y) continue;
		v[x].push_back(pii(x,y));
		v[y+1].push_back(pii(x,y));
	}
	ll ans=(ll)n*(n-1)*(n-2)/6;
	for (int i=1;i<=n;++i)
	{
		if (i>1) rev(1,1,MaxN,i-1,i-1);
		for (vector<pii>::iterator it=v[i].begin();it!=v[i].end();++it)
			rev(1,1,MaxN,it->X,it->Y);
		ll t=a[1];
		if (get(1,1,MaxN,i)) --t;
		ans-=t*(t-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
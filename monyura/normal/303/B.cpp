#pragma comment(linker,"/STACK:65000000")
#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const double PI = acos(-1.0);

ll gcd(ll a,ll b)
{
	while (b)
	{
		ll c = b;
		b=a%b;
		a=c;
	}
	return a;
}

struct rect
{
	ll x1,y1;
	ll x2,y2;
	rect(){}
	rect(ll x10,ll y10, ll x20, ll y20)
	{
		x1=x10;
		y1=y10;
		x2=x20;
		y2=y20;
	}
	bool operator<(const rect &a) const
	{
		if (x1!=a.x1)
			return x1<a.x1;
		if (y1!=a.y1)
			return y1<a.y1;
		if (x2!=a.x2)
			return x2<a.x2;
		if (y2!=a.y2)
			return y2<a.y2;
	}
};

class cmp
{
public:
	ll x,y;
	bool operator()(const rect &a,const rect &b)
	{
		ull dista = SQR(ull(2*x-(a.x1+a.x2)))+SQR(ull(2*y-(a.y1+a.y2)));
		ull distb = SQR(ull(2*x-(b.x1+b.x2)))+SQR(ull(2*y-(b.y1+b.y2)));
		if (dista!=distb)
			return dista<distb;
		return a<b;
	}
};

rect normRect(ll a,ll b,ll n,ll m,ll x,ll y)
{
	rect res;
	res.x1 = x - a/2;
	res.y1 = y - b/2;
	res.x2 = res.x1 + a;
	res.y2 = res.y1 + b;
	if (res.x1<0)
	{
		ll add  = -res.x1;
		res.x1+=add;
		res.x2+=add;
	}
	if (res.x2>n)
	{
		ll sub = res.x2-n;
		res.x1-=sub;
		res.x2-=sub;
	}
	if (res.y1<0)
	{
		ll add = -res.y1;
		res.y1+=add;
		res.y2+=add;
	}
	if (res.y2>m)
	{
		ll sub = res.y2-m;
		res.y1-=sub;
		res.y2-=sub;
	}
	if (res.x1<0 || res.x2>n || res.y1<0 || res.y2>m)
		return rect(2e9,2e9,2e9,2e9);
	return res;
}


void run()
{
	ll n,m,x,y,a,b;
	/*x=1e9;
	y=1e9;
	ull dista = SQR(ull(2*x-ll(2e9)))+SQR(ull(2*y-ll(2e9)));
	cout<<dista<<endl;*/
	cin>>n>>m>>x>>y>>a>>b;
	ll g = gcd(a,b);
	a/=g;
	b/=g;
	ll res = 1;
	ll l=1,r=1e9;
	while (l<=r)
	{
		ll c = (l+r)>>1;
		if (a*c<=n && b*c<=m)
		{
			res=c;
			l=c+1;
		}
		else
			r=c-1;
	}
	a*=res;
	b*=res;
	vector<rect> vec;
	for (int dx=-2;dx<=2;dx++)
		for (int dy=-2;dy<=2;dy++)
			vec.push_back(normRect(a,b,n,m,x+dx,y+dy));
	cmp Comp;
	Comp.x = x;
	Comp.y = y;
	sort(all(vec),Comp);
	rect ans = vec[0];
	cout<<ans.x1<<' '<<ans.y1<<' '<<ans.x2<<' '<<ans.y2<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/
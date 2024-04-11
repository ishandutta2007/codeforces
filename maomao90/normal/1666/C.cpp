#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define dbg(...) printf(__VA_ARGS__);
#define getchar_unlocked getchar
#else
#define dbg(...)
#endif
#define sf scanf
#define pf printf
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define mnto(x,y) x=min(x,(__typeof__(x))y)
#define mxto(x,y) x=max(x,(__typeof__(x))y)
#define INF 1023456789
#define LINF 1023456789123456789
#define all(x) x.begin(), x.end()
#define disc(x) sort(all(x));x.resize(unique(all(x))-x.begin());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vll;
mt19937 rng(time(0));

#define mod 1000000007

inline int add(int a,int b){
	int r=a+b;
	while(r>=mod)r-=mod;
	while(r<0)r+=mod;
	return r;
}

inline int mult(int a,int b){
	return (int)(((ll)(a*b))%mod);
}

vii v;

int main(){
	for(int i=0;i<3;++i){
		int x,y;sf("%d%d",&x,&y);
		v.pb({x,y});
	}
	pf("3\n");
	sort(all(v));
	if(v[1].se>=v[0].se){
		if(v[2].se>=v[1].se){
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[1].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[2].se);
			pf("%d %d %d %d\n",v[1].fi,v[2].se,v[2].fi,v[2].se);
		}
		else if(v[1].se>v[2].se&&v[2].se>=v[0].se){
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[1].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[1].se);
			pf("%d %d %d %d\n",v[1].fi,v[2].se,v[2].fi,v[2].se);
		}
		else{
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[2].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[1].se);
			pf("%d %d %d %d\n",v[2].fi,v[0].se,v[2].fi,v[2].se);
		}
	}
	else{
		if(v[2].se<=v[1].se){
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[1].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[2].se);
			pf("%d %d %d %d\n",v[1].fi,v[2].se,v[2].fi,v[2].se);
		}
		else if(v[1].se<v[2].se&&v[2].se<=v[0].se){
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[1].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[1].se);
			pf("%d %d %d %d\n",v[1].fi,v[2].se,v[2].fi,v[2].se);
		}
		else{
			pf("%d %d %d %d\n",v[0].fi,v[0].se,v[2].fi,v[0].se);
			pf("%d %d %d %d\n",v[1].fi,v[0].se,v[1].fi,v[1].se);
			pf("%d %d %d %d\n",v[2].fi,v[0].se,v[2].fi,v[2].se);
		}
	}
}
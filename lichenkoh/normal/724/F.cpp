#include <bits/stdc++.h>
//#include <iostream>
/*#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>*/
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }

template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll mod_pow2(ll a, ll n, ll mod) {
	if (n<0) return mod_inv(mod_pow(a,-n,mod),mod);
	else return mod_pow(a,n,mod);
}

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

const ll mn=1004;
ll MOD;
ll gd;
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
/*
const ll MAXFACT=5004;
ll fact[MAXFACT], invfact[MAXFACT];

void initfact(ll n) {
	fact[0] = 1;
	for (ll x = 1; x < n; x++) {
		fact[x] = (fact[x-1] * x) %MOD;
	}
	for (ll x = 0; x < n; x++) {
		invfact[x] = mod_inv(fact[x],MOD);
	}
}
ll binom(ll n,ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	
	ll ans = (invfact[k]*invfact[n-k])%MOD;
	
	return (fact[n]*ans)%MOD;
}*/
ll binom(ll n, ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	ll numer=1,denom=1;
	for (ll x=0;x<k;x++) {
		numer=mul(numer,n-x);
		denom=mul(denom,k-x);
	}
	return mul(numer, mod_inv(denom,MOD));
}

ll starbar(ll stars, ll parts) {
	if (parts==0) {
		return (stars==0)?1:0;
	}
	return binom(stars+parts-1,stars);
}
const ll md=11,ms=mn;
ll dpf[mn][md][ms];
ll dpg[mn][md][ms];
ll g(ll nodes, ll rootdeg, ll s);
ll f(ll nodes, ll rootdeg, ll s) {
	if (nodes<=0||rootdeg<0||s<0) return 0;
	if (dpf[nodes][rootdeg][s]!=UNDEF) return dpf[nodes][rootdeg][s];
	ll ans=0;
	for (ll k=1;k<=rootdeg;k++) {
		ll cand=g(nodes-k*s,rootdeg-k,s-1);
		if (cand>0) {
			ll parts=(s==1)?1:g(s,gd-1,s);
			ll stars=k;
			ll factor=starbar(stars,parts);
			ll adder=mul(cand,factor);
			//printf("f %lld %lld %lld. k:%lld adder:%lld cand:%lld factor:%lld. stars:%lld parts:%lld\n",nodes,rootdeg,s,k,adder,cand,factor,stars,parts);
			ans=add(adder,ans);
		}
	}
	//printf("f %lld %lld %lld: %lld\n",nodes,rootdeg,s,ans);
	return dpf[nodes][rootdeg][s]=ans;
}
ll g(ll nodes, ll rootdeg, ll s) {
	if (nodes<=0||rootdeg<0||s<0) return 0;
	if (dpg[nodes][rootdeg][s]!=UNDEF) return dpg[nodes][rootdeg][s];
	ll ans=add(g(nodes,rootdeg,s-1),f(nodes,rootdeg,s));
	//printf("g %lld %lld %lld: %lld\n",nodes,rootdeg,s,ans);
	return dpg[nodes][rootdeg][s]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld%lld%lld",&n,&gd,&MOD);
	if (n==2||n==1 ) {
		printf("1\n");
		return 0;
	}
	//initfact(MAXFACT);
	memset(dpf,-1,sizeof dpf);
	memset(dpg,-1,sizeof dpg);
	for (ll d=0;d<md;d++) for (ll s=0;s<mn;s++) dpf[1][d][s]=0;
	dpf[1][0][0]=1;
	ll ans=g(n,gd,n/2);
	if (n%2==0 ) {
		ll a=g(n/2,gd-1,-1+n/2);
		//printf("a:%lld\n",a);
		ll sub=binom(a,2);
		ans=add(ans,MOD-sub);
	}
	printf("%lld\n",ans);
}
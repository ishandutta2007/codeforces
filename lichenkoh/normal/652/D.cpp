#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=400004;
ll fenwick[MAXN];
// T[i] += value
void add(ll *t, ll i, ll value) {
  for (; i < MAXN; i |= i + 1)
    t[i] += value;
}

// sum[0..i]
ll sum(ll *t, ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

void sset(ll *t, ll i, ll value) {
  ll orig = sum(t,i)-sum(t,i-1);
  add(t,i,value-orig);
}
void resetfenwick(ll n) {
	for (ll i=0;i<n;i++) fenwick[i]=0;
}

pair<ll,pair<ll,ll> > v[MAXN];
ll ans[MAXN];
vector<ll> b;
ll bsz;
ll binsearch(ll x) {
	ll imin=0; ll imax=bsz;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (b[imid]<x) imin=imid+1;
		else imax=imid;
	}
	return imin;
}
int main() {
	int _n; scanf("%d",&_n);
	ll n=_n;
	set<ll> s;
	for (ll i=0;i<n;i++) {
		int x,y; scanf("%d %d",&x,&y);
		v[i]=(MP((ll)y,MP((ll)x,(ll)i)));
		s.insert(x); s.insert(y);
	}
	for (auto &w: s) {
		b.PB(w);
	}
	bsz=b.size();
	for (ll i=0;i<n;i++) {
		v[i].second.first = binsearch(v[i].second.first);
		v[i].first = binsearch(v[i].first);
	}
	sort(v,v+n);
	resetfenwick(MAXN);
	for (ll i=0;i<n;i++) {
		ll l=v[i].second.first,r=v[i].first,idx=v[i].second.second;
		ll x=MAXN-1-l;
		ans[idx]=sum(fenwick,x);
		add(fenwick,x,1);
	}
	for (ll i=0;i<n;i++) {
		printf("%d\n",(int)ans[i]);
	}
}
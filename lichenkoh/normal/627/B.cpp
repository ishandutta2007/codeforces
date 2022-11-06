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
#define MAXN 210004
ll t1[MAXN],t2[MAXN];
ll v[MAXN];
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


int main() {
	ios_base::sync_with_stdio(false);
	ll n, k, a, b, q;
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&k,&a,&b,&q);
	for (ll i=0;i<MAXN;i++) {
		t1[i]=0;
		t2[i]=0;
		v[i]=0;
	}
	for (ll zz=0;zz<q;zz++) {
		ll tp; scanf("%I64d",&tp);
		if (tp==1) {
			ll di,ai; scanf("%I64d %I64d",&di,&ai);
			v[di]+=ai;
			sset(t1,di,min(v[di],b));
			sset(t2,di,min(v[di],a));
			//printf("Set: %I64d: %I64d %I64d\n",di,min(v[di],b),min(v[di],a));
		}
		else {
			ll qi;scanf("%I64d",&qi);
			ll ans1 = sum(t2,n)-sum(t2,min(qi+k-1,n));
			//printf("Q:%I64d-%I64d:%I64d. %I64d %I64d\n",min(qi+k-1,n),n,ans1,sum(t2,min(qi+k-1,n)),sum(t2,n));
			ll ans2 = sum(t1,qi-1);
			//printf("Q:%I64d:%I64d\n",qi-1,ans2);
			ll final=ans1+ans2;
			printf("%I64d\n",final);
		}
	}
}
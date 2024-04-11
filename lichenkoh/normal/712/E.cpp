#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1e5+4;
ll n;
typedef pair<ld,ld> S;
S t[2 * mn];
S combine(S a, S b) {
	ld alr=a.first,arl=a.second;
	ld all=1-alr,arr=1-arl;
	ld blr=b.first,brl=b.second;
	ld bll=1-blr,brr=1-brl;
	ld slr=alr*blr/(1-bll*arr);
	//printf("%f %f %f %f\n",brl,arl,alr,bll);
	ld srl=brl*arl/(1-arr*bll);
	//printf("Combine %f %f. %f %f. %f %f.\n",alr,arl,blr,brl,slr,srl);
	return MP(slr,srl);
}
void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
void modify(ll p, const S& value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(ll l, ll r) {
	//printf("QUERY\n");
  S resl=MP(1.0l,1.0l), resr=MP(1.0l,1.0l);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll q; scanf("%lld %lld",&n,&q);
	for (ll i=0;i<n;i++) {
		ll a,b;
		scanf("%lld %lld",&a,&b);
		ld val=(ld)a/(ld)b;
		t[n+i]=MP(val,1-val);
		//printf("%.5f %.5f\n",(double)t[n+i].first , combine(MP(1.0l,1.0l),t[n+i]).first);
		//printf("%.5f %.5f\n",(double)t[n+i].second, combine(MP(1.0l,1.0l),t[n+i]).second);
		//printf("%.5f %.5f\n",(double)t[n+i].first , combine(t[n+i],MP(1.0l,1.0l)).first);
		//printf("%.5f %.5f\n",(double)t[n+i].second, combine(t[n+i],MP(1.0l,1.0l)).second);
	}
	build();
	for (ll ii=0;ii<q;ii++) {
		ll tp; scanf("%lld",&tp);
		if (tp==1) {
			ll i,a,b; scanf("%lld %lld %lld",&i,&a,&b);
			i--;
			ld val=(ld)a/(ld)b;
			modify(i,MP(val,1-val));
		}
		else {
			ll l,r; scanf("%lld %lld",&l,&r);
			l--;r--;
			ld ans=query(l,r+1).first;
			printf("%.5f\n",(double)ans);
		}
	}
}
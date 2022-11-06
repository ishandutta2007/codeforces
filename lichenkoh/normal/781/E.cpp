#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define fst first
#define snd second
const ll mn=1e5+4;
vector<pair<pll,pll> > barrier;
int vu[mn],vl[mn],vr[mn],vs[mn];
ll fallto[mn][2];

map<int,int> t[2*mn];
int segn;
long long hit[mn];
void ins(map<int,int> &s, int newidx) {
	ll me=vu[newidx]+vs[newidx];
	s[me]=newidx;
	for (auto it=s.begin();;) {
		ll idx=it->second;
		if (idx==newidx) break;
		it=s.erase(it);
	}
}
int get(map<int,int> &s, int h) {
	auto it=s.lower_bound(h);
	if (it!=s.end()) {
		return it->second;
	}
	return -1;
}
void modify(int l, int r, int value) {
	int n=segn;
	++r;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) ins(t[l++], value);
    if (r&1) ins(t[--r], value);
  }
}

int query(int p, int h) {
	int n=segn;
  int res = -1;
  for (p += n; p > 0; p >>= 1) chkmax(res, get(t[p], h));
  return res;
}

int main()
{
	segn=mn-1;
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll h,gw,n; scanf("%d%d%d",&h,&gw,&n);
	for (ll i=0;i<n;i++) {
		ll u,l,r,s;
		scanf("%d%d%d%d",&u,&l,&r,&s);
		barrier.PB(MP(MP(u,l),MP(r,s)));
	}
	sort(barrier.begin(),barrier.end());
	ll bsz=barrier.size();
	for (ll i=0;i<bsz;i++) {
		auto w=barrier[i];
		ll u=w.fst.fst,l=w.fst.snd,r=w.snd.fst,s=w.snd.snd;
		vu[i]=u;vl[i]=l;vr[i]=r;vs[i]=s;
	}
	for (ll i=0;i<bsz;i++) {
		auto w=barrier[i];
		ll u=w.fst.fst,l=w.fst.snd,r=w.snd.fst,s=w.snd.snd;
		for (ll k=0;k<2;k++) {
			ll x;
			if (k==0) x=l-1;
			else x=r+1;
			if (x<1) x=r+1;
			if (x>gw) x=l-1;
			fallto[i][k]=query(x,u);
		}
		modify(l,r,i);
	}
	long long ans=0;
	for (ll x=1;x<=gw;x++) {
		ll nextseg=query(x,h+1);
		if (nextseg==-1) {
			ans++;
		}
		else {
			hit[nextseg]++;
		}
	}
	for (ll i=bsz-1;i>=0;i--) {
		ll got=hit[i];
		for (ll k=0;k<2;k++) {
			ll nextseg=fallto[i][k];
			//printf("i:%lld->%lld\n",i,nextseg);
			if (nextseg==-1) {ans+=got; ans%=MOD;}
			else {hit[nextseg]+=got; hit[nextseg]%=MOD;}
		}
	}
	printf("%lld\n",ans);
}
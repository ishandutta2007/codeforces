#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
map<string,pair<vector<ll>,vector<ll> > > h;
map<string,vector<ll> > g;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll k,n;
	cin>>k>>n;
	for (ll i=0;i<k;i++) {
		string s; ll a; cin>>s>>a;
		string r=s; reverse(r.begin(),r.end());
		if (s<r) {h[s].first.PB(a);}
		else if (s>r) {h[r].second.PB(a);}
		else g[s].PB(a);
	}
	ll final=0;
	for (auto &ww:h) {
		auto &w=ww.second;
		sort(w.first.begin(),w.first.end(),greater<ll>());
		sort(w.second.begin(),w.second.end(),greater<ll>());
		ll sz=min(w.first.size(),w.second.size());
		for (ll i=0;i<sz;i++) {
			ll cand=w.first[i]+w.second[i];
			//cout<<ww.first<<cand<<endl;
			if (cand>0) final+=cand;
		}
	}
	ll woof=0;
	ll best=0;
	for (auto &w:g) {
		sort(w.second.begin(),w.second.end(),greater<ll>());
		ll sz=w.second.size();
		if (sz==0) continue;
		ll c0=0;
		for (ll i=0;i+1<sz;i+=2) {
			ll cand=w.second[i]+w.second[i+1];
			if (cand>0) c0+=cand;
		}
		woof+=c0;
		ll c1=max(0,w.second[0]);
		for (ll i=1;i+1<sz;i+=2) {
			ll cand=w.second[i]+w.second[i+1];
			if (cand>0) c1+=cand;
		}
		chkmax(best,c1-c0);
	}
	ll toadd=woof+best;
	final+=toadd;
	printf("%d\n",final);
}
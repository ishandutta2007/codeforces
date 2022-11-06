#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
vector<pair<ll,ll> > e;
int main() {
	ios_base::sync_with_stdio(false);
	ll n,d,h; scanf("%d %d %d",&n,&d,&h);
	bool ok=true;
	if (d>2*h) ok=false;
	if (d<h) ok=false;
	ll left=h;
	ll right=d-h;
	ll extra=n-(left+right+1);
	if (extra<0) ok=false;
	if (d==1&&n>2) ok=false;
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	ll v=1;
	for (ll i=1;i<=right;i++) {
		e.PB(MP(i,i+1));
		v=i+1;
	}
	v++;
	ll prev=1;
	for (ll i=0;i<left-1;i++) {
		e.PB(MP(prev,v));
		prev=v;
		v++;
	}
	for (ll i=0;i<extra+1;i++) {
		e.PB(MP(prev,v));
		v++;
	}
	for (auto &w:e) {
		printf("%d %d\n",w.first,w.second);
	}
}
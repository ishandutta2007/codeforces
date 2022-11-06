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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
bool seen[mn];
vector<pair<ll,vll> > cyc;
ll p[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll x=1;x<=n;x++) scanf("%d",&p[x]);
	for (ll x=1;x<=n;x++) {
		if (seen[x]) continue;
		ll y=x;
		seen[y]=true;
		y=p[x];
		vll v; v.PB(x);
		while(y!=x) {
			v.PB(y);
			seen[y]=true;
			y=p[y];
		}
		cyc.PB(MP((ll)v.size(),v));
	}
	sort(cyc.begin(),cyc.end());
	ll small=cyc[0].fst;
	if (small>=3) {
		printf("NO\n"); return 0;
	}
	for (auto &w:cyc) {
		if (w.fst%small != 0) {
			printf("NO\n"); return 0;
		}
	}
	ll csz=cyc.size();
	if (small==2) {
		printf("YES\n");
		ll t[2];
		t[0]=cyc[0].snd[0],t[1]=cyc[0].snd[1];
		printf("%d %d\n",t[0],t[1]);
		for (ll i=1;i<csz;i++) {
			for (ll k=0;k<cyc[i].fst;k++) {
				printf("%d %d\n",t[k%2],cyc[i].snd[k]);
			}
		}
	}
	else if (small==1) {
		printf("YES\n");
		ll x=cyc[0].snd[0];
		for (ll i=1;i<csz;i++) {
			for (ll k=0;k<cyc[i].fst;k++) {
				printf("%d %d\n",x,cyc[i].snd[k]);
			}
		}
	}
	else {
		printf("NO\n");
	}
}
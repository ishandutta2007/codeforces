#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
bool go() {
	int n; cin>>n; vi a(n),lh(n),rh(n);
	for (int i=0;i<n;i++) cin>>a[i];
	lh[0]=a[0];
	for (int x=1;x<n;x++) lh[x]=min(a[x],lh[x-1]);
	rh[n-1]=a[n-1];
	for (int x=n-2;x>=0;x--) rh[x]=min(a[x],rh[x+1]);
	for (int x=0;x<n;x++) {
		if (a[x]>lh[x]+rh[x]) return false;
	}
	int l=a[0],r=0;
	for (int x=0;x<n;x++) {
		int llo=a[x]-rh[x];
		int rlo=a[x]-lh[x];
		int need=a[x]-l-r;
		if (need>0) {
			r+=need;
		} else {
			l+=need;
		}
		//printf("l:%d r:%d\n",l,r);
		if (!(max(0,llo)<=l && l <= lh[x])) return false;
		if (!(max(0,rlo)<=r && r <= rh[x])) return false;
	}
	return true;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) {
  	bool ans=go();
  	printf(ans?"YES\n":"NO\n");
  }
}
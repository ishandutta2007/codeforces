#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

bool check(int xlim, int ylim, vector<string> a) {
  vector<ll> v; v.resize(xlim);
  for (int x=0;x<xlim;x++) {
    ll ans=0;
    for (int y=0;y<ylim;y++) {
      if (a[x][y]=='#') ans|=1LL<<y;
    }
    v[x]=ans;
  }
  for (int i=0;i<xlim;i++) {
    for (int j=0;j<i;j++) {
      if (v[i]&v[j]) {
        if (v[i]!=v[j]) return false;
      }
    }
  }
  return true;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int xlim,ylim; cin>>xlim>>ylim;
  vector<string> a; a.resize(xlim);
  for (int x=0;x<xlim;x++) cin>>a[x];
  vector<string> b; b.resize(ylim);
  for (int y=0;y<ylim;y++) {
    b[y].resize(xlim);
  }
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) b[y][x]=a[x][y];
  bool ans=check(xlim,ylim,a)&&check(ylim,xlim,b);
  if (ans) printf("Yes\n");
  else printf("No\n");
}
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
typedef vector<pii> vpii;
const int mn=1e5+4;
int a[mn];
vi b[mn];
int c[mn];
void fail() {
  printf("Impossible\n"); exit(0);
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=1;i<=n;i++) {
    // 0..n-1 to 1..n
    b[n-a[i]].PB(i);
  }
  int g=0;
  for (int k=1;k<=n;k++) {
    int s=b[k].size();
    if ((s%k)!=0) fail();
    for (int x=0;x<s;x+=k) {
      ++g;
      for (int y=x;y<x+k;y++) {
        c[b[k][y]]=g;
      }
    }
  }
  printf("Possible\n");
  for (int x=1;x<=n;x++) {
    printf("%d ",c[x]);
  }
}
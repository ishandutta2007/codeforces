#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
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
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
int rint() {int x;scanf("%d",&x);return x;}
ll rlong() {ll x;scanf("%lld",&x);return x;}
const int mn=(1e6)+2;

vi g[mn]; int k;
int ans=0;
int dfs(int x, int p) {
  if (g[x].size()==1) {
    return 0;
  }
  vector<int> v;
  for (auto &y:g[x]) {
    if (y!=p) {
      int got=dfs(y,x);
      //printf("x:%d y:%d got:%d\n",x,y,got);
      if (got>=0) {
        ++got;
        assert(got<=k);
        if (got==k) ans++;
        else v.PB(got);
      }
    }
  }
  sort(v.begin(),v.end());
  int n=v.size();
  if (n==0) return -INF;
  if (n==1) return v[0];
  for (int i=n-2;i>=0;i--) {
    if (v[i]+v[i+1]>k) {
      ans++; // i+1 is out.
    }
    else return v[i+1];
  }
  return v[0];
}
int main()
{
  int n=rint();k=rint();
  for (int i=1;i<n;i++) {int x=rint(),y=rint(); g[x].PB(y); g[y].PB(x);}
  int init=-1;
  for (int x=1;x<=n;x++) if (g[x].size()!=1) init=x;
  if (init==-1) {
    printf("1\n");
    exit(0);
  }
  int got=dfs(init,-1);
  if (got>=0) ans++;
  printf("%d\n",ans);
}
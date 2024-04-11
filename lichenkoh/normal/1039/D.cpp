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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
int rint() {int x;scanf("%d",&x);return x;}
ll rlong() {ll x;scanf("%lld",&x);return x;}
const int mn=100000+2;
vi g[mn]; vi h[mn]; int deg[mn], vid[mn];
vi vp;
int of[mn];
int f[mn];
int go(int k) {
  memset(f,0,sizeof f);
  int ans=0;
  for (auto &x:vp) {
    pii h1=MP(0,0);
    int h2=0;
    for (auto &y:h[x]) {if (f[y]>h1.fst) h1=MP(f[y],y);}
    for (auto &y:h[x]) {if (y!=h1.snd) chkmax(h2,f[y]);}
    //printf("x:%d h1:%d %d. h2:%d\n",x,h1.fst,h1.snd,h2);
    int loop=h1.fst+h2+1;
    if (loop>=k) {
      //printf("Hit %d\n",x);
      ++ans; f[x]=0;
    }
    else f[x]=h1.fst+1;
    //printf("f[%d] = %d\n",x,f[x]);
  }
  return ans;
}
int vans[mn];

void query(int l, int r, int lo, int hi) {
  if (l>r) return;
  else if (lo==hi) {
    for (int x=l;x<=r;x++) vans[x]=lo;
  }
  else if (l==r) {
    vans[l]=go(l);
  }
  else {
    int mid=(l+r+1)/2;
    vans[mid]=go(mid);
    query(l,mid-1,lo,vans[mid]);
    query(mid+1,r,vans[mid],hi);
  }
}

bitset<mn> seen;
int main()
{
  int n=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint(); g[x].PB(y); g[y].PB(x); ++deg[x]; ++deg[y];
  }
  queue<int> q;
  for (int x=1;x<=n;x++) if(deg[x]==1) {q.push(x);}
  int gid=0;
  while(!q.empty()) {
    int x=q.front(); q.pop();
    if (deg[x]!=1) continue;
    vp.PB(x); vid[x]=gid++; seen[x]=true;
    for (auto &y:g[x]) {
      if (--deg[y]==1) {q.push(y);}
    }
  }
  for (int x=1;x<=n;x++) if (!seen[x]) {
    vp.PB(x); vid[x]=gid++; break;
  }
  for (int x=1;x<=n;x++) {
    for (auto &y:g[x]) if (vid[y]<vid[x]) h[x].PB(y);
  }
  int s=ceil(sqrt(n)); while(s*s<=n) ++s;
  for (int k=1;k<=s;k++) {
    vans[k]=go(k);
  }
  query(s+1,n,vans[s],0);
  //query(1,n,n,1);
  for (int k=1;k<=n;k++) printf("%d\n",vans[k]);
}
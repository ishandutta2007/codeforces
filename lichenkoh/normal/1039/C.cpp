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
const int mn=(5e5)+4;
ll c[mn];
map<ll,vector<pii> > sig2e;
map<int,vi> h; set<int> seen;

int cnt=0;

void dfs(int x) {
  seen.insert(x);
  for (auto &y:h[x]) {
    if (seen.find(y)==seen.end()) {
      --cnt;
      dfs(y);
    }
  }
}

int ptwo[mn];

int main()
{
  int n=rint(),m=rint(),k=rint();
  ptwo[0]=1;
  for (int i=1;i<mn;i++) {
    ptwo[i]=ptwo[i-1]*2;
    if (ptwo[i]>=MOD) ptwo[i]-=MOD;
  }
  for (int x=1;x<=n;x++) c[x]=rlong();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(); ll sig=c[x]^c[y];
    sig2e[sig].PB(MP(x,y));
  }
  //printf("ptwo[k]:%d sig2e:%d\n",ptwo[k],(int)sig2e.size());
  int rem=(ptwo[k]-(int)sig2e.size()+MOD)%MOD;
  int ans=(rem*(ll)ptwo[n])%MOD;
  for (auto &sigve:sig2e) {
    auto &ve=sigve.snd;
    h.clear(); seen.clear();
    for (auto &e:ve) {
      int x=e.fst,y=e.snd; h[x].PB(y); h[y].PB(x);
    }
    cnt=n;
    for (auto &e:ve) {
      int x=e.fst,y=e.snd;
      if (seen.find(x)==seen.end()) dfs(x);
      if (seen.find(y)==seen.end()) dfs(y);
    }
    //printf("sig:%lld cnt:%d\n",sigve.fst,cnt);
    ans+=ptwo[cnt];
    if (ans>=MOD) ans-=MOD;
  }
  printf("%d\n",ans);
}
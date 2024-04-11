#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
 
using namespace std;
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
const int mn=1004;

int gr=0;
int gn;
vector<string> vs;
int getr() {
  gr++;
  return gr;
}
void go(vector<int> cyc) {
  int csz=cyc.size();
  if (csz<=1) return;
  for (int t=0;t<8;t++) for (int i=0;i<csz;i++) cyc.PB(cyc[i]);
  int s=-1;
  for (int i=0;i<csz;i++) {
    int c1=cyc[i],c2=cyc[i+1];
    if (c1<c2) {
      s=i;
      if (c2==gn) break;
    }
  }
  assert(s!=-1);
  s+=3*csz;
  if (cyc[s+1]==gn) {
    for (int i=s;i>=s-csz+2;i--) {
      int c1=cyc[i],c2=cyc[i+1];
      int r=getr();
      if (c1<c2) {
        vs[r][c1] = '/';
        vs[r][c2] = '/';
      }
      else if (c1>c2) {
        vs[r][c1] = '\\';
        vs[r][c2] = '\\';
      }
      else assert(0);
    }
    return;
  }
  {
    int r=getr();
    vs[r][cyc[s]]='/';
    vs[r][cyc[s+1]]='/';
    vs[r][gn]='/';
  }
  for (int i=s-1;i>=s-csz+2;i--) {
    int c1=cyc[i],c2=cyc[i+1];
    int r=getr();
    if (c1<c2) {
      vs[r][c1] = '/';
      vs[r][c2] = '/';
    }
    else if (c1>c2) {
      vs[r][c1] = '\\';
      vs[r][c2] = '\\';
    }
    else assert(0);
  }
  {
    int r=getr();
    vs[r][gn]='\\';
    vs[r][cyc[s+2]]='\\';
  }
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n; gn=n;
  vector<int> p(n+1);
  vs.resize(n+1);
  for (int r=1;r<=n;r++) {vs[r].resize(n+1,'.');}
  for (int x=1;x<=n;x++) cin>>p[x];
  bool ok=1; for (int x=1;x<=n;x++) if (p[x]!=x) ok=0;
  int ans=n;
  if (!ok) {
    ans=n-1;
    // Cycle involving n should go last.
    vector<vi> vcyc;
    for (int s=n;s>=1;s--) {
      vector<int> cyc; cyc.PB(s);
      int x=p[s]; if (x==-1) continue;
      while (x!=s) {
        cyc.PB(x);
        assert(x!=0);
        x=p[x];
      }
      for (auto &w:cyc) p[w]=-1;
      vcyc.PB(cyc);
    }
    reverse(vcyc.begin(),vcyc.end());
    for (auto &cyc:vcyc) go(cyc);
  }
  cout<<ans<<endl;
  for (int r=n;r>=1;r--) {
    cout<<vs[r].substr(1)<<endl;
  }
}
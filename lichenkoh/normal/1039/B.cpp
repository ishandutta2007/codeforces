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

mt19937 rng;
ll n,k;
bool active=false;
uniform_int_distribution<> dis01(0,1);

// Must be reset!!
ll C;
ll qrem;
ld res;

bool ask(ll l,ll r, ll len) {
  if (active) {
    cout<<l<<" "<<r<<endl; cout.flush();
    string s; cin>>s;
    assert(s[0]!='B');
    if (s[0]=='Y') {
      if (l==r) {
        exit(0);
      }
      return true;
    }
    return false;
  }
  else {
    //printf("C:%lld Hit %lld %lld\n",C,l,r);
    if (l==r) {
      res*=1-(1.0/len);
    }
    --qrem;
    return dis01(rng);
  }
}

void go(ll l, ll r) { // Train in (l,r) on this round, AFTER last query.
  if (qrem==0) return;
  chkmax(l,1LL);
  chkmin(r,n);
  assert(r>=1);
  assert(l<=n);
  //printf("go C:%lld Hit %lld %lld\n",C,l,r);
  if (r-l <= C) {
    uniform_int_distribution<> dis(0,r-l);
    ll x=l+dis(rng);
    ask(x,x,r-l+1);
    go(l-k,r+k);
  }
  else {
    ++r;
    ll mid=(l+r)/2;
    ll L[2],R[2];
    L[0]=l; R[0]=mid-1;
    L[1]=mid; R[1]=r-1;
    bool yes=ask(L[0],R[0],R[0]-L[0]+1);
    if (yes) {
      go(L[0]-k,R[0]+k);
    }
    else {
      go(L[1]-k,R[1]+k);
    }
  }
}

int main() 
{
  cin>>n>>k;
  rng.seed(chrono::steady_clock::now().time_since_epoch().count());
  pair<ld,ll> best=MP(1.0L, -(4*k+1));
  for (C=1;C<=1000;C++) {
    qrem=4500; res=1;
    go(1,n);
    chkmin(best, MP(res, -C));
  }
  C=-best.snd;
  //printf("Best C:%lld. Prob:%.50Lf\n",C,best.fst); exit(0);
  active=true; qrem=100000;
  go(1,n);
}
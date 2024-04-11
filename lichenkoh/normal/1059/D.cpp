#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
 
using namespace std;
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
typedef long long ll;
typedef long double ld;
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
const int mn=1e5+4;;
int vx[mn],vy[mn];
ll vy2[mn];
void fail() {
  printf("-1\n"); exit(0);
}
int n;
int f(ld x, ld r) {
  int sig=0;
  for (int i=0;i<n;i++) {
    if (vy[i]==0) continue;
    ld dx=x-vx[i];
    if (dx*dx+vy2[i]>2*r*vy[i]) {
      if (x<vx[i]) sig|=1;
      else sig|=2;
      if (sig==3) return sig;
    }
  }
  return sig;
}

int g(ld r) {
  ld xl=(-1e7)-1,xh=(1e7)+1;
  for (int tt=0;tt<47;tt++) {
    ld x=(xl+xh)/2;
    //printf("r: %.16Lf x: %.16Lf\n",r,x);
    int sig=f(x,r);
    if (sig==3) return sig;
    else if (sig==1) xl=x;
    else if (sig==2) xh=x;
    else {
      assert(sig==0); return 0;
    }
  }
  return f(xl,r);
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  int qq=0; int zeros=0; int zerox;
  for (int i=0;i<n;i++) {
    cin>>vx[i]>>vy[i];
    if (vy[i]==0) {zeros++; zerox=vx[i];}
    if (vy[i]>0) qq|=1;
    if (vy[i]<0) qq|=2;
    vy2[i]=vy[i]*(ll)vy[i];
  }
  if (qq==3 || zeros>=2) fail();
  for (int i=0;i<n;i++) vy[i]=abs(vy[i]);
  ld rl=0,rh=5e13+100;
  for (int zz=0;zz<67;zz++) {
    ld r=(rl+rh)/2;
    int sig;
    if (zeros) {
      sig=f(zerox,r);
    }
    else sig=g(r);
    //printf("r:%.16Lf sig:%d\n",r,sig);
    if (sig==0) rh=r;
    else rl=r;
  }
  printf("%.16Lf\n",rl);
}
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
const int MINL=1;
const int MAXL=(1000*1000*1000)-1;
int n;
int query(int x, int y) {
  --n;
  cout<<x<<" "<<y<<endl<<flush; cout.flush();
  string s; cin>>s;
  return s[0]=='b'?1:0;
}


void out(int x1, int y1, int x2, int y2) {
  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl<<flush;
  cout.flush();
  exit(0);
}
void go(int x, int lo, int hi, int lov, int hiv, int prev) {
  int mid=(lo+hi)/2;
  int midv=query(x,mid);
  if (n==0) {
    int ty;
    if (midv==lov) ty=midv+1;
    else ty=midv-1;
    int sy;
    if (lov==prev) sy=MAXL;
    else sy=0;
    out(x-1,sy,x,ty);
  }
  if (midv==lov) go(x,mid,hi,lov,hiv,prev);
  else go(x,lo,mid,lov,hiv,prev);
}

void go(int lo, int hi, int lov, int hiv, int sy) {
  int mid=(lo+hi)/2;
  int ans=query(MAXL,mid);
  if (n==0) {
    int ty=mid;
    if (ans==lov) ++ty;
    else --ty;
    out(MINL,sy,MAXL,ty);
  }
  if (ans==lov) {
    go(mid,hi,lov,hiv,sy);
  }
  else {
    go(lo,mid,lov,hiv,sy);
  }
}

int main()
{
  cin>>n;
  int prev=query(MINL,MAXL);
  if (n) for (int y=MAXL-2;;y-=2) {
    int now=query(MINL,y);
    if (n==0) {
      if (now!=prev) {
        out(MINL,y+1,MAXL,y+1);
      }
      else out(MAXL-1,MAXL,MAXL,MAXL-1);
    }
    if (now!=prev) {
      go(MINL+1,MAXL-1,now,prev,y+1);
    }
  }
  out(MAXL-1,MAXL,MAXL,MAXL-1);
}
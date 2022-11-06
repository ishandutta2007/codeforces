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
const int mn=2e3+4;
string a[mn];
typedef pair<int,pii> p3;

int vd[mn][mn];
priority_queue<p3, vector<p3>, greater<p3> > pq;
int rlim,clim;
void upd(int r, int c, int d) {
  if (1<=r&&r<=rlim&&1<=c&&c<=clim)
  if (d<vd[r][c]) {
    vd[r][c]=d;
    pq.push(MP(d,MP(r,c)));
  }
}
int main()
{
  cin>>rlim>>clim;
  int sr,sc; cin>>sr>>sc;
  int TL,TR; cin>>TL>>TR;
  for (int r=1;r<=rlim;r++) {
    string s; cin>>s;
    a[r]=" "+s;
  }
  memset(vd,0x7f,sizeof vd);
  vd[sr][sc]=0;
  pq.push(MP(0,MP(sr,sc)));
  while(!pq.empty()) {
    auto top=pq.top(); pq.pop();
    int r=top.snd.fst,c=top.snd.snd;
    int dist=vd[r][c];
    if (dist!=top.fst) continue;
    if (a[r][c]=='*') continue;
    for (int dr=r-1;dr<=r+1;dr+=2) {
      upd(dr,c,dist);
    }
    upd(r,c-1,dist+1);
    upd(r,c+1,dist);
  }
  int ans=0;
  for (int r=1;r<=rlim;r++) {
    for (int c=1;c<=clim;c++) {
      if (a[r][c]=='*') {
        //printf("*");
        continue;
      }
      int L=vd[r][c];
      int R=L+(c-sc);
      if (L<=TL&&R<=TR) {
        ans++;
        //printf("+");
      }
      //else printf("%d",L);
    }
    //printf("\n");
  }
  printf("%d\n",ans);
}
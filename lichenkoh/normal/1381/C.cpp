#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
vi EMPTYYYYY;
int getidx(vvi & lab2i, int lab) {
  int idx=lab2i[lab].back(); lab2i[lab].pop_back();
  return idx;
}
pair<bool,vi> go() {
  int n,X,Y; cin>>n>>X>>Y;
  vi inp(n);
  for (int i=0;i<n;i++) cin>>inp[i];
  if (!(X<=Y&&Y<=n)) return MP(false,EMPTYYYYY);

  vvi lab2i(n+2);
  for (int i=0;i<n;i++) lab2i[inp[i]].PB(i);

  vi vcnt(n+2);
  for (int lab:inp) vcnt[lab]++;
  int unused=-1;
  for (int lab=1;lab<=n+1;lab++) {
    if (vcnt[lab]==0) {unused=lab;break;}
  }
  vi vfinal(n,unused);

  priority_queue<pii,vpii> pq;
  for (int lab=1;lab<=n+1;lab++) {
    if (vcnt[lab]) pq.push(MP(vcnt[lab],lab));
  }
  for (int k=0;k<X;k++) {
    pii top=pq.top(); pq.pop();
    top.fst--;
    assert(top.fst>=0);
    vfinal[getidx(lab2i,top.snd)]=top.snd;
    if (top.fst>0) pq.push(top);
  }
  vi vcyci;
  vpii vcyc;
  while(!pq.empty()) {
    if (pq.size()==1) {
      pii top=pq.top(); pq.pop();
      int mylab=top.snd;
      int mylabidx=getidx(lab2i, mylab);
      // Attempt to splice
      for (auto &cyc: vcyc) {
        if (mylab!=inp[cyc.fst] && mylab != inp[cyc.snd]) {
          vfinal[cyc.fst]=mylab;
          vfinal[cyc.snd]=inp[cyc.fst];
          vfinal[mylabidx]=inp[cyc.snd];
          vcyci.PB(mylabidx);
          break;
        }
      }
      break;
    } else {
      pii top[2];
      for (int k=0;k<2;k++) {top[k]=pq.top(); pq.pop();}
      assert(top[0].snd!=top[1].snd);
      int idx[2];
      for (int k=0;k<2;k++) {
        idx[k]=getidx(lab2i,top[k].snd);
        vfinal[idx[k]]=top[k^1].snd;
        vcyci.PB(idx[k]);
      }
      vcyc.PB(MP(idx[0],idx[1]));
      for (int k=0;k<2;k++) {
        top[k].fst--;
        if (top[k].fst>0) {
          pq.push(top[k]);
        }
      }
    }
  }
  for (auto cyci: vcyci) {
    assert(vfinal[cyci]!=inp[cyci]);
  }
  int hasy=0;
  for (int i=0;i<n;i++) {
    if (vfinal[i]!=unused) hasy++;
  }
  if (hasy<Y) return MP(false,EMPTYYYYY);
  int rm=hasy-Y;
  assert(rm<=vcyci.size());
  for (int i=0;i<rm;i++) vfinal[vcyci[i]]=unused;
  {
    for (int i=0;i<n;i++) assert(vfinal[i]>=1);
    for (int i=0;i<n;i++) assert(vfinal[i]<=n+1);
    int same=0;
    for (int i=0;i<n;i++) if(inp[i]==vfinal[i]) same++;
    assert(same==X);
    vi vout(n+2);
    for (int i=0;i<n;i++) vout[vfinal[i]]++;
    int yy=0;
    for (int i=0;i<n+2;i++) yy+=min(vcnt[i],vout[i]);
    assert(yy==Y);
  }
  return MP(true,vfinal);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t;
  for (int i=0;i<t;i++) {
    pair<bool,vi> got=go();
    if(got.fst) {
      printf("YES\n");
      for (auto &w:got.snd) printf("%d ",w);
      printf("\n");
    }else{
      printf("NO\n");
    }
  }
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
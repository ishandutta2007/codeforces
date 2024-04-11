#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=1e5+10;
vi vkey;
int vk[mn];
pii f[mn][2];
int lo[2][mn],hi[2][mn],cont[2][mn],stop[2][mn];


class RangeSegTree {
public:
  int segn=-1;
  using S=int;
  vector<S> t;
  S identity = INT_MAX;
  S combine(const S& lefts, const S& rights) {
    return min(lefts,rights);
  }
  void init(int n) {
    segn=n; t.resize(2*segn); for (int i=0;i<2*segn;i++) t[i]=identity;
  }
  void setrange(int l, int r, const S& value) {
    if (l>r) return;
    r++;
    int n=segn;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l] = combine(t[l], value);
        l++;
      }
      if (r&1) {
        --r;
        t[r] = combine(t[r], value);
      }
    }
  }

  S get(int p) {
    int n=segn;
    S res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
  }
  void push() {
    int n=segn;
    for (int i = 1; i < n; ++i) {
      t[i<<1] = combine(t[i<<1], t[i]);
      t[i<<1|1] = combine(t[i<<1|1], t[i]);
      t[i] = identity;
    }
  }
};

RangeSegTree seg[2];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int qn=rint(); int unknown=rint();
  ++qn;
  {
    int qi=0;
    vk[qi]=0;
    vkey.PB(vk[qi]);
    for (int t=0;t<2;t++) {
      lo[t][qi]=0; hi[t][qi]=0;
      vkey.PB(lo[t][qi]);
      vkey.PB(hi[t][qi]);
    }
  }
  for (int qi=1;qi<qn;qi++) {
    vk[qi]=rint();
    vkey.PB(vk[qi]);
    for (int t=0;t<2;t++) {
      lo[t][qi]=rint(); hi[t][qi]=rint();
      vkey.PB(lo[t][qi]);
      vkey.PB(hi[t][qi]);
    }
  }
  makeunique(vkey);
  for (int t=0;t<2;t++) {
    seg[t].init(vkey.size());
    cont[t][qn]=qn;
  }
  for (int qi=qn-1;qi>=0;qi--) {
    int k=vk[qi];
    for (int t=0;t<2;t++) {
      seg[t].setrange(0, bins(vkey,lo[t][qi])-1, qi);
      seg[t].setrange(bins(vkey,hi[t][qi])+1,int(vkey.size())-1, qi);
    }
    for (int t=0;t<2;t++) {
      stop[t][qi]=seg[t].get(bins(vkey,k));
      if (lo[t][qi]<=k&&k<=hi[t][qi]) {
        cont[t][qi]=cont[t][qi+1];
      } else {
        cont[t][qi]=qi;
      }
      //printf("t:%d qi:%d k:%d lo:%d hi:%d stop:%d cont:%d\n",t,qi,k,lo[t][qi],hi[t][qi],stop[t][qi],cont[t][qi]);
    }
  }
  for (int t=0;t<2;t++) f[0][t]=MP(-1,-1);
  for (int t=0;t<2;t++) {
    int qi=0;
    int k=vk[qi];
    //printf("t:%d lo:%d k:%d hi:%d\n",t,lo[t][qi],k,hi[t][qi]);
    if (lo[t][qi]<=k&&k<=hi[t][qi]) {
      chkmax(f[0][t],MP(0,-1));
    }
  }
  for (int qi=0;qi<qn;qi++) {
    for (int t=0;t<2;t++) f[qi+1][t]=f[qi][t];
    int k=vk[qi];
    for (int t=0;t<2;t++) {
      if (f[qi][t].fst>=qi) {
        if(!(lo[t][qi]<=k&&k<=hi[t][qi])) {
          //printf("t:%d qi:%d f[t]:%d lo[t][qi]<=k&&k<=hi[t][qi] failed\n",t,qi,f[t]); fflush(stdout);
          assert(0);
        }
        // Replace t with k now. Then continuously use t^1
        int reach=min(stop[t][qi]-1, cont[t^1][qi+1]-1);
        //printf("t:%d qi:%d stop:%d cont[%d][%d]:%d reach:%d Set f[%d]\n",t,qi,stop[t][qi],t^1,qi+1,cont[t^1][qi+1],reach,t^1);
        chkmax(f[qi+1][t^1], MP(reach,qi));
      }
    }
  }
  vi vans(qn,-1);
  for (int origt=0;origt<2;origt++) {
    if (f[qn-1][origt].fst>=qn-1) {
      int qi=qn-1,t=origt;
      while(qi>=0) {
        int qnext=f[qi][t].snd;
        for (int x=qnext+1;x<=qi;x++) vans[x]=t;
        //printf("qi:%d qnext:%d\n",qi,qnext);
        qi=qnext;
        t^=1;
      }
      printf("Yes\n");
      for (int x=1;x<qn;x++) printf("%d ",vans[x]);
      printf("\n");
      exit(0);
    }
  }
  printf("No\n");

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
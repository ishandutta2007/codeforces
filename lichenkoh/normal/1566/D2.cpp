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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


int ilog2(int n) {
  return 31-__builtin_clz(n);
}

struct Fenwick1D {
    vector<int> bit;  // binary indexed tree
    int n;
    int logn;
    void init(int _n) {
      n = _n;
      logn=ilog2(n);
      bit.resize(n);
    }

    int sum(int r) {
      int ret = 0;
      for (; r >= 0; r = (r & (r + 1)) - 1) {
        ret += bit[r];
      }
      return ret;
    }
    int sum(int l, int r) {
      return sum(r) - sum(l - 1);
    }

    void add(int _idx, int delta) {
      for (int idx=_idx; idx < n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
      }
    }

    int atleast(int needsticks) {
      int pre=0;
      for (int k=logn;k>=0;k--) {
        int askidx=pre + (1<<k) - 1;
        if (askidx < n) {
          int got = bit[askidx];
          if (got < needsticks) {
            needsticks -= got;
            pre |= 1<<k;
          }
        }
      }
      return pre;
    }
};

void go() {
  int n,m; cin>>n>>m;
  int tot=n*m;
  vi a(tot);
  for (int i=0;i<tot;i++) {
    cin>>a[i];
  }
  map<int,vi> k2src;
  map<int,vpii> k2targ;
  for (int i=0;i<tot;i++) k2src[a[i]].PB(i);
  vvi rc2k(n,vi(m));
  {
    int r=0,c=0;
    for (auto &w:k2src) {
      for (auto &x:w.snd) {
        rc2k[r][c]=w.fst;
        k2targ[w.fst].PB(MP(r,c));
        c++;
        if (c==m) {
          c=0; r++;
        }
      }
    }
  }
  vpii b(tot);
  for (auto &w:k2src) {
    vi & vsrc=w.snd;
    vpii & vtarg = k2targ[w.fst];
    sort(vsrc.begin(),vsrc.end());
    sort(vtarg.begin(),vtarg.end());
    map<int,pair<vi,vi> > r2csrc;
    for (int i=0;i<vtarg.size();i++) {
      int src=vsrc[i];
      int r=vtarg[i].fst,c=vtarg[i].snd;
      r2csrc[r].fst.PB(c);
      r2csrc[r].snd.PB(src);
    }
    for (auto &it:r2csrc) {
      int r=it.fst;
      vi & vr=it.snd.fst;
      vi & vsrc=it.snd.snd;
      sort(vr.begin(),vr.end());
      sort(vsrc.begin(),vsrc.end(),greater<int>());
      for (int j=0;j<vr.size();j++) {
        b[vsrc[j]]=MP(r,vr[j]);
      }
    }
  }
  vector<Fenwick1D> fen(n);
  for (int r=0;r<n;r++) fen[r].init(m);
  ll final=0;
  for (int i=0;i<tot;i++) {
    int r=b[i].fst; int c=b[i].snd;
    int got=fen[r].sum(c);
    final+=got;
    fen[r].add(c,1);
  }
  printf("%lld\n",final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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
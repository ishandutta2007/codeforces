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

const int mc=26;
void go() {
  int n; string s,t; cin>>n>>s>>t;
  for (int i=0;i<n;i++) {
    s[i]-='a';
    t[i]-='a';
  }
  vi q[mc];
  for (int i=0;i<n;i++) {
    q[s[i]].PB(i);
  }
  for (int c=0;c<mc;c++) reverse(q[c].begin(),q[c].end());
  ll final=LLONG_MAX/2;
  ll prev=0;

  Fenwick1D fen; fen.init(n);
  for (int x=0;x<n;x++) fen.add(x,1);

  for (int pos=0;pos<n;pos++) {
    int tpos=t[pos];
    for (int c=0;c<tpos;c++) {
      if (q[c].size()>0) {
        ll moves=fen.sum(q[c].back())-1;
        ll cand=prev+moves;
        chkmin(final,cand);
      }
    }
    {
      int c=tpos;
      if (q[c].size()>0) {
        int src=q[c].back();
        ll moves=fen.sum(src)-1;
        fen.add(src,-1);
        prev+=moves;
        q[c].pop_back();
      } else {
        break;
      }
    }
  }
  if (final >= LLONG_MAX/2) final=-1;
  printf("%lld\n",final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test; cin>>test; for (int i=0;i<test;i++) go();
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
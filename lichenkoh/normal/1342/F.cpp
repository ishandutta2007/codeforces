#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=15;
int a[mn];
const int mr=mn-1;
const int ms=mn-2;
int R[mr];
int S[ms];
int revr[mn],revs[mn];
int f[mr][1<<ms];
int g[mr][1<<ms];
int zsum[1<<ms];

inline int next_bit_perm(int v) {
  int t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

// Nonempty subset increasing
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
#define FORSI(sub, full, FNWORK) {{int sub = 0; {FNWORK}} for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; ) {FNWORK}}


void out(int sn, int z, int n) {
  int rn=n-sn;
  int ri=rn-2;
  printf("%d\n",sn);
  vector<pii> v; v.reserve(sn);
  for (int i=0;i<sn;i++) if (0==(z&(1<<i))) v.PB(MP(i,ri+1));
  for (int rx=ri;rx>=1;rx--) {
    int bz=g[rx][z];
    assert((bz&z)==bz);
    int w=z^bz;
    for (int i=0;i<sn;i++) if (w&(1<<i)) v.PB(MP(i,rx));
    z=bz;
  }
  assert(v.size()==sn);
  int univ=(1<<n)-1;
  for (auto &p:v) {
    int src=revs[p.fst];
    int des=revr[p.snd];
    assert (univ & (1<<src));
    assert (univ & (1<<des));
    int psrc=__builtin_popcount(univ & (1<<src)-1)+1;
    int pdes=__builtin_popcount(univ & (1<<des)-1)+1;
    printf("%d %d\n",psrc,pdes);
    univ ^= 1<<src;
  }
}

void go() {
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  bool imm=true;
  for (int i=1;i<n;i++) {
    if (a[i-1]>=a[i]) imm=false;
  }
  if (imm) {
    printf("0\n"); return;
  }
  for (int sn=1;sn<(n-1);sn++) {
    for (int s = (1 << sn) - 1; s < (1 << n); s = next_bit_perm(s)) {
      int rn=0;
      {
        int sidx=0;
        for (int i=0;i<n;i++) {
          if (s&(1<<i)) {
            revs[sidx]=i;
            S[sidx++]=a[i];
          }
          else {
            revr[rn]=i;
            R[rn++]=a[i];
          }
        }
      }
      for (int z=0;z<(1<<sn);z++) {
        int sum=0;
        for (int i=0;i<sn;i++) if ((1<<i)&z) sum+=S[i];
        zsum[z]=sum;
      }
      {
        int cur=0;
        f[cur][0]=R[0];
        for (int z=1;z<(1<<sn);z++) f[cur][z]=INF;
      }
      for (int ri=0;ri<rn-1;ri++) {
        int cur=ri;
        int nxt=ri+1;
        for (int z=0;z<(1<<sn);z++) f[nxt][z]=INF;
        for (int z=0;z<(1<<sn);z++) {
          int now=f[cur][z];
          if (now<INF) {
            int after=R[ri+1];
            int diff=now+1-after;
            FORSI(w, ((1<<sn)-1)^z,
            {
              int cand=zsum[w];
              if (cand>=diff) {
                if (ri==rn-2) {
                  out(sn,z,n);
                  return;
                } else {
                  int sumcand=cand+after;
                  if (sumcand < f[nxt][z|w]) {
                    f[nxt][z|w] = sumcand;
                    g[nxt][z|w] = z;
                  }
                }
              }
            }
              )
          }
        }
      }
    }
  }
  printf("%d\n",n-1);
  for (int i=0;i<n-1;i++) printf("1 2\n");
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T=rint();
  for (int i=0;i<T;i++) {
    go();
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
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
const int mn=(4e5)+4;
const int mk=27;
int inp[mn];
int a[2][mn];
int c[2];
const bool DBG=0;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    inp[i]=rint();
  }
  int final=0;
  for (int k=0;k<mk;k++) {
    int mask=(1<<(k))-1;
    memset(c,0,sizeof c);
    for (int i=0;i<n;i++) {
      int b=(inp[i]>>k)&1;
      int u=inp[i]&mask;
      if (DBG) if (k==1) printf("inp:%d b:%d u:%d\n",inp[i],b,u);
      a[b][c[b]]=u;
      ++c[b];
    }
    for (int b=0;b<2;b++) {
      sort(a[b],(a[b])+c[b]);
      if (DBG) if (k==1) {
        for (int i=0;i<c[b];i++) printf("%d ",a[b][i]);
        printf(" end a[%d]\n",b);
      }
    }
    ll sumk=0;
    for (int p=0;p<2;p++) {
      for (int q=0;q<2;q++) {
        if (p==0&&q==1) continue; // Dont double count 0-1 and 1-0.
        int l=0;
        ll sumpq=0;
        for (int r=c[q]-1;r>=0;r--) {
          while(l<c[p] && a[p][l] + a[q][r] < (1<<k) ) {
            l++;
            if (DBG) if (k==1) printf("k:%d p:%d q:%d l:%d r:%d\n",k,p,q,l,r);
          }
          if (p^q) {
            sumpq+=l;
            if (DBG) if (k==1) printf("k:%d r:%d p:%d q:%d Add l:%d\n",k,r,p,q,l);
          }
          else {
            int cnt=max(0,r-l);
            //if (r>=l) --cnt;
            if (DBG) if (k==1) printf("k:%d r:%d p:%d q:%d Add cnt:%d l:%d\n",k,r,p,q,cnt,l);
            sumpq+=cnt;
          }
        }
        sumk+=sumpq;
      }
    }
    if (sumk&1) final |= (1<<k);
  }
  printf("%d\n",final);
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
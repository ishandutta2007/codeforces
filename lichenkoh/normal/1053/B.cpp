#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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
const int mn=3e5+4;
int a[mn];
int prec[2][mn];
int presum[mn];
const int mb=62;
int npos[mn][mb];

int queryc(int l, int r, int b) {
  return prec[b][r]-prec[b][l-1];
}
int querysum(int l, int r) {
  return presum[r]-presum[l-1];
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<=n;i++) {
    ll x; cin>>x; a[i]=__builtin_popcountll(x);
  }
  for (int i=1;i<=n;i++) {
    presum[i]+=presum[i-1]+a[i];
  }
  for (int i=1;i<=n;i++) {
    ++prec[presum[i]&1][i];
  }
  for (int b=0;b<2;b++) {
    for (int i=1;i<=n;i++) {
      prec[b][i]+=prec[b][i-1];
      //printf("b:%d i:%d prec:%d\n",b,i,prec[b][i]);
    }
  }
  for (int b=mb-1;b>=0;b--) {
    npos[n][b]=INF;
  }
  for (int i=n-1;i>=1;i--) {
    memcpy(npos[i],npos[i+1],sizeof npos[i]);
    int ai=a[i+1];
    for (int b=ai-1;b>=0;b--) {
      chkmin(npos[i][b],i+1);
    }
  }
  ll final=0;
  for (int lp=1;lp<=n;lp++) {
    ll ans=(a[lp]==0)?1:0;
    int rp=lp;
    while(rp<=n) {
      int nr=npos[rp][a[rp]];
      int L=rp,R=min(nr-1,n);
      int bneed=a[L]*2;
      // Bins
      int imin=L,imax=R+1;
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (querysum(lp,imid)<bneed) imin=imid+1;
        else imax=imid;
      }
      int newL=imin;
      //printf("lp:%d rp:%d newL:%d R:%d\n",lp,rp,newL,R);
      if (newL<=R) {
        ans+=queryc(newL,R,presum[lp-1]&1);
        //printf("b:%d add:%d\n",presum[lp-1]&1,queryc(newL,R,presum[lp-1]&1));
      }
      rp=nr;
    }
    final+=ans;
  }
  printf("%lld\n",final);
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
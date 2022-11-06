#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
vector<ll> s;
const ll C=1000000000000000000LL;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); s.resize(n);
  for (int i=0;i<n;i++) s[i]=rlong();
  sort(s.begin(),s.end());
  vll v; v.reserve(n-1);
  ull sumoverlap=0;
  for (int i=0;i<n-1;i++) {
    ll diff=(s[i]+C)-s[i+1]+1;
    //printf("diff:%lld\n",diff);
    if (diff>0) {
      v.PB(diff);
      sumoverlap+=diff;
    }
  }
  sort(v.begin(),v.end(),greater<ll>());
  vector<ull> pre(v.size()+1);
  for (int i=0;i<n-1;i++) pre[i+1]=pre[i]+v[i];
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
    ll l=rlong(),r=rlong();
    ll thresh=l+C-r; assert(thresh>=0);
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)/2;
      if (v[imid]>thresh) imin=imid+1;
      else imax=imid;
    }
    ull sumcorrect=pre[imin]-((ull)thresh)*((ull)imin);
    ull overlap=sumcorrect;
    ull all=((ull)n)*((ull)(r-l+1));
    ull ans=all-overlap;
    //printf("thresh:%lld sumcorrect:%llu\n",thresh,sumcorrect);
    printf("%llu ",ans);
  }
  printf("\n");

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
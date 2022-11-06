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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=2e5+2;
vector<int> b[30];
int c[30];
map<int,vector<int> > h;
map<int,int> g;
int a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint();
    a[i]=x;
    for (int k=0;k<30;k++) {
      if (x&(1<<k)) b[k].PB(i);
    }
    h[x].PB(i);
  }
  ll final= (n*((ll)n+1LL))>>1;
  for (int t=0;t<n;t++) {
    int l=-1,r=n;
    int val=a[t];
    for (int k=0;k<30;k++) {
      if (0==(val&(1<<k))) {
        int idx=c[k];
        if (idx>0&&b[k].size()>0) chkmax(l,b[k][idx-1]);
        if (idx<b[k].size()) chkmin(r, b[k][idx]);
      }
      else {
        c[k]++;
      }
    }
    int idx=g[val];
    g[val]++;
    auto &v=h[val];
    if (idx<v.size()-1) chkmin(r, v[idx+1]);
    l++; r--;
    ll gl=t-l+1;
    ll gr=r-t+1;
    ll sub=gl*(ll)gr;
    //printf("t:%d l:%d r:%d\n",t,l,r);
    final-=(sub);
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
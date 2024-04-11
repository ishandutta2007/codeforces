#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

int solve(vi v) {
  int n=v.size();
  int as=0,ae=n-1;
  int len=0;
  {
    int c=v[ae];
    while(ae>=as&&v[ae]==c) {
      c^=1;len++;ae--;
    }
  }
  int bs=v[ae+1],be=v[n-1];
  int sgn=1;
  while(1) {
    int olen=len;
    int c=be^1;
    //printf("sgn:%d as:%d ae:%d bs:%d be:%d\n",sgn,as,ae,bs,be);
    if (sgn==1) {
      while(as<=ae&&v[as]==c) {
        //printf("as:%d c:%d\n",as,c);
        as++; len++; c^=1;
      }
    }
    else {
      while(as>=ae&&v[as]==c) {
        //printf("as:%d c:%d\n",as,c);
        as--; len++; c^=1;
      }
    }
    swap(bs,be);
    bs=c^1;
    if (len==olen) return len;
    swap(as,ae);
    sgn=-sgn;
  }
  return -1;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s; int n=s.length();
  vi a(n);
  for (int i=0;i<n;i++) a[i]=(s[i]=='b')?1:0;
  int final=0;
  int now=1;
  for (int i=1;i<n;i++) {
    if (a[i]!=a[i-1]) {
      ++now;
    }
    else now=1;
    chkmax(final,now);
  }
  for (int k=0;k<2;k++) {
    //printf("K:%d   \n",k);
    chkmax(final,solve(a));
    reverse(a.begin(),a.end());
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
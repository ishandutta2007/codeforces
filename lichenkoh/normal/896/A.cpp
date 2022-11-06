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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const string o0="What are you doing at the end of the world? Are you busy? Will you save us?";
const string g="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
const string g0="What are you doing while sending \"";
const string g1="\"? Are you busy? Will you send \"";
const string g2="\"?";
const int glen=g.length();
const int mn=100000+2;
const ll mx=1e18+5;
ll f[mn];
char solve(int n, ll k) {
  if (n==0) {
    if (k<o0.length()) return o0[k];
    else return '.';
  }
  else {
    ll h0=g0.length();
    ll h1=h0+f[n-1];
    ll h2=h1+g1.length();
    ll h3=h2+f[n-1];
    ll h4=h3+g2.length();
    if (k<h0) return g0[k];
    else if (k<h1) return solve(n-1,k-h0);
    else if (k<h2) return g1[k-h1];
    else if (k<h3) return solve(n-1,k-h2);
    else if (k<h4) return g2[k-h3];
    else return '.';
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  f[0]=o0.length();
  for (int k=1;k<mn;k++) {
    f[k]=2*f[k-1]+glen;
    if (f[k]>mx) f[k]=mx;
  }
  int q=rint();
  for (int i=0;i<q;i++) {
    int n=rint(); ll k=rlong()-1;
    char c=solve(n,k);
    printf("%c",c);
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
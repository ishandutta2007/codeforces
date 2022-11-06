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

string s;
int sidx=0;
char gc() {
  return s[sidx++];
}
int gop(int l, int r, char op) {
  if (op=='|') {
    return l|r;
  }
  else if (op=='&') {
    return l&r;
  }
  else if (op=='^') {
    return l^r;
  }
  else assert(0);
}
const int ZERO=1;
const int ONE=2;
const int QU=4;
int dop(int l, char op) {
  if (op=='|') {
    if (l==ZERO) return QU;
    else if (l==ONE) return ONE;
    else if (l==QU) return ONE|QU;
    else assert(0);
  }
  else if (op=='&') {
    if (l==ZERO) return ZERO;
    else if (l==ONE) return QU;
    else if (l==QU) return ZERO|QU;
    else assert(0);
  }
  else if (op=='^') {
    if (l==ZERO) return QU;
    else if (l==ONE) return QU;
    else if (l==QU) return ZERO|ONE;
    else assert(0);
  }
  else assert(0);
}
vector<int> vm={ZERO,ONE,QU};
int dfs() {
  char c=gc();
  if (c=='(') {
    int zl=dfs();
    char op=gc();
    int zr=dfs();
    assert(gc()==')');
    int ans=0;
    for (int l=0;l<2;l++) {
      for (int r=0;r<2;r++) {
        if (0==(zl&(1<<l))) continue;
        if (0==(zr&(1<<r))) continue;
        int got=gop(l,r,op);
        if (got==0) ans|=ZERO;
        if (got==1) ans|=ONE;
      }
    }
    if (zl&QU) {
      for (auto &m:vm) {
        if (m&zr) {
          ans|=dop((m&zr),op);
        }
      }
    }
    if (zr&QU) {
      for (auto &m:vm) {
        if (m&zl) {
          ans|=dop((m&zl),op);
        }
      }
    }
    return ans;
  }
  else if (c=='0') {
    return ZERO;
  }
  else if (c=='1') {
    return ONE;
  }
  else if (c=='?') {
    return QU;
  }
  else assert(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  cin>>s;
  int slen=s.length();
  sidx=0; int g0=dfs(); assert(sidx==slen);
  if (g0&QU) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
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
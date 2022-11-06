#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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
map<ll,ll> h;
map<ll,ll> dp;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt(),w=readInt();
    int l=x-w,r=x+w;
    auto it=h.find(l);
    if (it==h.end()) {
      h[l]=r;
    }
    else {
      chkmin(it->snd,r);
    }
    dp[l]=0;dp[r]=0;
  }
  int best=0;
  for (auto &w:dp) {
    int l=w.fst;
    chkmax(w.snd,best);
    chkmax(best,w.snd);
    auto it=h.find(l);
    if (it!=h.end()) {
      int r=it->snd;
      int ans=w.snd+1;
      chkmax(dp[r],ans);
    }
  }
  printf("%d\n",best);
}
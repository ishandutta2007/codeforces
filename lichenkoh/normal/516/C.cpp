#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1e18;
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

struct SS {
  ll distOnRight;
  ll bestFromLeft;
  ll bestFromRight;
  ll bestInternal;
};
typedef struct SS S;
S identity;
S combine(S &a, S &b) {
  if (a.distOnRight==0) return b;
  if (b.distOnRight==0) return a;
  S c;
  c.distOnRight=a.distOnRight+b.distOnRight;
  c.bestFromLeft=max(a.bestFromLeft, a.distOnRight+b.bestFromLeft);
  c.bestFromRight=max(b.bestFromRight, a.bestFromRight+b.distOnRight);
  //printf("dbg:%d,%d. %d+%d\n",a.distOnRight,b.distOnRight, a.bestFromRight,b.bestFromLeft);
  c.bestInternal=max(a.bestFromRight+b.bestFromLeft, max(a.bestInternal, b.bestInternal));
  return c;
}
const int MAXN=2e5+4;
S t[2*MAXN];
int segn;
void build(int n) {  // build the tree
  segn=n;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
S query(int l, int r) {
  int n=segn;
    r++;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) resl = combine(resl, t[l++]);
        if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
}
int h[MAXN],d[MAXN];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),m=readInt();
  for (int i=0;i<n;i++) d[i]=readInt();
  for (int i=0;i<n;i++) h[i]=readInt();
  segn=2*n;
  for (int i=0;i<n;i++) {
    t[segn+i].bestInternal=0;
    t[segn+i].bestFromLeft=2LL*((ll)h[i]);
    t[segn+i].bestFromRight=2LL*((ll)h[i])+d[i];
    t[segn+i].distOnRight=d[i];
    t[segn+n+i]=t[segn+i];
  }
  build(segn);
  for (int i=0;i<m;i++) {
    int a=readInt()-1,b=readInt()-1;
    int l,r;
    if (a<=b) {
      l=b+1,r=n+a-1;
    }
    else {
      l=b+1,r=a-1;
    }
    //printf("a:%d b:%d l:%d r:%d\n",a,b,l,r);
    auto q=query(l,r);
    printf("%lld\n",q.bestInternal);
  }
}
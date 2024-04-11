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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
char readCh()
{
    readAhead(16);
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

const int MAXSEG = 1000004;  // limit for array size
int segn;  // array size
typedef struct {
  int minlo;
  int delta;
} S;
S t[2 * MAXSEG];
S identity;
S combine(const S& lefts, const S& rights) {
  S res;
  res.minlo=min(lefts.minlo, lefts.delta+rights.minlo);
  res.delta=lefts.delta+rights.delta;
  return res;
}
void build() {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) { // sum on interval [l, r]
  r++;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
const int mn=MAXSEG;
char a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=0;
  while(1) {
    char c=readCh();
    a[n++]=c;
    if (c=='\n') break;
  }
	identity.minlo=0,identity.delta=0;
  segn=n;
  for (int i=0;i<n;i++) {
    if (a[i]=='(') {
      t[segn+i].minlo=0;
      t[segn+i].delta=1;
    }
    else {
      t[segn+i].minlo=0;
      t[segn+i].delta=-1;
    }
  }
  build();
  int m=readInt();
  for (int i=0;i<m;i++) {
    int l=readInt()-1,r=readInt()-1;
    S res=query(l,r);
    //printf("minlo:%d delta:%d\n",res.minlo,res.delta);
    int downskip = -res.minlo;
    int ans=r-l+1 - downskip - max(0,res.delta+downskip);
    //printf("len:%d - downskip:%d - max(0,%d)\n",
    //  r-l+1,downskip,max(0,res.delta+downskip));
    printf("%d\n",ans);
  }
}
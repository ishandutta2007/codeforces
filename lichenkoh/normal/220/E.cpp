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

void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
vector<int>vx;
int bins(int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}



const int MAXSEG = 1e5+4;  // limit for array size
int segn;  // array size
typedef int S;

S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}

void modify(int *t, int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] += value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int *t, int l, int r) { // sum on interval [l, r]
  if (l>r) return 0;
  r++;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
S t[3][2 * MAXSEG];
const int mn=2e5+4;
int a[mn];
const int L=0,R=1;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); ll k=rlong();
  for (int i=0;i<n;i++) a[i]=rint();
  vx.resize(n); for (int i=0;i<n;i++) vx[i]=a[i];
  makeunique(vx);
  segn=vx.size();
  for (int i=0;i<n;i++) a[i]=bins(a[i]);
  ll inv=0;
  for (int i=0;i<n;i++) {
    inv+=query(t[R],a[i]+1,segn-1);
    modify(t[R],a[i],1);
  }

  {
    modify(t[R],a[0],-1);
    modify(t[L],a[0],1);
  }

  int l=0;
  ll ans=0;
  for (int r=1;r<n;) {
    while(inv<=k&&l<r-1) {
      l++;
      int got=query(t[L],a[l]+1,segn-1)+query(t[R],0,a[l]-1);
      modify(t[L],a[l],1);
      inv+=got;
    }
    //printf("r:%d l:%d inv:%lld\n",r,l,inv);
    if (inv>k) ans+=min(l-1,r-1)+1;
    else ans+=min(l,r-1)+1;
    {
      int got=query(t[L],a[r]+1,segn-1)+query(t[R],0,a[r]-1);
      //printf("r:%d got:%d\n",r,got);
      inv-=got;
      modify(t[R],a[r],-1);
    }
    r++;
  }
  printf("%lld\n",ans);
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
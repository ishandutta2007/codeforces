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
//#define DEBUG_CAT
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

const int MAXSEG = 131072;  // limit for array size
int segn;  // array size
typedef pair<ll,int> S;
S t[2 * MAXSEG];
S identity = MP(0ll,0);
S combine(const S& lefts, const S& rights) {
  return MP(lefts.fst+rights.fst, max(lefts.snd,rights.snd));
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
int modx;
int lq,rq;
void domodh(int l, int r, int idx) {
  if (r<=lq||l>=rq) return;
  //printf("l:%d r:%d idx:%d segn:%d\n",l,r,idx,segn);
  if (l+1==r) {
    int nv=t[idx].fst%modx;
    t[idx].fst=nv;
    t[idx].snd=nv;
  }
  else {
    bool has=0;
    int lidx=idx<<1;
    int ridx=lidx|1;
    int mid=(l+r)>>1;
    //printf("t[lidx]:%d t[ridx]:%d\n",t[lidx].snd,t[ridx].snd);
    if (t[lidx].snd>=modx) {
      domodh(l,mid,lidx); has=1;
    }
    if (t[ridx].snd>=modx) {
      domodh(mid,r,ridx); has=1;
    }
    if (has) t[idx]=combine(t[lidx],t[ridx]);
  }
}
void domod(int l, int r, int mod) {
  lq=l; rq=r+1; modx=mod;
  domodh(0,segn,1);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),m=readInt();
  segn=1;
  while((segn-1)<n) segn*=2;
  for (int x=1;x<=n;x++) {
    int v=readInt();
    t[segn+x]=MP(v,v);
  }
  build();
  for (int i=0;i<m;i++) {
    int type=readInt();
    dbg("type:%d\n",type);
    if (type==1) {
      int l=readInt(),r=readInt();
      auto got=query(l,r);
      printf("%lld\n",got.fst);
    }
    else if (type==2) {
      int l=readInt(),r=readInt(),mod=readInt();
      domod(l,r,mod);
    }
    else {
      int k=readInt(),x=readInt();
      modify(k,MP(x,x));
    }
  }
}
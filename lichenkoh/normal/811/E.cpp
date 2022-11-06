#include <bits/stdc++.h>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
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
const int INF=1<<25;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
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
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const int MAXSEG = 1e5;  // limit for array size
int segn;  // array size
int ht;
typedef struct ST {
  pair<int,int> l[10],r[10];
  int cnt;
} S;
S t[2 * MAXSEG];
S identity;
const ll MAXUF=1e6+4;
int p[MAXUF];
void inituf() {
  for (int x=0;x<MAXUF;x++) p[x]=x;
}
int ffind(int x) {
  if (p[x] != x) {
    p[x] = ffind(p[x]);
  }
  return p[x];
}
void funion(int x, int y) {
  if (rand()&1) swap(x,y); 
  int xr = ffind(x);
  int yr = ffind(y);
  p[xr] = yr;
}
void print(const S& a) {
  printf("cnt:%d\n",a.cnt);
  for (int x=0;x<ht;x++) {
    printf("(%d,%d) (%d,%d)\n",a.l[x].fst,a.l[x].snd,a.r[x].fst,a.r[x].snd);
  }
}

int ssz,midssz;
int s[20];
int mids[20];

S combine(const S& lefts, const S& rights) {
  if (lefts.cnt==-1) return rights;
  if (rights.cnt==-1) return lefts;
  S res;
  int rescnt=lefts.cnt+rights.cnt;
  for (int x=0;x<ht;x++) {
    if (lefts.r[x].fst==rights.l[x].fst) { // Same color
      //printf("x:%d lrf:%d rlf:%d\n",x,lefts.r[x].fst,rights.l[x].fst);
      funion(lefts.r[x].snd, rights.l[x].snd);
    }
  }
  ssz=0;
  for (int x=0;x<ht;x++) {
    {
      int col=ffind(lefts.l[x].snd);
      res.l[x].fst=lefts.l[x].fst;
      res.l[x].snd=col;
      s[ssz++]=col;
      //dbg("x:%d lcol:%d\n",x,col);
    }
    {
      int col=ffind(rights.r[x].snd);
      res.r[x].fst=rights.r[x].fst;
      res.r[x].snd=col;
      s[ssz++]=col;
      //dbg("x:%d rcol:%d\n",x,col);
    }
  }
  sort(s,s+ssz);
  // Count middle colors which are no longer involved
  midssz=0;
  for (int x=0;x<ht;x++) {
    {int mm=ffind(lefts.r[x].snd);
    int imin=0,imax=ssz;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (s[imid]<mm) imin=imid+1;
      else imax=imid;
    }
    if(imin>=ssz||s[imin]!=mm) {
      mids[midssz++]=mm;
    }}
    {int mm=ffind(rights.l[x].snd);
    int imin=0,imax=ssz;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (s[imid]<mm) imin=imid+1;
      else imax=imid;
    }
    if(imin>=ssz||s[imin]!=mm) {
      mids[midssz++]=mm;
    }}
  }
  if (midssz) {
    sort(mids,mids+midssz);
    rescnt++;
    for (int i=1;i<midssz;i++) {
      if (mids[i]!=mids[i-1]) rescnt++;
    }
  }
  res.cnt=rescnt;
  // Reset Union Find
  for (int x=0;x<ht;x++) {
    p[lefts.r[x].snd]=lefts.r[x].snd;
    p[rights.l[x].snd]=rights.l[x].snd;
  }
  //print(lefts); print(rights); print(res);
  //printf("\n\n");
  return res;
}
void build() {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

/*void modify(int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}*/

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
const int maxn=10,maxm=100000;
int a[maxn][maxm];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  inituf();
  int n=readInt(),m=readInt(),q=readInt();
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) a[x][y]=readInt();
  ht=n; segn=m;
  identity.cnt=-1;
  int idx=0;
  for (int y=0;y<m;y++) {
    t[segn+y].cnt=0;
    for (int x=0;x<ht;x++) {
      t[segn+y].l[x]=t[segn+y].r[x]=MP(a[x][y],idx);
      //printf("y:%d x:%d idx:%d\n",y,x,idx);
      if (x==ht-1||a[x][y]!=a[x+1][y]) idx++;
    }
  }
  build();
  for (int i=0;i<q;i++) {
    int l=readInt()-1,r=readInt()-1;
    S res=query(l, r);
    int ans=res.cnt;
    midssz=0;
    for (int x=0;x<ht;x++) {
      //printf("x:%d rl:%d rr:%d\n",x,res.l[x].snd,res.r[x].snd);
      mids[midssz++]=res.l[x].snd; mids[midssz++]=(res.r[x].snd);
    }
    if (midssz) {
      sort(mids,mids+midssz);
      ans++;
      for (int i=1;i<midssz;i++) {
        if (mids[i]!=mids[i-1]) ans++;
      }
    }
    //printf("res:%d s:%d\n",res.cnt,(int)s.size());
    printf("%d\n",ans);
  }
}
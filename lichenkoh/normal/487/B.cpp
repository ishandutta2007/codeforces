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
const ll INF=1e15;
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

ll readInt()
{
    readAhead(16);

    ll x = 0;
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

ll segn;
void build(ll *t) {  // build the tree
  ll n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(ll *t, ll p, ll value) {  // set value at position p
  ll n=segn;
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

ll query(ll *t, ll l, ll r) {  // sum on interval [l, r]
  r++;
  ll n=segn;
  ll res = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmin(res, t[l++]);
    if (r&1) chkmin(res, t[--r]);
  }
  return res;
}


class RmqSparseTable {

  ll* logTable;
  ll** rmq;
  ll* a;
  int n;
  public:
  RmqSparseTable(ll *_a, int _n) {
    a=_a;
    n=_n;

    logTable = new ll[n + 1];
    fill(logTable,logTable+n+1,0);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    rmq = new ll*[logTable[n] + 1];
    for (int i=0;i<logTable[n] + 1;i++) {
      rmq[i]=new ll[n];
    }
    for (int i = 0; i < n; ++i)
      rmq[0][i] = i;

    for (int k = 1; (1 << k) < n; ++k) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        ll x = rmq[k - 1][i];
        ll y = rmq[k - 1][i + (1 << k - 1)];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }

  ll minPos(ll i, ll j) {
    ll k = logTable[j - i];
    ll x = rmq[k][i];
    ll y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
  ll minVal(ll i, ll j) {
    if (i>j) return INF;
    ll k = logTable[j - i];
    ll x = rmq[k][i];
    ll y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? a[x] : a[y];
  }
};


ll getmaxtake(ll x, ll s, ll l, RmqSparseTable &tmin, RmqSparseTable &tmax) {
  ll imin=l,imax=x+1+1+1;
  while(imin<imax) {
    ll imid=(imin+imax)>>1;
    if (x-imid+1<0) {imax=imid; continue;}
    ll lo=tmin.minVal(x-imid+1,x);
    ll hi=-tmax.minVal(x-imid+1,x);
    if (hi-lo<=s) {imin=imid+1;}
    else imax=imid;
  }
  ll ans=imin-1;
  if (l<=ans&&ans<=x+1) {
    ll imid=ans;
    ll lo=tmin.minVal(x-imid+1,x);
    ll hi=-tmax.minVal(x-imid+1,x);
    if (hi-lo<=s) return ans;
  }
  return -1;
}
const int mn=1e5+4;
ll va[mn],vna[mn],tf[2*mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),s=readInt(),l=readInt();
  for (int i=0;i<n;i++) va[i]=readInt();
  for (int i=0;i<n;i++) vna[i]=-va[i];
  RmqSparseTable tmin=RmqSparseTable(va,n);
  RmqSparseTable tmax=RmqSparseTable(vna,n);
  segn=n+1;
  for (int i=1;i<n;i++) tf[segn+i]=INF;
  build(tf);
  for (int x=l;x<=n;x++) {
    ll gmt=getmaxtake(x-1,s,l,tmin,tmax);
    if (gmt==-1) continue;
    //printf("x:%d %d %d\n",x,gmt,l);
    assert(gmt>=l);
    ll L=x-gmt,R=x-l;
    assert(L<=R);
    ll q=query(tf,L,R)+1;
    if (x==n) {
      if (q>=INF) printf("-1\n");
      else printf("%lld\n",q);
      return 0;
    }
    modify(tf,x,q);
  }
  printf("-1\n");
}
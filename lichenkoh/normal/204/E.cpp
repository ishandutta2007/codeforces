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

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 2e5+4;

const int MAXSEG = MAXN;  // limit for array size
int segn;  // array size
typedef int SEGS;
SEGS t[2 * MAXSEG];
SEGS identity = 0;
SEGS combine(const SEGS& lefts, const SEGS& rights) {
  return max(lefts,rights);
}
void modify(int l, int r, const SEGS& value) {
  r++;
  int n=segn;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      t[l] = combine(t[l], value);
      l++;
    }
    if (r&1) {
      --r;
      t[r] = combine(t[r], value);
    }
  }
}

/*S query(S *t, int p) {
  int n=segn;
  S res = identity;
  for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
  return res;
}*/
void push() {
  int n=segn;
  for (int i = 1; i < n; ++i) {
    t[i<<1] = combine(t[i<<1], t[i]);
    t[i<<1|1] = combine(t[i<<1|1], t[i]);
    t[i] = identity;
  }
}


const int mx=MAXN;
typedef set<int> UFTYPE;
class UnionFind {
public:
    int ufParent[mx];
    UFTYPE ufData[mx];
    int vl[mx],vr[mx];
    int lastlcp[mx];
    void init(int n) {
      for (int x=0;x<n;x++) {
        ufParent[x]=x;
        vl[x]=x;
        vr[x]=x;
      }
    }
    int ffind(int x) {
      if (ufParent[x] != x) {
        ufParent[x] = ffind(ufParent[x]);
      }
      return ufParent[x];
    }
    int funion(int _x, int _y) {
      int xr = ffind(_x);
      int yr = ffind(_y);
      if (xr==yr) return yr;
      if (ufData[xr].size() > ufData[yr].size()) swap(xr,yr);
      ufParent[xr] = yr;
      chkmin(vl[yr], vl[xr]);
      chkmax(vr[yr], vr[xr]);
      for (auto &w:ufData[xr]) ufData[yr].insert(w);
      return yr;
    }
};



int S[MAXN];
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN], revsa[MAXN];

bool sufCmp(int i, int j)
{
  if (pos[i] != pos[j])
    return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(int stringlen)
{
  N = stringlen;
  REP(i, N) sa[i] = i, pos[i] = S[i];
  for (gap = 1;; gap *= 2)
  {
    sort(sa, sa + N, sufCmp);
    REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
    REP(i, N) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break;
  }
}

void buildLCP()
{
  for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
    {
      for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
        ++k;
      lcp[pos[i]] = k;
      if (k)--k;
    }
}
void buildREVSA() {
  for (int i=0;i<N;i++) revsa[sa[i]]=i;
}

vector<int> vlen2lcp[MAXN];
const int mc=1e5+2;
int ti2tlen[mc];
int ti2sidx[mc];
UnionFind uf;
char temp[mc];
const int SPLITTER=1000000;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tn,k; scanf("%d %d\n",&tn,&k);
  int sidx=0;
  for (int ti=0;ti<tn;ti++) {
    ti2sidx[ti]=sidx;
    scanf("%s\n",temp);
    int tlen=strlen(temp);
    ti2tlen[ti]=tlen;
    for (int i=0;i<tlen;i++) {
      S[sidx++]=temp[i]-'a';
    }
    S[sidx++]=SPLITTER+ti;
  }
  int slen=sidx;
  buildSA(slen);
  buildREVSA();
  buildLCP();
  /*for (int i=0;i<slen;i++) {
    printf("%d ",S[i]);
  }
  printf(" end S\n");
  for (int i=0;i<slen;i++) {
    int pp=sa[i];
    for (int j=pp;j<slen;j++) printf("%d ",S[j]);
    printf(" end SA %d pos:%d\n",i,pp);
  }*/
  for (int i=0;i<slen;i++) {
    vlen2lcp[lcp[i]].PB(i);
  }
  uf.init(slen);
  for (int ti=0;ti<tn;ti++) {
    int xs=ti2sidx[ti];
    int xe=xs+ti2tlen[ti];
    for (int x=xs;x<xe;x++) {
      int saidx = revsa[x];
      uf.ufData[saidx].insert(ti);
    }
  }
  segn=slen;
  for (int len=MAXN-1;len>=1;len--) {
    for (auto &saidx:vlen2lcp[len]) {
      int root=uf.funion(saidx,saidx+1);
      //printf("len:%d merge: %d %d\n",len,saidx,saidx+1);
      if (uf.ufData[root].size()>=k) {
        int l=uf.vl[root];
        int r=uf.vr[root];
        modify(l,r,len);
      }
    }
  }
  push();
  for (int ti=0;ti<tn;ti++) {
    int xs=ti2sidx[ti];

    int xe=xs+ti2tlen[ti];
    ll final=0;
    for (int pos=xs;pos<xe;pos++) {
      int saidx=revsa[pos];
      final+=t[segn+saidx];
    }
    if (k==1) {
      ll tlen=ti2tlen[ti];
      final=(1ll*tlen*(tlen+1LL))/2;
    }
    printf("%lld ",final);
  }
  printf("\n");
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
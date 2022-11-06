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

const int MAXN = 3e5+2;

const int mx=MAXN;
ll gans=0;
inline int mul(int x, int y) {
  return (x*(ll)y)%MOD;
}
class UnionFind {
public:
    int ufParent[mx];
    int rank[mx];
    int ufData[mx][3];
    void init(int n) {
      for (int x=0;x<n;x++) {
        ufParent[x]=x;
        rank[x]=0;
      }
    }
    int ffind(int x) {
      if (ufParent[x] != x) {
        ufParent[x] = ffind(ufParent[x]);
      }
      return ufParent[x];
    }
    void funion(int _x, int _y) {
      int xr = ffind(_x);
      int yr = ffind(_y);
      if (xr==yr) return;
      if (rank[xr] > rank[yr]) swap(xr,yr);
      if (rank[xr]==rank[yr]) rank[yr]++;
      ufParent[xr] = yr;
      ll sub=(1ll*ufData[xr][0]*ufData[xr][1]*ufData[xr][2]);
      sub+=(1ll*ufData[yr][0]*ufData[yr][1]*ufData[yr][2]);
      for (int k=0;k<3;k++) ufData[yr][k]+=ufData[xr][k];
      ll add=(1ll*ufData[yr][0]*ufData[yr][1]*ufData[yr][2]);
      gans=gans-sub+add;
      gans%=MOD;
      if (gans<0) gans+=MOD;
    }
};



char S[MAXN];
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
int vans[MAXN];
char vs[3][MAXN];
int vslen[3];
int vbase[3];
UnionFind uf;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n%s\n",&vs[0],&vs[1],&vs[2]);
  for (int k=0;k<3;k++) vslen[k]=strlen(vs[k]);
  int slen=0;
  for (int k=0;k<3;k++) {
    vbase[k]=slen;
    for (int i=0;i<vslen[k];i++) {
      S[slen++]=vs[k][i];
    }
    S[slen++]='z'+k+1;
  }
  buildSA(slen);
  buildREVSA();
  buildLCP();

  /*for (int i=0;i<slen;i++) {
    printf("%c ",S[i]);
  }
  printf(" end S\n");
  for (int i=0;i<slen;i++) {
    int pp=sa[i];
    for (int j=pp;j<slen;j++) printf("%c",S[j]);
    printf(" end SA %d pos:%d\n",i,pp);
  }*/

  for (int i=0;i<slen;i++) {
    vlen2lcp[lcp[i]].PB(i);
  }
  uf.init(slen);
  for (int k=0;k<3;k++) {
    for (int i=0;i<vslen[k];i++) {
      int x=i+vbase[k];
      int saidx=revsa[x];
      //printf("x:%d saidx:%d set to ONE\n",x,saidx);
      uf.ufData[saidx][k]++;
    }
  }
  int ttn=max(vslen[0],max(vslen[1],vslen[2]));
  for (int len=MAXN-1;len>=1;len--) {
    for (auto &saidx:vlen2lcp[len]) {
      uf.funion(saidx,saidx+1);
      //printf("len:%d Merge %d %d. gans:%d\n",len,saidx,saidx+1,gans);
    }
    //printf("len:%d gans:%d\n",len,gans);
    vans[len]=gans;
  }
  int qn=min(vslen[0],min(vslen[1],vslen[2]));
  for (int qi=1;qi<=qn;qi++) {
    printf("%d ",vans[qi]);
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
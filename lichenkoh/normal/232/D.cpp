#include "bits/stdc++.h"
#include <assert.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
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

const int MAXSZ=(128)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 3) & ~0x03;
  //preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}

const int MAXN = 2e5+2;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
const int mx=MAXN;
typedef ordered_set UFTYPE;
class UnionFind {
public:
    int ufParent[mx];
    UFTYPE ufData[mx];
    void init(int n) {
      for (int x=0;x<n;x++) {
        ufParent[x]=x;
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
      if (ufData[xr].size()>ufData[yr].size()) swap(xr,yr);
      ufParent[xr] = yr;
      for (auto &w:ufData[xr]) ufData[yr].insert(w);
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
int vl[mc];
int h[mc];
int d[mc];
vector<int> qlen2qi[MAXN];
int vans[mc];
UnionFind uf;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    h[i]=rint();
  }
  for (int i=0;i<n-1;i++) {
    S[i]=h[i+1]-h[i];
  }
  S[n-1]=(1000*1000*1000)+1;
  for (int i=0;i<n-1;i++) {
    S[i+n]=-(h[i+1]-h[i]);
  }
  int slen=(2*n)-1;
  buildSA(slen);
  buildREVSA();
  buildLCP();

  /*for (int i=0;i<slen;i++) {
    printf("%d ",S[i]);
  }
  printf(" end S\n");*/
  /*for (int i=0;i<slen;i++) {
    int pp=sa[i];
    for (int j=pp;j<slen;j++) printf("%d ",S[j]);
    printf(" end SA %d pos:%d\n",i,pp);
  }*/

  for (int i=0;i<slen;i++) {
    vlen2lcp[lcp[i]].PB(i);
  }
  uf.init(slen);
  for (int x=0;x<n-1;x++) {
    int saidx=revsa[x];
    //printf("x:%d saidx:%d set to ONE\n",x,saidx);
    uf.ufData[saidx].insert(x);
  }
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
    int l=rint()-1,r=rint()-1;
    vl[qi]=l;
    int qlen=r-l;
    if (qlen>0) qlen2qi[qlen].PB(qi);
    else vans[qi]=n-1;
  }
  for (int len=MAXN-1;len>=1;len--) {
    for (auto &saidx:vlen2lcp[len]) {
      uf.funion(saidx,saidx+1);
      //printf("len:%d Merge %d %d\n",len,saidx,saidx+1);
    }
    for (auto &qi: qlen2qi[len]) {
      int l=vl[qi];
      int saidx=revsa[l+n];
      int ufid=uf.ffind(saidx);
      int ans=uf.ufData[ufid].size();
      int lower=l-len;
      int lo=uf.ufData[ufid].order_of_key(lower);
      int upper=l+len+1;
      int up=uf.ufData[ufid].order_of_key(upper);
      int avoid=up-lo;
      ans-=avoid;
      vans[qi]=ans;
      /*printf("l:%d saidx:%d ufid:%d ans:%d lower:%d lo:%d upper:%d up:%d\n"
              ,l,saidx,ufid,ans,lower,lo,upper,up);*/
    }
  }
  for (int qi=0;qi<qn;qi++) {
    printf("%d\n",vans[qi]);
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
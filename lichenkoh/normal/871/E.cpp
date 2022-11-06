#include <bits/stdc++.h>
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
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int MAXSZ=180*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 7) & ~0x07;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
int rint();char rch();long long rlong();
void fail() {
  printf("-1\n"); exit(0);
}
const int mk=200,mn=30000;
vector<int> gans[mn];
int vbfsdist[mn];
void bfs(int n, int init) {
  for (int x=0;x<n;x++) vbfsdist[x]=INF;
  vbfsdist[init]=0;
  queue<int> q;
  q.push(init);
  while(!q.empty()) {
    int x=q.front(); q.pop();
    int cand=vbfsdist[x]+1;
    for (auto &y:gans[x]) {
      if (cand<vbfsdist[y]) {
        vbfsdist[y]=cand;
        q.push(y);
      }
    }
  }
}

void ae(int x, int y) {
  gans[x].PB(y); gans[y].PB(x);
}
int vinp[mk][mn];
int vd[mn][mk];
vector<int> d2v[mn];
typedef vector<short> tkey;
typedef short tval;
vector<pair<tkey, tval> > h[2];
int vlo[2][mn];

int perm[mn];
int iperm[mn];
bitset<mn> specced;

tval bins(vector<pair<tkey, tval> > &v, tkey &key) {
  int sz=v.size(); int imin=0,imax=sz;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid].fst<key) imin=imid+1;
    else imax=imid;
  }
  if (imin==sz) return -1;
  return v[imin].snd;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(), k=rint();
  for (int i=0;i<k;i++) {
    int x=-1;
    for (int j=0;j<n;j++) {
      int got=rint();
      vinp[i][j]=got;
      if (got==0) x=j;
    }
    if (x==-1) fail();
    perm[x]=i;
    iperm[i]=x;
    specced[x]=true;
  }
  {
    int idx=k;
    for (int x = 0; x < n; x++) {
      if (!specced[x]) {
        iperm[idx]=x;
        perm[x]=idx;
        idx++;
      }
    }
  }
  for (int x=0;x<k;x++) {
    for (int y=0;y<n;y++) {
      vd[perm[y]][x]=vinp[x][y];
    }
  }
  int kk=k-1;
  for (int x=0;x<n;x++) {
    d2v[vd[x][kk]].PB(x);
  }
  int cur=0,nxt=1;
  {
    vector<short> sig; sig.resize(kk);
    for (int t=0;t<kk;t++) {
      sig[t]=vlo[cur][t]=vd[kk][t];
    }
    h[cur].PB(MP(sig,kk));
  }
  for (int d=1;d<n;d++) {
    memcpy(vlo[nxt],vlo[cur],sizeof vlo[cur]);
    h[nxt].clear();
    h[nxt].reserve(d2v[d].size());
    sort(h[cur].begin(),h[cur].end());
    for (auto &x:d2v[d]) {
      vector<short> sig; sig.resize(kk);
      vector<short> wsig; wsig.resize(kk);
      vector<short> nsig; nsig.resize(kk);
      for (int t = 0; t < kk; t++) {
        int got = vd[x][t], lo = vlo[cur][t];
        sig[t]=got;
        nsig[t]=got-1;
        if (got < lo) {
          chkmin(vlo[nxt][t], got);
          wsig[t]=got+1;
        }
        else wsig[t]=got-1;
      }
      h[nxt].PB(MP(sig,x));
      short parent=bins(h[cur], wsig);
      if (parent==-1) {
        parent=bins(h[cur],nsig);
        if (parent==-1) fail();
      }
      //printf("d:%d x:%d parent:%d\n",d,x,parent);
      ae(parent,x);
    }
    swap(cur,nxt);
  }
  for (int t=0;t<k;t++) {
    bfs(n,t);
    for (int y=0;y<n;y++) {
      if (vbfsdist[y]!=vd[y][t]) {
        fail();
      }
    }
  }
  for (int x=0;x<n;x++) {
    for (auto &y:gans[x]) {
      if (x<y) printf("%d %d\n",iperm[x]+1,iperm[y]+1);
    }
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
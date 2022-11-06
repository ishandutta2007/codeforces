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
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=1e5+4;
const int MAXN=mn;
int fenwick_t[mn];
// T[i] += value
void fenwick_add(int i, int value) {
  for (; i < MAXN; i |= i + 1)
    fenwick_t[i] += value;
}

  // sum[0..i]
int fenwick_sum(int i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += fenwick_t[i];
  return res;
}

int col2numvtx[mn];
int st[mn],ft[mn],ver[mn],big[mn],sz[mn];
int vfinal[mn];
int v2col[mn];
vector<pii> v2queries[mn];
vector<int> g[mn];
void add(int v, int toadd) {
  int col=v2col[v];
  int oldcnt=col2numvtx[col];
  col2numvtx[col]+=toadd;
  int newcnt=col2numvtx[col];
  fenwick_add(mn-1-oldcnt,-1);
  fenwick_add(mn-1-newcnt,1);
  //printf("v:%d col:%d toadd:%d\n",v,col,toadd);
}
void handlequery(int v) {
  for (auto &query:v2queries[v]) {
    int idx=query.fst,k=query.snd;
    int ans=fenwick_sum(mn-1-k);
    vfinal[idx]=ans;
    //printf("v:%d idx:%d ans:%d\n",v,idx,ans);
  }
}
void dfs(int v, int p, bool keep){
    /*int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;*/
  int bigChild=big[v];
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
    for(auto u : g[v])
  if(u != p && u != bigChild)
    for(int p = st[u]; p < ft[u]; p++) add(ver[p],1);
    add(v,1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    handlequery(v);
    if(keep == 0)
        for(int p = st[v]; p < ft[v]; p++) add(ver[p],-1);
}
int dfs_time=0;
void pre_dfs(int v, int p){
  st[v] = dfs_time++;
  ver[ st[v] ] = v;
  sz[v] = 1, big[v] = -1;
  for(auto u : g[v]){
    if (u==p) continue;
    pre_dfs(u,v);
    sz[v] += sz[u];
    if(big[v] == -1 || sz[u] > sz[ big[v] ])
        big[v] = u;
  }
  ft[v] = dfs_time;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),m=readInt();
  for (int i=1;i<=n;i++) v2col[i]=readInt();
  for (int i=1;i<n;i++) {
    int a=readInt(),b=readInt();
    g[a].PB(b);
    g[b].PB(a);
  }	
  for (int i=0;i<m;i++) {
    int v=readInt(),k=readInt();
    v2queries[v].PB(MP(i,k));
  }
  pre_dfs(1,-1);
  dfs(1,-1,true);
  for (int i=0;i<m;i++) printf("%d\n",vfinal[i]);
}
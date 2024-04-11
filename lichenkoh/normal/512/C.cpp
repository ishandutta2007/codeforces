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

const int MAXN=2e4+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = sqrt(MAXP)+1;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
      }
    }
  }
}

  // Hopcroft Karp Bipartite Matching
  const int MAX_N = 202, MAX_M = 202;
  int karp_n, karp_m;
  vector<int> graph[MAX_N];
  int match[MAX_N];

  int matched[MAX_M], depth[MAX_N], q[MAX_N];
  int v[MAX_N], vcnt;
  bool BFS(){
    int t = 0;
    for(int i = 0; i < karp_n; i++)
      if (match[i] == -1) depth[i] = 0, q[t++] = i;
      else depth[i] = -1;
    for(int h = 0; h < t; h++) {
      int cur = q[h];
      int curDepth = depth[cur];
      for(int i = 0; i < graph[cur].size(); i++) {
        int adj = graph[cur][i];
        if (matched[adj] == -1)
          return true;
        int next = matched[adj];
        if (depth[next] != -1) continue;
        depth[next] = curDepth + 1, q[t++] = next;
      }
    }
    return false;
  }

  bool DFS(int nod) {
    v[nod] = vcnt;
    for(int i = 0; i < graph[nod].size(); i++) {
      int adj = graph[nod][i];
      int next = matched[adj];
      if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
        continue;
      if (next == -1 || DFS(next)) {
        match[nod] = adj;
        matched[adj] = nod;
        return true;
      }
    }
    return false;
  }

  int Match(int leftPartiteSize, int rightPartiteSize)
  {
    karp_n=leftPartiteSize;
    karp_m=rightPartiteSize;
    memset(match, -1, sizeof(match));
    memset(matched, -1, sizeof(matched));
    vcnt=0;
    memset(depth,0,sizeof depth);
    memset(q,0,sizeof q);
    memset(v,0,sizeof v);
    int ans = 0;
    while(BFS()) {
      ++vcnt;
      for(int i = 0; i < karp_n; i++) if (depth[i] == 0 && DFS(i)) ans++;
    }
    return ans;
  }

  void resetKarp() {
    for (int x=0;x<karp_n;x++) {
      graph[x].clear();
    }
  }


const int maxn=202;
bitset<maxn> orig[maxn];
int n,a[maxn];
int nxt[maxn];
bitset<maxn> seen;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
	n=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  {
    int kn=0,km=0;
    for (int x=0;x<n;x++) {
      if (a[x]%2==0) kn++;
      else km++;
    }
    if (kn!=km||n%2!=0) {printf("Impossible\n"); return 0;}
  }
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    if (a[x]%2==0&&a[y]%2!=0&&sieve_array[a[x]+a[y]]) {
      orig[x][y]=1;
      //printf("%d->%d\n",x,y);
      graph[x].PB(y);
    }
  }
  {
    int flow=Match(n,n);
    //printf("flow:%d\n",flow);
    if (flow!=n/2) {printf("Impossible\n"); return 0;}
  }
  //memcpy(nxt,match,sizeof(match));
  for (int x=0;x<n;x++) {
    if (match[x]!=-1) {
      nxt[x]=match[x];
      //printf("x:%d->%d\n",x,match[x]);
    }
  }
  resetKarp();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    if (orig[x][y]&&match[x]!=y) {
      //printf("%d->%d\n",x,y);
      graph[x].PB(y);
    }
  }
  {
    int flow=Match(n,n);
    //printf("flow2:%d\n",flow);
    if (flow!=n/2) {printf("Impossible\n"); return 0;}
  }
  for (int y=0;y<n;y++) {
    if (matched[y]!=-1) {
      nxt[y]=matched[y];
      //printf("y:%d->%d\n",y,matched[y]);
    }
  }
  vector<vector<int> > vans;
  for (int x=0;x<n;x++) {
    if (seen[x]) continue;
    vector<int> tmp; tmp.PB(x);
    seen[x]=1;
    int y=nxt[x];
    while (y!=x) {
      //printf("x:%d y:%d nxt[y]:%d\n",x,y,nxt[y]);
      tmp.PB(y);
      seen[y]=1;
      y=nxt[y];
    }
    vans.PB(tmp);
  }
  printf("%d\n",(int)vans.size());
  for (auto &tmp:vans) {
    printf("%d ",(int)tmp.size());
    for (auto &w:tmp) printf("%d ",w+1);
    printf("\n");
  }
}
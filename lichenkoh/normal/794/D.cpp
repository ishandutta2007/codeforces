#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD1=1000000009LL;
const ll MOD2=1500450271LL;
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
const int mn=3e5+2;
vector<int> g[mn];
ll vhash[mn];
int vid[mn];
set<int> usedid;
map<ll,int> hash2id;
const ll K1=100000007LL;
const ll K2=1234561LL;
bool ok=true;
void dfs(int x) {
  //printf("x:%d vid:%d\n",x,vid[x]);
  for (auto &y:g[x]) {
    if (vid[y]!=-1) {
      if (abs(vid[y]-vid[x])>1) {ok=false; return;}
    }
    else {
      auto it=hash2id.find(vhash[y]);
      if (it!=hash2id.end()) {
        vid[y]=it->snd;
      }
      else {
        for (int nid=vid[x]-1;nid<=vid[x]+1;nid+=2) {
          if (usedid.find(nid)==usedid.end()) {
            vid[y]=nid;
            break;
          }
        }
        if (vid[y]==-1) {ok=false; return;}
        hash2id[vhash[y]]=vid[y];
        usedid.insert(vid[y]);
      }
      dfs(y);
    }
  }
}

void check(int n) {
  if (n>1000) return;
  bitset<1002>adj[1002];
  for (int x=1;x<=n;x++) adj[x].reset();
  for (int x=1;x<=n;x++) {
    for (auto &y:g[x]) adj[x][y]=true;
  }
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=n;y++) {
      if (adj[x][y]) assert(abs(vid[x]-vid[y])<=1);
      else assert(abs(vid[x]-vid[y])>1);
    }
  }
  for (int x=1;x<=n;x++) assert(vid[x]!=-1);//assert(1<=vid[x]&&vid[x]<=1000000000);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  for (int i=0;i<m;i++) {
    int u=readInt(),v=readInt();
    g[u].PB(v); g[v].PB(u);
  }
  for (int x=1;x<=n;x++) {
    g[x].PB(x);
    sort(g[x].begin(),g[x].end());
    ll hash1=0,hash2=0;
    for (auto &w:g[x]) {
      hash1=((ll)hash1*(ll)K1+w)%MOD1;
      hash2=((ll)hash2*(ll)K2+w)%MOD2;
    }
    vhash[x]=(hash2<<31)|hash1;
  }
  memset(vid,-1,sizeof vid);
  int sid=mn;
  {
    int x=1;
    usedid.insert(sid);
    hash2id[vhash[x]]=sid;
    vid[x]=sid;
    dfs(x);
  }
  if (!ok) {
    printf("NO\n");
    //assert(0);
  }
  else {
    printf("YES\n");
    for (int x=1;x<=n;x++) printf("%d ",vid[x]);
    printf("\n");
    check(n);
  }
}
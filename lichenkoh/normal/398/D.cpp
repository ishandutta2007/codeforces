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
const int mn=50001;
const int mq=250000+1;
//const int slim=4;
set<int> bg[mn];
unordered_set<int> ag[mn];
bool von[mn];
int predeg[mn];
bool big[mn];
int vc[mn];
char vt[mq];
int vu[mq],vv[mq];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),q=readInt();
  int o=readInt();
  for (int i=0;i<o;i++) {
    int x=readInt();
    von[x]=true;
  }
  for (int i=0;i<m;i++) {
    int x=readInt(),y=readInt();
    ag[x].insert(y); ag[y].insert(x);
    predeg[x]++;predeg[y]++;
  }
  for (int i=0;i<q;i++) {
    char t=readCh(); int u=readInt();
    vt[i]=t; vu[i]=u;
    if (t=='A'||t=='D') {
      int v=readInt();
      vv[i]=v;
      if (t=='A') {
        predeg[u]++;
        predeg[v]++;
      }
    }
  }
  int slim=0;
  for (int x=1;x<=n;x++) slim+=predeg[x];
  slim=round(sqrt(slim));
  for (int x=1;x<=n;x++) {
    if (predeg[x]>=slim) big[x]=true;
  }
  for (int x=1;x<=n;x++) {
    for (auto &y:ag[x]) {
      if (big[y]) {bg[x].insert(y);}
      else if (von[y]) {vc[x]++;}
    }
  }
  for (int i=0;i<q;i++) {
    char t=vt[i]; int u=vu[i],v=vv[i];
    if (t=='O') {
      von[u]=true;
      if (!big[u]) {
        for (auto &y:ag[u]) vc[y]++;
      }
    }
    else if (t=='F') {
      von[u]=false;
      if (!big[u]) {
        for (auto &y:ag[u]) vc[y]--;
      }
    }
    else if (t=='A') {
      ag[u].insert(v);
      ag[v].insert(u);
      if (big[u]) bg[v].insert(u); else if (von[u]) vc[v]++;
      if (big[v]) bg[u].insert(v); else if (von[v]) vc[u]++;
    }
    else if (t=='D') {
      ag[u].erase(v);
      ag[v].erase(u);
      if (big[u]) bg[v].erase(u); else if (von[u]) vc[v]--;
      if (big[v]) bg[u].erase(v); else if (von[v]) vc[u]--;
    }
    else {
      assert(t=='C');
      int ans=vc[u];
      //printf("u:%d ans:%d\n",u,ans);
      for (auto &y:bg[u]) {
        ans+=von[y];
        //printf("u:%d y:%d von:%d\n",u,y,von[y]);
      }
      printf("%d\n",ans);
    }

  }
}
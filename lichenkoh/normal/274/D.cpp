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
const int mn=200010;
int gid=mn;
vector<int> g[2*mn];
int indeg[2*mn];
int *a[mn];
void ae(int x, int y) {
  //printf("ae %d %d\n",x,y);
  indeg[y]++;
  g[x].PB(y);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  for (int x=0;x<n;x++) {
    a[x]=new int[m];
    for (int y=0;y<m;y++) a[x][y]=rint();
  }
  for (int r=0;r<n;r++) {
    vector<pii> v;
    for (int x=0;x<m;x++) {
      int val=a[r][x];
      if (val==-1) continue;
      v.PB(MP(val,x));
    }
    sort(v.begin(),v.end());
    int prevleave=-1;
    int entry,leave;
    int vsz=v.size();
    for (int x=0;x<vsz;x++) {
      if (x==0||v[x].fst!=v[x-1].fst) {
        entry=++gid;
        leave=++gid;
        if (prevleave!=-1) ae(prevleave,entry);
        prevleave=leave;
      }
      int col=v[x].snd;
      //printf("r:%d col:%d entry:%d leave:%d\n",r,col,entry,leave);
      ae(entry,col);
      ae(col,leave);
    }
  }
  queue<int> q;
  for (int x=0;x<2*mn;x++) {
    if (indeg[x]==0&&g[x].size()>0) {
      //printf("initp:%d\n",x);
      q.push(x);
    }
  }
  vector<int> vans;
  for (int y=0;y<m;y++) {
    bool ok=1;
    for (int x=0;x<n;x++) {
      if (a[x][y]!=-1) {ok=0; break;}
    }
    if (ok) vans.PB(y);
  }
  while(!q.empty()) {
    int x=q.front(); q.pop();
    //printf("BFS:%d\n",x);
    if (x<mn) vans.PB(x);
    for (auto &y:g[x]) {
      indeg[y]--;
      if (indeg[y]==0) {
        q.push(y);
      }
    }
  }
  if (vans.size()==m) {
    for (auto &w:vans) printf("%d ",w+1);
    printf("\n");
  }
  else printf("-1\n");
}
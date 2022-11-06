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
const ll INF=2e15;
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
const int mn=2004;
int a[mn][mn];
int leastEdge[mn];
int n;
ll dist[mn];
priority_queue<pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt();
  int s=2e9;
  for (int i=0;i<n;i++) {
    for (int j=1;j<n-i;j++) {
      int x=readInt();
      a[i][i+j]=x;
      a[i+j][i]=x;
      chkmin(s,x);
    }
  }
  for (int x=0;x<n;x++) {
    int le=2e9;
    for (int y=0;y<n;y++) {
      if (x!=y) chkmin(le,a[x][y]);
    }
    leastEdge[x]=le;
  }
  for (int x=0;x<n;x++) dist[x]=INF;
  ll newdist=(ll)s*(ll)(n-1);
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      if (a[x][y]==s) {
        if (newdist<dist[x]) {
          dist[x]=newdist;
          pq.push(MP(newdist,x));
        }
        if (newdist<dist[y]) {
          dist[y]=newdist;
          pq.push(MP(newdist,y));
        }
      }
    }
  }
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    ll odist=got.fst;
    int x=got.snd;
    if (odist>dist[x]) continue;
    for (int y=0;y<n;y++) {
      if (x==y) continue;
      ll newdist1=odist+a[x][y]-s;
      ll newdist2=odist+2*(leastEdge[y]-s);
      ll newdist=min(newdist1,newdist2);
      if (newdist<dist[y]) {
        dist[y]=newdist;
        pq.push(MP(newdist,y));
      }
    }
  }
  for (int x=0;x<n;x++) printf("%lld\n",dist[x]);
}
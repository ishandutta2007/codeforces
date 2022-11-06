#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
const int MAXN=555;
int cost[MAXN][MAXN][4];
ll f[2][MAXN][MAXN];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m,k; cin>>n>>m>>k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m-1;j++) {
      int x; cin>>x;
      x*=2;
      cost[i][j][1]=x;
      cost[i][j+1][3]=x;
    }
  }
  for (int i=0;i<n-1;i++) {
    for (int j=0;j<m;j++) {
      int x; cin>>x;
      x*=2;
      cost[i][j][0]=x;
      cost[i+1][j][2]=x;
    }
  }
  if (k%2) {
    for (int r=0;r<n;r++) {
      for (int c=0;c<m;c++) printf("-1 ");
      printf("\n");
    }
    exit(0);
  }
  int cur=0,nxt=1;
  for (int t=0;t<(k/2);t++) {
    for (int r=0;r<n;r++) {
      for (int c=0;c<m;c++) {
        ll ans=LLONG_MAX/4;
        for (int d=0;d<4;d++) {
          int nr=r+dr[d],nc=c+dc[d];
          if (0<=nr&&nr<n && 0<=nc&&nc<m) {
            chkmin(ans, f[cur][nr][nc]+cost[r][c][d]);
          }
        }
        f[nxt][r][c]=ans;
      }
    }
    swap(cur,nxt);
  }
  for (int r=0;r<n;r++) {
    for (int c=0;c<m;c++) {
      ll ans=f[cur][r][c];
      if (ans>=LLONG_MAX/4) ans=-1;
      printf("%lld ",ans);
    }
    printf("\n");
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
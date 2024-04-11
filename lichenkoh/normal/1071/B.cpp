#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
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

template<typename T> int bins(vector<T> &v, T key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

const int mn=2004;
int f[mn][mn];
int dp[mn][mn];
string a[mn];
int g(int x, int y) {
  if (x<0||y<0) return INF;
  if(dp[x][y]!=-1) return dp[x][y];
  int ans=min(g(x-1,y),g(x,y-1));
  if (a[x][y]!='a') ans++;
  return dp[x][y]=ans;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,k; cin>>n>>k;
  for (int x=0;x<n;x++) cin>>a[x];
  memset(dp,-1,sizeof dp);
  dp[0][0]=(a[0][0]=='a')?0:1;
  

  for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) f[x][y]=INF;
  f[n-1][n-1]=0;
  for (int d=2*n-3;d>=0;d--) {
    vector<pair<char,int> > v;
    for (int x=max(0,d-(n-1));x<=min(n-1,d);x++) {
      int y=d-x;
      v.PB(MP(a[x][y],min(f[x+1][y],f[x][y+1])));
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(it-v.begin());
    for (int x=max(0,d-(n-1));x<=min(n-1,d);x++) {
      int y=d-x;
      f[x][y]=bins(v,MP(a[x][y],min(f[x+1][y],f[x][y+1])));
      //printf("x:%d y:%d f:%d\n",x,y,f[x][y]);
    }
  }
  vector<char> final;
  {
    vector<char> s;
    int x=0,y=0;
    s.PB(a[x][y]);
    while(x+y<2*n-2) {
      if (f[x+1][y]<f[x][y+1]) {
        x++;
      }
      else {
        y++;
      }
      s.PB(a[x][y]);
    }
    final=s;
  }
  for (int d=2*n-2;d>=0;d--) {
    pii best=MP(INF,INF);
    for (int x=max(0,d-(n-1));x<=min(n-1,d);x++) {
      int y=d-x;
      if (g(x,y)<=k) chkmin(best,MP(min(f[x][y+1],f[x+1][y]),x));
    }
    int x=best.snd;
    if (x!=INF) {
      vector<char> s;
      for (int i=0;i<=d;i++) s.PB('a');
      int y=d-x;
    //printf("Cons x:%d y:%d\n",x,y);
      while(x+y<2*n-2) {
        if (f[x+1][y]<f[x][y+1]) {
          x++;
        }
        else {
          y++;
        }
        s.PB(a[x][y]);
      }
      chkmin(final,s);
    }
  }
  for (auto &w:final) printf("%c",w);
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
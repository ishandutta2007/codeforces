#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int mn=5004;
ll vt[mn],vx[mn];
ll f[mn][mn];
int n;
void go(int a, int dest, ll nowtime, ll clonetime) {
  chkmin(f[dest][n],max(clonetime,nowtime+abs(vx[a]-vx[dest])));
  for (int b=dest+1;b<n;b++) {
    chkmin(f[dest][b], max(vt[dest],max(nowtime+abs(vx[b]-vx[a]), clonetime) + abs(vx[dest]-vx[b])));
  }
}
void solve() {
  for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) f[x][y]=INF;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>vt[i]>>vx[i];
  n++;
  f[0][n]=0;
  for (int a=0;a<n-1;a++) {
    if (f[a][n]<=vt[a]) {
      int dest=a+1;
      ll nowtime=f[a][n];
      ll clonetime=vt[a];
      go(a,dest,nowtime,clonetime);
    }
    for (int b=a+2;b<n;b++) {
      if (f[a][b]<=vt[a]) {
        int dest=a+1;
        chkmin(f[a+1][b], max(vt[a+1], vt[a]+abs(vx[a]-vx[dest])));
      }
    }
    if (f[a][a+1]<=vt[a]) {
      int dest=a+2;
      ll nowtime=vt[a];
      ll clonetime=vt[a+1];
      go(a,dest,nowtime,clonetime);
    }
  }
  bool final=0;
  for (int b=0;b<=n;b++) if (f[n-1][b]<=vt[n-1]) final=1;
  if (f[n-2][n-1]<=vt[n-2]) final=1;
  if(final) printf("YES\n");
  else printf("NO\n");

}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //int t; cin>>t; for (int i=0;i<t;i++)
  solve();
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
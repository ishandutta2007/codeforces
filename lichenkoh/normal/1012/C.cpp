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


const int mn=5000+2;
int f[2][3][mn];
int bins(vi &v, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
const int LIM=(1e5*5000)+100;
const int NO=0,UP=1,DOWN=2;
int a[mn];
void rst(int q) {
  for (int t=0;t<3;t++) for (int x=0;x<mn;x++) f[q][t][x]=LIM;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); for (int i=0;i<n;i++) a[i]=rint();
  int klim=(n+1)/2;
  int cur=0,nxt=1;
  rst(cur);
  f[cur][NO][0]=0;
  f[cur][UP][0]=0;
  for (int p=0;p<n-1;p++) {
    rst(nxt);
    // Any -> NO costs 0
    for (int s=0;s<3;s++) for (int k=0;k<=klim;k++) chkmin(f[nxt][NO][k],f[cur][s][k]);
    { // NO->UP must decrease p to a[p+1]-1
      int cost=max(0,a[p]-(a[p+1]-1));
      for (int k=0;k<=klim;k++) {
        chkmin(f[nxt][UP][k],f[cur][NO][k]+cost);
      }
    }
    if (p-1>=0) { // DOWN->UP must decrease p to a[p+1]-1
      int cost=max(0,(a[p-1]-1)-(a[p+1]-1));
      for (int k=0;k<=klim;k++) {
        chkmin(f[nxt][UP][k],f[cur][DOWN][k]+cost);
      }
    }
    { // UP->DOWN
      int cost=max(0,a[p+1]-(a[p]-1)); // Decrease p+1 to a[p]-1
      for (int k=0;k<=klim;k++) {
        chkmin(f[nxt][DOWN][k+1],f[cur][UP][k]+cost);
      }
    }
    if (a[p+1]<a[p]) { // UP->NO costs 0 if already satisfied
      for (int k=0;k<=klim;k++) {
        chkmin(f[nxt][NO][k+1],f[cur][UP][k]);
      }
    }
    swap(cur,nxt);
  }
  for (int k=1;k<=klim;k++) {
    int ans=INT_MAX; for (int t=0;t<3;t++) chkmin(ans,f[cur][t][k]);
    chkmin(ans, f[cur][UP][k-1]);
    printf("%d ",ans);
  }
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
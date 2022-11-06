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
const int mt=1<<12;
const int mn=(3e4)+4;;
const int m3=531441+50;
int w,n,m;
int a[mn];
int c[mt];
int z2p[m3+50];

int g[256];
int f[256][2];
void init() {
  for (int x=0;x<2;x++) for (int y=0;y<2;y++) {
    if (x==0&&y==1) continue;
    int ones=x+y;
    if (x&y) f['a'][g['a']++]=ones;
    else f['A'][g['A']++]=ones;
  }
  for (int x=0;x<2;x++) for (int y=0;y<2;y++) {
    if (x==0&&y==1) continue;
    int ones=x+y;
    if (x|y) f['o'][g['o']++]=ones;
    else f['O'][g['O']++]=ones;
  }
  for (int x=0;x<2;x++) for (int y=0;y<2;y++) {
    if (x==0&&y==1) continue;
    int ones=x+y;
    if (x^y) f['x'][g['x']++]=ones;
    else f['X'][g['X']++]=ones;
  }
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  cin>>w>>n>>m;
  for (int i=0;i<n;i++) {int x; cin>>x; c[x]++;}
  int tlim=1<<w;
  for (int x=0;x<tlim;x++) for (int y=0;y<tlim;y++) {
    //int x=a[i],y=a[j];
    int z=0;
    for (int k=0;k<w;k++) {
      z*=3;
      int ones=((x>>k)&1)+((y>>k)&1);
      z+=ones;
    }
    z2p[z]+=c[x]*c[y];
  }
  for (int i=0;i<m;i++) {
    string s; cin>>s; reverse(s.begin(),s.end());
    int final=0;
    for (int t=0;t<(1<<w);t++) {
      int z=0;
      for (int k=0;k<w;k++) {
        z*=3;
        int idx=((t>>k)&1);
        if (idx >= g[s[k]]) {z=-1; break;}
        z+=f[s[k]][idx];
      }
      if (z!=-1) final+=z2p[z];
    }
    printf("%d\n",final);
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
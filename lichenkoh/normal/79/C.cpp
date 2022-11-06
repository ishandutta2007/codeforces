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
const int INF=1e8;
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

string s,a[20];
const int mn=2e5;
int badstart[mn];
int badend[mn];
int lastend[mn];
const int LIM=10+1;
//const int LIM=3;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>s;
  int k; cin>>k;
  for (int i=0;i<k;i++) cin>>a[i];
  int n=s.length();
  for (int x=0;x<mn;x++) {
    badstart[x]=INF;
    badend[x]=-INF;
    lastend[x]=n;
  }
  for (int t=0;t<k;t++) {
    int tlen=a[t].length();
    for (int x=0;x<n-tlen+1;x++) {
      //printf("%s %s\n",s.substr(x,tlen).c_str(),a[t].c_str());
      if (s.substr(x,tlen)==a[t]) {
        chkmin(badstart[x],x+tlen-1);
        chkmax(badend[x+tlen-1],x);
        chkmin(lastend[x],x+tlen-1);
      }
    }
  }
  for (int x=n-2;x>=0;x--) {
    chkmin(lastend[x],lastend[x+1]);
  }
  pii final=MP(-INF,-INF);
  for (int x=0;x<n;x++) {
    int ans=0;
    int ylim=min(x+LIM,n-1);
    for (int y=x;y<=ylim;y++) {
      //printf("x:%d badstart[x]:%d y:%d badend[y]:%d\n",x,badstart[x],y,badend[y]);
      if (badstart[x]<=y||badend[y]>=x) {
        break;
      }
      else {
        //printf("x:%d y:%d %s\n",x,y,s.substr(x,y-x+1).c_str());
        chkmax(ans,y-x+1);
      }
    }
    //if (x==2) printf("x:%d bs:%d lastend:%d\n",x,badstart[x],lastend[x]);
    if (badstart[x]==INF&&lastend[x]>=ylim+1) {
      chkmax(ans,lastend[x]-x);
    }
    chkmax(final,MP(ans,x));
  }
  printf("%d %d\n",final.fst,final.snd);
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
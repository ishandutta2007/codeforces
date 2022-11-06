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
const int mn=1e5+4;
int sum[3][mn];

int queryzeros(int l, int r, bool sw) {
  int t=0; if (sw) t=1;
  return sum[t][r+1]-sum[t][l];
}

int query(int l, int r, int zeros, int ones, bool sw) {
  if (sw) swap(zeros,ones);
  int havezeros=sum[0][r+1]-sum[0][l];
  int haveones=sum[1][r+1]-sum[1][l];
  int q=sum[2][r+1]-sum[2][l];
  int needzeros=zeros-havezeros;
  int needones=ones-haveones;
  //if (sw&&l==0&&r==1&&zeros==2&&ones==0)printf("havezeros:%d zeros:%d\n",havezeros,zeros);
  return (needzeros>=0 && needones>=0 && needzeros+needones==q);
}

bool ask01(int n, bool sw) {
  int a=(n-2+1)/2,b=(n-2)/2;
  if (sw) swap(a,b);
  if (query(n-1,n-1,0,1,sw)) {
    for (int x=0;x<n-1;x++) { // x is pos of last 0
      int tail1=n-2-x;
      //if(!sw) printf("x:%d b:%d a:%d tail1:%d\n",x,b,a,tail1);
      if (
        query(x,x,1,0,sw) &&
        query(0,x-1,b,a-tail1,sw) &&
        query(x+1,n-2,0,tail1,sw)
        ) return true;
    }
  }
  return false;
}
vector<int> ov;
bool ask11(int n, int sw) {
  int a=(n-2+1)/2,b=(n-2)/2;
  if (sw) swap(a,b);
  if (queryzeros(0,n-1,sw)<=b) return true;
  /*for (int x=0;x<=n-2;x++) {
    if (sw) printf("x:%d got:%d\n",x,query(x,x+1,0,2,sw));
    if (query(x,x+1,0,2,sw)) {
      int zeros=queryzeros(0,x-1,sw)+queryzeros(x+2,n-1,sw);
      if (sw) printf("x:%d zeros:%d b:%d\n",x,zeros,b);
      if (zeros<=b) return true;
    }
  }*/
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string os; cin>>os;
  int n=os.length();
  for (auto &w:os) {
    if (w=='?') ov.PB(2);
    else ov.PB(w-'0');
  }
  for (int t=0;t<3;t++) {
    for (int x=1;x<=n;x++) {
      sum[t][x]=sum[t][x-1]+((ov[x-1]==t)?1:0);
    }
  }
  if (ask11(n,true)) printf("00\n");
  if (ask01(n,false)) printf("01\n");
  if (ask01(n,true)) printf("10\n");
  if (ask11(n,false)) printf("11\n");
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
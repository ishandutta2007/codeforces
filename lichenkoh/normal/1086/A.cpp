#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

int a[3][2];
const int mx=1002;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int k=0;k<3;k++) {
    a[k][0]=rint();a[k][1]=rint();
  }
  pair<int,pii> final=MP(INT_MAX,MP(0,0));
  for (int x=0;x<=mx;x++) for (int y=0;y<=mx;y++) {
    int ans=0;
    for (int k=0;k<3;k++) {
      int addx=abs(x-a[k][0]);
      int addy=abs(y-a[k][1]);
      int add=addx+addy;
      ans+=add;
    }
    ans++;
    chkmin(final,MP(ans,MP(x,y)));
  }
  set<pii> s;
  int tx=final.snd.fst,ty=final.snd.snd;
  //printf("T:%d %d\n",tx,ty);
  s.insert(MP(tx,ty));
  for (int k=0;k<3;k++) {
    int x=a[k][0],y=a[k][1];
    s.insert(MP(x,y));
    while(x<tx) {x++; s.insert(MP(x,y));}
    s.insert(MP(x,y));
    while(x>tx) {x--; s.insert(MP(x,y));}
    s.insert(MP(x,y));
    while(y<ty) {y++; s.insert(MP(x,y));}
    s.insert(MP(x,y));
    while(y>ty) {y--; s.insert(MP(x,y));}
    s.insert(MP(x,y));
  }
  printf("%d\n",(int)s.size());
  for (auto &w:s) printf("%d %d\n",w.fst,w.snd);
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
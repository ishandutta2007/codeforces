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
const int mn=1e5+4;
vector<pii> val2pos[mn];
char vs[mn]; int xv[mn];
int vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,qn; cin>>n>>qn;
  for (int p=0;p<n;p++) {
    int val; cin>>val;
    val2pos[abs(val)].PB(MP(val,p));
  }
  for (int qi=0;qi<qn;qi++) {
    cin>>vs[qi]>>xv[qi];
  }
  int lim=mn-1;
  int flip=1;
  for (int qi=qn-1;qi>=0;qi--) {
    char s=vs[qi]; int opval=xv[qi];
    //printf("%c %d\n",s,opval);
    if ((s=='>'&&opval>=0)||(s=='<'&&opval<=0)) {
      for (int val=lim;val>abs(opval);val--) {
        for (auto &w:val2pos[val]) {
          int pos=w.snd,aval=w.fst;
          if (s=='>') vans[pos]=-val*flip;
          else vans[pos]=val*flip;
        }
        lim=val-1;
      }
    } else {
      for (int val=lim;val>=abs(opval);val--) {
        for (auto &w:val2pos[val]) {
          int pos=w.snd,aval=w.fst;
          if (s=='>') vans[pos]=-val*flip;
          else vans[pos]=val*flip;
          //printf("Proc: pos:%d vans:%d\n",pos,vans[pos]);
        }
        lim=val-1;
      }
      flip*=-1;
    }
  }
  for (int val=lim;val>=0;val--) {
    for (auto &w:val2pos[val]) {
      int pos=w.snd,aval=w.fst;
      //printf("val:%d pos:%d postproc\n",val,pos);
      vans[pos]=aval*flip;
    }
  }
  for (int p=0;p<n;p++) printf("%d ",vans[p]);
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
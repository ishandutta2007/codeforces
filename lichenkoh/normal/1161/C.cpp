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
/*
map<vi,bool> h;
bool f(const vi &v) {
  const int n=6;
  auto it=h.find(v);
  if (it!=h.end()) return it->snd;
  for (int a=0;a<n;a++) for (int b=0;b<a;b++) for (int c=0;c<b;c++) {
    if (v[a]>0&&v[b]>0&&v[c]>0) {
      for (int az=1;az<=v[a];az++) for (int bz=1;bz<=v[b];bz++) for (int cz=1;cz<=v[c];cz++) {
        vi nv=v; nv[a]-=az; nv[b]-=bz; nv[c]-=cz;
        if (!f(nv)) return h[v]=true;
      }
    }
  }
  return h[v]=false;
}
*/
bool smart(vi v) {
  sort(v.begin(),v.end());
  //reverse(v.begin(),v.end());
  int n=v.size();
  for (int i=0;i<n/2;i++) {
    if (v[i]!=v[i+1]) return true;
  }
  return false;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  vi v(n); for (int i=0;i<n;i++) cin>>v[i];
  if (smart(v)) printf("Alice\n");
  else printf("Bob\n");
  /*for (int a=1;a<=7;a++) for (int b=1;b<=a;b++) for (int c=1;c<=b;c++) for (int d=1;d<=c;d++) for (int e=1;e<=d;e++)
  for (int g=1;g<=e;g++) {
    vi v(6); v[0]=a;v[1]=b;v[2]=c;v[3]=d; v[4]=e; v[5]=g;
    int slow=f(v)?1:0;
    int fast=smart(v)?1:0;
    if (slow!=fast) printf("%d %d %d %d. slow: %d fast:%d\n",a,b,c,d,slow,fast);
    //if (!slow)printf("%d %d %d %d %d %d. slow: %d\n",a,b,c,d,e,g,slow);
  }*/
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
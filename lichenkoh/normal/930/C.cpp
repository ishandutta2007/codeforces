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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

vector<int> lis(vector<int> p) {
  vector<int> res;
  vector<int> v;
  for (auto &x:p) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if(v[imid]<=x) imin=imid+1;
      else imax=imid;
    }
    //for (auto &w:v) printf("%d ",w); printf(" end x:%d\n",x);
    res.PB(imin+1);
    if (imin==v.size()) v.PB(x);
    else {
      v[imin]=x;
    }
  }
  return res;
}
/*vector<int> lis(vector<int> p) {
  int n=p.size();
  for (int x=0;x<n;x++) p[x]+=x;
  return lsis(p);
}*/

int solve(vi a) {
  vi fa=a;
  vi f=lis(fa);
  vi ra=a;
  reverse(ra.begin(),ra.end());
  vi r=lis(ra);
  reverse(r.begin(),r.end());
  int ans=0;
  for (int x=0;x<a.size();x++) {
    int cand=f[x]+r[x]-1;
    chkmax(ans,cand);
  }
  //for (int x=0;x<a.size();x++) printf("%d ",f[x]); printf(" end f\n");
  //for (int x=0;x<a.size();x++) printf("%d ",r[x]); printf(" end r\n");
  return ans;
}

bool isgood(vi b) {
  int n=b.size();
    bool inc=1;
    for (int i=1;i<n;i++) {
      if (b[i-1]>b[i]) {
        inc=0;
      }
      if ((!inc)&&b[i-1]<b[i]) return false;
    }
    return true;
}

int bf(vi a) {
  int n=a.size();
  int ans=0;
  for (int z=0;z<(1<<n);z++) {
    vi b;
    for (int i=0;i<n;i++) if (z&(1<<i)) b.PB(a[i]);
      if (isgood(b)) chkmax(ans,__builtin_popcount(z));
  }
  return ans;
}
void test() {
  int seed=clock();
  //seed=6867;
  srand(seed);
  int n=rand()%10+1;
  vi a;
  for (int i=0;i<n;i++) a.PB(rand()%5);
  int smart=solve(a);
  int dumb=bf(a);
  if(smart!=dumb) {
    for (auto &w:a) printf("%d ",w); printf("\n s:%d d:%d. seed:%d\n",smart,dumb,seed);
    exit(0);
  }
}
void go() {
  for (int k=0;k<100000;k++) test();
  printf("OK\n");
}

const int mn=1e5+4;
vector<int> a;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go(); return 0;
  //vector<int> t={1,4,2,4,3};
  //vector<int> dd=lsis(t);
  //for (auto &w:dd) printf("%d ",w); printf("\n");
  //return 0;
  int segs=rint(); int n=rint();
  a.resize(n);
  for (int i=0;i<segs;i++) {
    int l=rint()-1; int r=rint()-1;
    a[l]++;
    if (r+1<n) a[r+1]--;
  }
  for (int x=1;x<=n-1;x++) a[x]+=a[x-1];
  int ans=solve(a);
  printf("%d\n",ans);
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
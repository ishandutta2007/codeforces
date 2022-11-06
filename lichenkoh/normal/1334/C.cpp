#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
const int mn=(3e5)+4;
ll inpa[mn],inpb[mn];
ll a[mn],b[mn];

ll f[2][8];

void rst(int cur) {
  for (int i=0;i<8;i++) f[cur][i]=LLONG_MAX/4;
}
const int FL=1;
const int FR=0;
ll solve(int n, int z0) {
  for (int i=0;i<n;i++) {a[i]=inpa[i]; b[i]=inpb[i];}
  int cur=0,nxt=1;
  rst(cur);
  {
    ll cost=a[0];
    if (z0&FL) cost-=b[n-1];
    if (z0&FR) cost-=b[1];
    chkmax(cost,0LL);
    f[cur][z0]=cost;
  }
  f[cur][4]=f[cur][0];
  for (int p=1;p<n;p++) {
    rst(nxt);
    for (int pz=0;pz<8;pz++) {
      ll prev=f[cur][pz];
      //printf("p-1:%d pz:%d cost:%lld\n",p-1,pz,prev);
      for (int z=0;z<4;z++) {
        if (bool(pz&FR)&&bool(z&FL)) {
          continue;
        }
        ll cost=a[p];
        if (z&FL) cost-=b[p-1];
        int np=p+1; if (np==n) np=0;
        if (z&FR) cost-=b[np];
        chkmax(cost,0LL);
        int nz=z;
        if (z==0||pz==0|| bool(pz&4)) {
          nz|=4;
        }
        chkmin(f[nxt][nz],prev+cost);
      }
    }
    swap(cur,nxt);
  }
  ll ans=LLONG_MAX/4;
  for (int pz=4;pz<8;pz++) {
    if (bool(pz&FR) && bool(z0&FL)) continue;
    chkmin(ans,f[cur][pz]);
  }
  return ans;
}

void go() {
  int n; cin>>n;
  for (int i=0;i<n;i++) cin>>inpa[i]>>inpb[i];
  ll final=LLONG_MAX/4;
  for (int z0=0;z0<4;z0++) {
    //if (z0!=2) continue; // REMOVE
    ll ans=solve(n,z0);
    //if (ans==2) printf("z0:%d\n",z0);
    chkmin(final,ans);
  }
  printf("%lld\n",final);
  /*for (int p=0;p<2;p++) {
    for (int r=0;r<2;r++) {
      for (int c=0;c<2;c++) {
        ll ans=solve(n,c);
        chkmin(final,ans);
      }
      reverse(inpa,inpa+n);
      reverse(inpb,inpb+n);
    }
    for (int i=n;i>=1;i--) {
      inpa[i]=inpa[i-1];
      inpb[i]=inpb[i-1];
    }
    inpa[0]=inpa[n];
    inpb[0]=inpb[n];
  }*/

}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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
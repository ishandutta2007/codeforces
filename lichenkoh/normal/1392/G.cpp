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
const int mn=1000*1000;
const int mk=20;
int k;

using State = bitset<mk>;
State src,tar;
struct Perm {
  char p[mk];
  // Permute *this first, then permute by b
  Perm operator*(Perm const & b) {
    Perm res;
    for (int i=0;i<k;i++) {
      res.p[i]=b.p[p[i]];
    }
    return res;
  }
  void rswap(int x, int y) { // Permute, then swap
    int rx=-1,ry=-1;
    for (int i=0;i<k;i++) {
      if (p[i]==x) rx=i;
      if (p[i]==y) ry=i;
    }
    assert(rx!=-1&&ry!=-1);
    swap(p[rx],p[ry]);
  }
  void lswap(int x, int y) { // Swap, then permute
    swap(p[x],p[y]);
  }
  Perm inverse() const {
    Perm res;
    for (int i=0;i<k;i++) {
      res.p[p[i]]=i;
    }
    return res;
  }
  State apply(State const & s) const {
    State res;
    for (int i=0;i<k;i++) {
      res[p[i]]=s[i];
    }
    return res;
  }
  static Perm identity() {
    Perm id;
    for (int i=0;i<k;i++) id.p[i]=i;
    return id;
  }
};
int dist[2][1<<mk];
int avail[1<<mk];
int a[mn],b[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dist[0],-1,sizeof dist[0]);
  int n=rint(),m=rint(); k=rint();
  for (int x=0;x<(1<<k);x++) avail[x]=INF;
  for (int i=0;i<k;i++) src[i]=rch()-'0';
  for (int i=0;i<k;i++) tar[i]=rch()-'0';


  for (int i=0;i<n;i++) {a[i]=rint()-1; b[i]=rint()-1;}

  Perm mseg=Perm::identity(); // Prefix[x-m+1,x]
  Perm wpre=Perm::identity(); // Prefix[0..x]
  for (int x=0;x<m-1;x++) {
    mseg.rswap(a[x],b[x]);
    wpre.rswap(a[x],b[x]);
  }
  for (int x=m-1;x<n;x++) {
    // Include x. mseg = Prefix[x-m+1,x]
    mseg.rswap(a[x],b[x]);
    // Apply suf
    wpre.rswap(a[x],b[x]); // Prefix[0..x]

    // Add pre into available results
    State s=wpre.inverse().apply(mseg.apply(src));
    //cout<<"avail x: " << x<<": "<<s<<endl;
    // If avail[p]=x, then can get (p * prefix[x, y]) for any y>=x
    // Lower x is more flexible => better
    chkmin(avail[s.to_ulong()],x);

    // Exclude x-(m-1)
    mseg.lswap(a[x-m+1],b[x-m+1]);
  }


  {
    Perm pre=Perm::identity();
    for (int x=0;x<n;x++) {
      pre.rswap(a[x],b[x]); // pre[0,x]
      State ss=pre.inverse().apply(tar).to_ulong();
      //cout<<"Invert tar x: "<<x<<": "<<ss<<endl;
      int s=ss.to_ulong();
      dist[0][s]=x;
      if (avail[s]<=x) {
        int l=avail[s]-m+1;
        int r=x;
        printf("%d\n%d %d\n",k,l+1,r+1);
        exit(0);
      }
    }
    // Convolution
    for (int d=0;d<k-1;d++) {
      memset(dist[(d+1)&1],-1,sizeof dist[(d+1)&1]);
      for (int x=0;x<(1<<k);x++) {
        int now=dist[d&1][x];
        if (now==-1) continue;
        for (int i=0;i<k;i++) {
          // Higher now => Can match with more "avail" patterns => Better
          chkmax(dist[(d+1)&1][x^(1<<i)],now);
        }
      }
      for (int s=0;s<(1<<k);s++) {
        int r=dist[(d+1)&1][s];
        if (avail[s]<=r) {
          int l=avail[s]-m+1;
          printf("%d\n%d %d\n",k-d-1,l+1,r+1);
          exit(0);
        }
      }
    }
  }

  // No solution found yet, implies only maximal solution available
  printf("0\n%d %d\n",1,n);
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
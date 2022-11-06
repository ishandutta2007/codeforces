#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=(2e5)+4;
inline ull MK(uint x, uint y) {return (((ull)x)<<32)|y;}

map<ull,int> subtreeSize;
template<size_t maxn> class EulerEdgeSumWeight {
public: // Custom code
  typedef struct S {
    int sum;
    S () : sum(0) {}
    S(const int _sum) : sum(_sum) {}
    S operator*(const S &b) const {
      // Must be commutative
      return S(sum+b.sum);
    }
  } S;
  S upd(const S &b, int x) {
    /*
    The problem may require t[x]= f(\prod_{y \in neighbor(x)} t[y]).
    At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
    So we now want to perform the operation t[x]=f(t[x]).
    This function performs that operation.
    This function should modify this->variables in the struct S directly.
    */
    S a=b;
    a.sum++; // Add 1 for the vertex itself
    return a;
  }
  S identity=S(0);

  void custom_handle_result(int x, int p, const S &s) {
    // If p=-1, then it's the full graph
    subtreeSize[MK(x,p)]=s.sum;
  }
  void run(vector<vector<int> > &_g, int initVtx) {
    // We can handle 0 or 1-indexed graphs gracefully
    // This only handles the tree that is connected to initVtx
    // If you have a forest, you need to run this multiple times
    g=_g;
    init(initVtx,-1);
    euler_edge(initVtx,-1);
  }

private:
  typedef struct VS {
    vector<S> prefix;
    vector<S> suffix;
    S allChildren;
  } VS;
  S t[maxn];
  VS vt[maxn];
  vector<vector<int> > g;
  int numVtx;

  void init(int x, int p) {
    int numchildren=((int)g[x].size()) - ((p==-1)?0:1);
    for (auto &y:g[x]) {
      if (y==p) continue;
      init(y,x);
      t[x]=t[x]*t[y];
    }
    t[x]=upd(t[x],x);
    {
      S prefix=identity;
      vt[x].prefix.resize(numchildren);
      int id=0;
      for (auto &y:g[x]) {
        if (y==p) continue;
        vt[x].prefix[id]=prefix;
        prefix=prefix*t[y];
        id++;
      }
    }
    {
      S suffix=identity;
      vt[x].suffix.resize(numchildren);
      int id=0;
      for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
        int y=*it;
        if (y==p) continue;
        vt[x].suffix[id]=suffix;
        suffix=suffix*t[y];
        id++;
      }
      reverse(vt[x].suffix.begin(),vt[x].suffix.end());
    }
  }
  void euler_edge(int x, int p) {
    // Start edge custom code
    if (p!=-1) {
      custom_handle_result(x,p,t[x]);
      custom_handle_result(p,x,t[p]);
      custom_handle_result(x,-1,t[p]*t[x]);
    } else {
      custom_handle_result(x,-1,t[x]);
    }
    // End edge custom code
    int yid=0;
    for (auto &y:g[x]) {
      if (y==p) continue;
  
      S old_tx=t[x];
      t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
      if (p!=-1) {
        t[x]=t[x]*t[p];
      }
      t[x]=upd(t[x],x);
      euler_edge(y,x);
      t[x]=old_tx;
  
      yid++;
    }
  }
};
ll final=0;
template<size_t maxn> class EulerEdgeDP {
public: // Custom code
  typedef struct S {
    ll sum;
    S () : sum(0) {}
    S(const ll _sum) : sum(_sum) {}
    S operator*(const S &b) const {
      // Must be commutative
      return S(sum+b.sum);
    }
  } S;
  S upd(const S &b, int x, int p) {
    /*
    The problem may require t[x]= f(\prod_{y \in neighbor(x)} t[y]).
    At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
    So we now want to perform the operation t[x]=f(t[x]).
    This function performs that operation.
    */
    S a=b;
    assert(subtreeSize.count(MK(x,p)));
    a.sum+=subtreeSize[MK(x,p)];
    return a;
  }
  S identity=S(0);

  void custom_handle_result(int x, int p, const S &s) {
    // If p=-1, then it's the full graph
    if (p==-1) chkmax(final,s.sum);
    //printf("x:%d p:%d s:%lld\n",x,p,s.sum);
  }
  void run(vector<vector<int> > &_g, int initVtx) {
    // We can handle 0 or 1-indexed graphs gracefully
    // This only handles the tree that is connected to initVtx
    // If you have a forest, you need to run this multiple times
    g=_g;
    init(initVtx,-1);
    euler_edge(initVtx,-1);
  }

private:
  typedef struct VS {
    vector<S> prefix;
    vector<S> suffix;
    S allChildren;
  } VS;
  S t[maxn];
  VS vt[maxn];
  vector<vector<int> > g;
  int numVtx;

  void init(int x, int p) {
    int numchildren=((int)g[x].size()) - ((p==-1)?0:1);
    for (auto &y:g[x]) {
      if (y==p) continue;
      init(y,x);
      t[x]=t[x]*t[y];
    }
    t[x]=upd(t[x],x,p);
    {
      S prefix=identity;
      vt[x].prefix.resize(numchildren);
      int id=0;
      for (auto &y:g[x]) {
        if (y==p) continue;
        vt[x].prefix[id]=prefix;
        prefix=prefix*t[y];
        id++;
      }
      vt[x].allChildren=prefix;
    }
    {
      S suffix=identity;
      vt[x].suffix.resize(numchildren);
      int id=0;
      for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
        int y=*it;
        if (y==p) continue;
        vt[x].suffix[id]=suffix;
        suffix=suffix*t[y];
        id++;
      }
      reverse(vt[x].suffix.begin(),vt[x].suffix.end());
    }
  }
  void euler_edge(int x, int p) {
    // Start edge custom code
    if (p!=-1) {
      custom_handle_result(x,p,t[x]);
      custom_handle_result(p,x,t[p]);
      custom_handle_result(x,-1,t[p]*upd(vt[x].allChildren,x,-1));
    } else {
      custom_handle_result(x,-1,t[x]);
    }
    // End edge custom code
    int yid=0;
    for (auto &y:g[x]) {
      if (y==p) continue;
  
      S old_tx=t[x];
      t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
      if (p!=-1) {
        t[x]=t[x]*t[p];
      }
      t[x]=upd(t[x],x,y);
      euler_edge(y,x);
      t[x]=old_tx;
  
      yid++;
    }
  }
};



EulerEdgeSumWeight<mn> ee1;
EulerEdgeDP<mn> ee2;

int n;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  vvi g;
  g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  //srand(time(0));
  int init=1;
  ee1.run(g,init);
  ee2.run(g,init);
  printf("%lld\n",final);
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
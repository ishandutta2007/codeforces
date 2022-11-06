#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
struct S {
  S(int _loop, int _noloop) : loop(_loop),noloop(_noloop) {}
  int loop;
  int noloop;
};

const int defaultValue = 0;
template<typename Key,typename Val> class Trie {
public:
  struct Node {
    Val val;
    struct Node *ch[2];
    Node() {
      val=defaultValue;
      ch[0]=NULL; ch[1]=NULL;
    }
  };
  Trie(int _keyDepth): root(new Node), keyDepth(_keyDepth) {};

  void _insKey(Node *r, Key key, int depth, Val delta) {
    r->val += delta;
    if (depth==-1) return;
    int b=(key>>depth)&1;
    if (r->ch[b]==NULL) {
      r->ch[b]=new Node();
    }
    _insKey(r->ch[b],key,depth-1,delta);
  }

  S _dfs(Node *v, int depth) {
    if (depth==-1) return S(v->val,min(1,v->val));
    S l=S(0,0),r=S(0,0);
    if (v->ch[0]) l=_dfs(v->ch[0],depth-1);
    if (v->ch[1]) r=_dfs(v->ch[1],depth-1);
    int loop=max(max(l.noloop + r.loop, l.loop + r.noloop), l.noloop + r.noloop);
    int noloop=min(1, l.noloop + r.noloop);
    return S(loop,noloop);
  }

  S dfs() {return _dfs(root, keyDepth);}

  void insKey(Key key, Val delta) {_insKey(root,key,keyDepth,delta);}

  Node *root = NULL;
  int keyDepth=0;
};
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  Trie<int,int> trie(30);
  int n; cin>>n;
  vi a(n);
  for (int i=0;i<n;i++) {cin>>a[i];}
  for (auto &w:a) trie.insKey(w,1);
  S res=trie.dfs();
  int ans=max(res.loop,res.noloop);
  int final=n-ans;
  printf("%d\n",final);
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
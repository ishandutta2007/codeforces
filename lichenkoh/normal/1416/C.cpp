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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
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
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}

const pii defaultValue = MP(0,0);
template<typename Val> class Trie {
public:
  struct Node {
    Val val;
    struct Node *ch[2];
    Node() {
      val=defaultValue; ch[0]=NULL; ch[1]=NULL;
    }
  };
  Trie(int _keyDepth): root(new Node), keyDepth(_keyDepth) {};

  void _insKey(Node *r, int key, int depth) {
    if (depth==-1) return;
    int b=(key>>depth)&1;
    if (r->ch[b]==NULL) {
      r->ch[b]=new Node();
    }
    _insKey(r->ch[b],key,depth-1);
  }

  void insKey(int key) {_insKey(root,key,keyDepth);}

  Val & _getRef(Node *r, int key, int targetDepth, int depth) {
    if (depth+1 == targetDepth) return r->val;
    int b=(key>>depth)&1;
    if (r->ch[b]==NULL) r->ch[b]=new Node();
    return _getRef(r->ch[b], key,targetDepth,depth-1);
  }
  Val & getRef(int key, int targetDepth) {return _getRef(root,key,targetDepth, keyDepth);}

  Node *root = NULL;
  int keyDepth=0;
};
const int mk=29;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); vi a(n);
  for (int i=0;i<n;i++) a[i]=rint();
  Trie<pii> trie(mk+1);
  int final=0;
  ll finalinv=0;
  for (int k=mk;k>=0;k--) {
    ll ainv=0;
    ll binv=0;
    for (int i=0;i<n;i++) {
      int x=a[i];
      int key=x;
      pii & val=trie.getRef(key,k+1);
      //printf("key:%d k:%d",key,k);
      if (x&(1<<k)) {
        ++val.snd;
        binv+=val.fst;
        //printf(" bit 1\n");
      } else {
        ++val.fst;
        ainv+=val.snd;
        //printf(" bit 0\n");
      }
    }
    if (binv < ainv) {
      final|=1<<k;
    }
    finalinv+=min(binv,ainv);
  }
  printf("%lld %d\n",finalinv, final);
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
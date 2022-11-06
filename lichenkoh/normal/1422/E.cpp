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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
using vc=vector<char>;
vector<pair<int,string> > vfinal;
struct S {
  S(int _pos, char _cur, char _prev): pos(_pos),cur(_cur),prev(_prev) {
    assert(_prev!=_cur);
  }
  int pos;
  char cur,prev;
};
vector<S> ans;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string inp; cin>>inp;
  int n=inp.length();
  vfinal.reserve(n);
  bool prevused=true;
  for (int p=n-1;p>=0;p--) {
    char c=inp[p];
    if (ans.size() && p==ans.back().pos-1 && c==ans.back().cur && c>ans.back().prev) {
      ans.pop_back();
    } else {
      char prev;
      if (ans.size()) {
        if (ans.back().cur==c) {
          prev=ans.back().prev;
        } else {
          prev=ans.back().cur;
        }
      } else {
        prev='a'-1;
      }
      ans.PB(S(p,c,prev));
    }
    int sz=ans.size();
    if (sz<=10) {
      vector<char> res; res.reserve(10);
      for (int i=0;i<sz;i++) res.PB(ans[sz-1-i].cur);
      vfinal.PB(MP(sz,string(res.begin(),res.end())));
    } else {
      vector<char> res; res.reserve(10);
      for (int i=0;i<5;i++) res.PB(ans[sz-1-i].cur);
      for (int i=0;i<3;i++) res.PB('.');
      for (int i=1;i>=0;i--) res.PB(ans[i].cur);
      vfinal.PB(MP(sz,string(res.begin(),res.end())));
    }
  }
  for (int p=n-1;p>=0;p--) printf("%d %s\n",vfinal[p].fst,vfinal[p].snd.c_str());
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
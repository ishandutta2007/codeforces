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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
/*int longest_strictly_increasing_subsequence(vector<int> p) {
  vector<int> v;
  int n=p.size();
  for (auto &x:p) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if(v[imid]<x) imin=imid+1;
      else imax=imid;
    }
    if (imin==v.size()) v.PB(x);
    else {
      v[imin]=x;
    }
  }
  return v.size();
}*/
int hquery(map<int,int> &h, int key) {
  //Queries the largest (k,v) pair where k<=key
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    return 0;
  }
  --it;
  return it->snd;
}

void hins(map<int,int> &h, int key, int val) {
  //Inserts (key,val) into h.
  //Maintains the invariant that if key1<key2, then val1<val2.
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    it=h.insert(MP(key,val)).fst;
  }
  else {
    --it;
    if (it->snd >= val) return;
    if (it->fst==key) it->snd = val;
    else it=h.insert(MP(key,val)).fst;
  }
  ++it;
  while(it!=h.end()) {
    if (it->snd <= val) it=h.erase(it);
    else return;
  }
}
const int mn=100000+2;
map<int,int> h[mn];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  int final=0;
  for (int i=0;i<m;i++) {
    int a=rint(),b=rint(),w=rint();
    int gota=hquery(h[a],w-1);
    ++gota;
    chkmax(final,gota);
    hins(h[b],w,gota);
  }
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
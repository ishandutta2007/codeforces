#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
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

template <typename LST, int MAXLIM> struct LimitedVec  {
  LST a[MAXLIM];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
  int size() {
    return sz;
  }
};


const int mn=5000;
char s[mn+1];
int ilog2(int x) {
  return 31-__builtin_clz(x);
}
int n;
queue<int> q;
char vans[mn+1];
const int mz=4096;
bitset<mz> f;
bitset<mz> g;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n",s);
  n=strlen(s);
  int klim=ilog2(n);
  int fposlim=n-(1<<klim)+1;
  //printf("klim:%d fposlim:%d n:%d\n",klim,fposlim,n);
  f[0]=true;
  int zlim=1<<klim;
  for (int fpos=0;fpos<fposlim;fpos++) {
    for (int k=0;k<klim;k++) {
      int msk=1<<k;
      for (int z=0;z<zlim;z++) {
        if (msk&z) {
          if (f[z^msk]) f[z]=true;
        }
      }
    }
    char bestc='z';
    for (int z=0;z<zlim;z++) {
      if (f[z]) chkmin(bestc,s[fpos+z]);
    }
    //printf("bestc:%d %c\n",bestc,bestc);
    g.reset();
    for (int z=0;z<zlim;z++) {
      if (f[z]&&s[fpos+z]==bestc) {
        //printf("fpos:%d z:%d\n",fpos,z);
        g[z]=true;
      }
    }
    f=g;
    vans[fpos]=bestc;
  }
  vans[fposlim]='\0';
  printf("%s\n",vans);
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
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

int csame(pii a, pii b) {
  int ans=0;
  if (a.fst==b.fst) ans++;
  if (a.fst==b.snd) ans++;
  if (a.snd==b.fst) ans++;
  if (a.snd==b.snd) ans++;
  return ans;
}
int gsame(pii a, pii b) {
  if (a.fst==b.fst) return a.fst;
  if (a.fst==b.snd) return a.fst;
  if (a.snd==b.fst) return a.snd;
  if (a.snd==b.snd) return a.snd;
  return -1;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  vector<pii> va,vb;
  for (int i=0;i<n;i++) {
    va.PB(MP(rint(),rint()));
  }
  for (int i=0;i<m;i++) {
    vb.PB(MP(rint(),rint()));
  }
  {
    set<int> sg;
    for (auto &a:va) for (auto &b:vb) {
      if (csame(a,b)!=1) continue;
      int g=gsame(a,b);
      sg.insert(g);
    }
    if (sg.size()==1) {
      printf("%d\n",*(sg.begin())); exit(0);
    }
  }
  for (auto &a:va) {
    set<int> sg;
    for (auto &b:vb) {
      if (csame(a,b)!=1) continue;
      int g=gsame(a,b);
      sg.insert(g);
    }
    if (sg.size()>1) {
      printf("-1\n"); exit(0);
    }
  }
  for (auto &a:vb) {
    set<int> sg;
    for (auto &b:va) {
      if (csame(a,b)!=1) continue;
      int g=gsame(a,b);
      sg.insert(g);
    }
    if (sg.size()>1) {
      printf("-1\n"); exit(0);
    }
  }
  printf("0\n");

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
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

void fail(int t) {
  printf("-1\n"); exit(0);
}
int a,b,ab,ba;
vector<int> v;
void ga() {
  --a; v.PB(4);
}
void gb() {
  --b; v.PB(7);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  a=rint(),b=rint(),ab=rint(),ba=rint();
  if (ab==ba+1) {
    // Start with ab
    int ae=a-ab;
    int be=b-ab;
    //printf("ae:%d be:%d\n",ae,be);
    if (ae<0||be<0) fail(1);
    for (int i=0;i<ae;i++) ga();
    for (int i=0;i<ab;i++) {ga();gb();}
    for (int i=0;i<be;i++) gb();
  }
  else if (ab==ba){
    if (a-ab-1>=0) {
      int ae=a-ab-1;
      int be=b-ba;
      if (ae<0||be<0) fail(10);
      for (int i=0;i<ae;i++) ga();
      for (int i=0;i<ab;i++) {ga();gb();}
      for (int i=0;i<be;i++) gb();
      ga();
    }
    else {
      gb(); ba--; if (b<0||ba<0) fail(2);
    int ae=a-ab;
    int be=b-ab;
    //printf("ae:%d be:%d\n",ae,be);
    if (ae<0||be<0) fail(1);
    for (int i=0;i<ae;i++) ga();
    for (int i=0;i<ab;i++) {ga();gb();}
    for (int i=0;i<be;i++) gb();
    }
  }
  else if (ba==ab+1) {
      gb();ba--; if (b<0||ba<0) fail(4);
      int ae=a-ab-1;
      int be=b-ba;
      if (ae<0||be<0) fail(11);
      for (int i=0;i<ae;i++) ga();
      for (int i=0;i<ab;i++) {ga();gb();}
      for (int i=0;i<be;i++) gb();
      ga();
  }
  else fail(5);
  //printf("%d %d %d %d\n",a,b,ab,ba);
  //for (auto &w:v) printf("%d",w);
  if (a<0||b<0||ab<0||ba<0) fail(6);
  for (auto &w:v) printf("%d",w);
  printf("\n");
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
int x; cin>>x; return x;
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
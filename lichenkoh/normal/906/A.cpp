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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mc=26;
int no=0,tmp=0;
const int mn=1e5+4;
string tp[mn];
string a[mn];
vector<pair<int,pii> > v;
vector<pair<int,pii> > vbang;
const int MASK=(1<<26)-1;
int fl(int x) {
  return (~x)&MASK;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=0;i<n;i++) {
    cin>>tp[i]>>a[i];
  }
  int allshocks=0;
  for (int tt=0;tt<n;tt++) {
    string s=a[tt];
    char t=tp[tt][0];
    if ((t=='!'||t=='?')&&tt!=n-1) allshocks++;
  }
  int shocks=0;
  
  int final=INF;
  for (int tt=0;tt<n;tt++) {
    string s=a[tt];
    char t=tp[tt][0];
    if ((t=='!'||t=='?')&&tt!=n-1) shocks++;
    if (t=='!') {
      int bang=0;
      for (int x=0;x<s.length();x++) {
        int c=s[x]-'a';
        bang|=(1<<c);
      }
      vbang.PB(MP(tt, MP(bang,shocks)));
      int newno=no|fl(bang);
      if (newno!=no) {v.PB(MP(tt,MP(newno,shocks)));}
      no=newno;
    }
    else if (t=='.') {
      int dot=0;
      for (int x=0;x<s.length();x++) {
        int c=s[x]-'a';
        dot|=(1<<c);
      }
      int newno=no|dot;
      if (newno!=no) {v.PB(MP(tt,MP(newno,shocks)));}
      no=newno;
    }
    else if (t=='?') {
      int ques=0;
      int c=s[0]-'a';
      ques|=(1<<c);
      int newno=no|ques;
      if (newno!=no) {v.PB(MP(tt,MP(newno,shocks)));}
      no=newno;
    }
    else assert(0);
    if (__builtin_popcount(no)==mc-1) {
      chkmin(final,shocks);
    }
  }
  for (auto &w:v) {
    int wi=w.fst;
    int wno=w.snd.fst;
    int wshock=w.snd.snd;
    for (auto &b:vbang) {
      int bi=b.fst, bang=b.snd.fst, bshock=b.snd.snd;
      int sig=fl(wno)&bang;
      //printf("wi:%d wno:%d wshock:%d bi:%d bang:%d bshock:%d sig:%d\n",wi,wno,wshock,bi,bang,bshock,sig);
      if (__builtin_popcount(sig)<=1) {
        chkmin(final,max(wshock,bshock));
        break;
      }
    }
  }
  int ans=shocks-final;
  chkmax(ans,0);
  printf("%d\n",ans);
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
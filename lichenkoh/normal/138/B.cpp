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
int orig[10];
string origs;
string make(int *a, int numz, vector<int> s, int seed) {
  vector<char> c;
  for (int d=0;d<=9;d++) for (int i=0;i<a[d];i++) c.PB('0'+d);
  reverse(s.begin(),s.end());
  for (auto &w:s) c.PB('0'+w);
  //c.PB(seed);
  for (int i=0;i<numz;i++) c.PB('0');
  assert(c.size()==origs.length());
  return string(c.begin(),c.end());
}
int a[10],b[10];
pair<int,pair<string,string> > f(int seed) {
  memcpy(a,orig,sizeof a);
  memcpy(b,orig,sizeof b);
  int oppseed=10-seed;
  if (a[seed]<=0||b[oppseed]<=0) return MP(-1,MP("",""));
  vector<int> s,t;
  a[seed]--; s.PB(seed);
  b[oppseed]--; t.PB(oppseed);
  int ans=1;
  for (int d=0;d<=9;d++) {
    int take=min(a[d],b[9-d]);
    for (int i=0;i<take;i++) {s.PB(d); t.PB(9-d);}
    a[d]-=take; b[9-d]-=take;
    ans+=take;
  }
  int numz=min(a[0],b[0]); a[0]-=numz; b[0]-=numz;
  ans+=numz;
  string ss=make(a,numz,s,seed);
  string tt=make(b,numz,t,oppseed);
  return MP(ans,MP(ss,tt));
}
pair<int,pair<string,string> > g() {
  string s=origs,t=origs;
  sort(s.begin(),s.end(),greater<char>());
  sort(t.begin(),t.end(),greater<char>());
  return MP(orig[0],MP(s,t));
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>origs;
  for (auto &w:origs) orig[w-'0']++;
  pair<int,pair<string,string> > final=g();
  for (int seed=1;seed<=9;seed++) chkmax(final,f(seed));
  cout<<final.snd.fst<<endl<<final.snd.snd<<endl;
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
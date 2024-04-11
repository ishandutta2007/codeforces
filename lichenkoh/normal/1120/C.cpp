#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int mn=5004;
class KMP {
// State starts with 0. State is equal to the number of chars in the prefix matched.
// If state = length of string, then it is fully matched.
// Supports further matching after fully matched. Matches may intersect.
// So if pattern = ABAB, and str = ABABAB, then there are 2 matches.
// http://codeforces.com/contest/346/submission/28895320
// http://codeforces.com/contest/346/submission/28895339
public:
  int fail[mn+10];
  int memo[26][mn+10];
  char p[mn];
  int gm;
  // Walk the KMP DFA from state j with letter x
  int dfa(int j, char x) {
    int oldj = j;
    int z = x - 'a';
    if (memo[z][j] != -1) {
      return memo[z][j];
    }
    ++j;
    while (j > 0 && x != p[j-1]) {
      j = fail[j];
    }
    memo[z][oldj] = j;
    return j;
  }
  
  // Build KMP failure table
  void buildfail()
  {
    int m=gm;
    int j = 0;
    for (int i = 1; i <= m; i++) {
      fail[i] = j;
      while (j > 0 && p[i-1] != p[j-1]) {
        j = fail[j];
      }
      j++;
    }
    fail[m+1] = j;
  }
  void initstr(string pattern) {
    int m=pattern.length();
    gm=m;
    for (int i = 0; i < m; i++) p[i] = pattern[i];
    common_init();
  }
  void common_init() {
    int m=gm;
    for (int i = 0; i < 26; i++) {
      memset(memo[i],-1,sizeof(int)*(m+2));
    }
    for (int i = 0; i <= m+1; i++) fail[i] = 0;
    buildfail();
  }
};

int f[mn];
KMP k;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,a,b; cin>>n>>a>>b; string s; cin>>s;
  f[0]=0; for (int x=1;x<mn;x++) f[x]=INT_MAX;
  for (int x=0;x<n;x++) {
    chkmin(f[x+1],f[x]+a);
    k.initstr(s.substr(x));
    //cout<<s.substr(x)<<endl;
    int maxgo=0;
    int state=0;
    for (int y=0;y<x;y++) {
      state=k.dfa(state,s[y]);
      //printf("%c state:%d\n",s[y],state);
      chkmax(maxgo,state);
    }
    chkmin(maxgo,n-x);
    //cout<<maxgo<<endl;
    //cout<<f[x]<<endl;
    /*
    if (x+maxgo>n) {
      printf("x:%d maxgo:%d. %s | %s\n",x,maxgo,s.substr(0,x).c_str(),s.substr(x).c_str());
      fflush(stdout);
      assert(0);
      exit(0);
    }
    assert(x+maxgo<=n);
    */
    for (int y=x+1;y<x+1+maxgo;y++) {
      chkmin(f[y],f[x]+b);
      //cout<<y<<endl;
    }
  }
  printf("%d\n",f[n]);
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
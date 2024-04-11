#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mk=24;
const int mz=1<<mk;
int f[mz];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
  for (int i=0;i<n;i++) {
    string s; cin>>s;
    set<int> sc;
    int msk=0;
    for (int j=0;j<3;j++) {
      int c=s[j]-'a';
      sc.insert(c);
    }
    vector<int> v; for (auto &w:sc) v.PB(w);
    int k=v.size();
    for (auto &x:v) {
      f[1<<x]++;
    }
    for (int x=0;x<k;x++) {
      for (int y=0;y<x;y++) {
        f[(1<<v[x])|(1<<v[y])]--;
      }
    }
    if (k==3) {
      f[(1<<v[0])|(1<<v[1])|(1<<v[2])]++;
    }
  }
  for (int i=0;i<mk;i++) {
    for (int msk=0;msk<(1<<mk);msk++) {
      if (msk&(1<<i)) {
        f[msk]+=f[msk^(1<<i)];
      }
    }
  }
  //printf("%d\n",f[mz-1]);
  int final=0;
  for (int z=0;z<mz;z++) {
    int x=f[z];
    final^=x*x;
  }
  printf("%d\n",final);
}
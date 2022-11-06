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

bitset<26> forbid[26];
const int mn=1e5+4;
int vnxt[mn][26];
int f[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s;
  int k; cin>>k;
  for (int i=0;i<k;i++) {
  	string t; cin>>t;
  	int x=t[0]-'a',y=t[1]-'a';
  	forbid[x][y]=forbid[y][x]=true;
  }
  int n=s.length();
  for (int i=0;i<mn;i++) for (int x=0;x<26;x++) vnxt[i][x]=INF;
  for (int i=n-2;i>=0;i--) {
  	for (int x=0;x<26;x++) vnxt[i][x]=vnxt[i+1][x]; 
  	chkmin(vnxt[i][s[i+1]-'a'],i+1);
  }
  for (int i=0;i<n;i++) f[i]=1;
  for (int i=0;i<n;i++) {
  	int now=f[i]+1;
  	int c=s[i]-'a';
  	for (int d=0;d<26;d++) {
  		if (!forbid[c][d]) {
  			int k=vnxt[i][d];
  			if (k!=INF) {
  				chkmax(f[k],now);
  				//printf("i:%d d:%c k:%d now:%d\n", i,d+'a',k,now);
  			}
  		}
  	}
  }
  int final=0; for (int i=0;i<n;i++) chkmax(final,f[i]);
  printf("%d\n", n-final);
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
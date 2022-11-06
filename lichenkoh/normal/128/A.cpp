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

string s[8];
bitset<8> b[8];
bitset<8> p[2][8];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  clock_t start=clock();
  for (int i=0;i<8;i++) cin>>s[i];
  for (int x=0;x<8;x++) for (int y=0;y<8;y++) {
  	if (s[x][y]=='M') p[0][x][y]=true;
  	if (s[x][y]=='S') b[x][y]=true;
  }
  int cur=0;
  while(1) {
  	int nxt=cur^1;
  	if (clock()-start > 0.6 * CLOCKS_PER_SEC) {
  		printf("LOSE\n"); exit(0);
  	}
  	for (int x=0;x<8;x++) p[nxt][x].reset();
  	for (int x=0;x<8;x++) for (int y=0;y<8;y++) {
  		if (b[x][y]||(!p[cur][x][y])) continue;
  		if (s[x][y]=='A') {
  			printf("WIN\n"); exit(0);
  		}
  		for (int nx=max(0,x-1);nx<=min(7,x+1);nx++) {
  			for (int ny=max(0,y-1);ny<=min(7,y+1);ny++) {
  				if (!b[nx][ny]) p[nxt][nx][ny]=true;
  			}
  		}
  	}
  	for (int x=7;x>=1;x--) {
  		b[x]=b[x-1];
  	}
  	b[0].reset();
  	cur^=1;
  }
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
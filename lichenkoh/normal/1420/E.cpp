#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
const int mn=82;
int f[mn][mn][(mn*(mn-1))/2]; // f[pos][usedShields][usedMoves] = Max pairs given shield at pos-1, and we used shields are used
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(f,-1,sizeof f);
  int n=rint();
  vi shieldPos;
  for (int i=0;i<n;i++) {
  	if (rint()) {
  		shieldPos.PB(i);
  	}
  }
  int totalShields=shieldPos.size();
	f[0][0][0]=0;
	int totalMoves=(n*(n-1))/2;
	for (int pos=0;pos<n;pos++) {
		for (int usedShields=0;usedShields<=totalShields;usedShields++) {
			for (int usedMoves=0;usedMoves<=totalMoves;usedMoves++) {
				int curPairs=f[pos][usedShields][usedMoves];
				if (curPairs==-1) continue;
				int prevNoShields=pos-usedShields;
				if (usedShields==totalShields) {
					int unshielded=n-pos;
					int newPairs=curPairs + unshielded * prevNoShields;
					chkmax(f[n][usedShields][usedMoves],newPairs);
				} else {
					int origShieldPos=shieldPos[usedShields];
					for (int nxtPos=pos+1;nxtPos<=n;nxtPos++) {
						int newMoves=usedMoves+abs(nxtPos-1-origShieldPos);
						if (newMoves<=totalMoves) {
							int unshielded=nxtPos-pos-1;
							int newPairs=curPairs + unshielded * prevNoShields;
							chkmax(f[nxtPos][usedShields+1][newMoves],newPairs);
						}
					}
				}
			}
		}
	}
	int best=0;
	for (int moves=0;moves<=totalMoves;moves++) {
		chkmax(best,f[n][totalShields][moves]);
		printf("%d ",best);
	}
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
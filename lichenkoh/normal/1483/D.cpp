#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const ll mn=602;
ll n;
vvi g;
ll vdist[mn][mn];
ll ed[mn][mn];
vpll q[mn];
bitset<mn> good[mn];

void floyd() {
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				chkmin(vdist[i][j], vdist[i][k]+vdist[k][j]);
			}
		}
	}
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint();
  g.resize(n+1);
  for (int x=1;x<=n;x++) for (int y=1;y<=n;y++) {
  	vdist[x][y]=INF;
  }
  for (int x=1;x<=n;x++) vdist[x][x]=0;
  for (int i=0;i<m;i++) {
  	int x=rint(); int y=rint(); int w=rint();
  	g[x].PB(y);
  	g[y].PB(x);
  	vdist[x][y]=w; vdist[y][x]=w;
  	ed[x][y]=w; ed[y][x]=w;
  }
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
  	int s=rint(); int t=rint(); int l=rint();
  	q[t].PB(MP(s,l));
  }
  floyd();
	for (int t=1;t<=n;t++) {
		for (int x=1;x<=n;x++) {
  		ll remhi=INT_MIN;
  		for (auto &wsl:q[t]) {
  			int s=wsl.fst; ll l=wsl.snd;
  			if (l==-1) continue;
  			ll dsx=vdist[s][x];
  			ll rem=l-dsx;
  			chkmax(remhi,rem);
  		}
  		for (auto &y:g[x]) {
  			ll d=ed[x][y]+vdist[y][t];
  			if (d<=remhi) {
	  			good[x][y]=true;
	  			good[y][x]=true;
  			}
  		}
  	}
  }
  ll final=0;
  for (int x=1;x<=n;x++) {
  	good[x][x]=false;
  	final+=good[x].count();
  }
  final/=2;
  printf("%lld\n",final);
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
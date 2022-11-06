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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing***/
#endif
int rint();char rch();long long rlong();
const int mn=200000+1;
int g2b[mn][2];
vector<int> b2g[mn];
int bcg[mn];

class UnionFind {
	static const int mx=mn;
  typedef int UFTYPE;
public:
  int par[mx];
  UFTYPE val[mx];
  void init(int n) {
    for (int x=1;x<=n;x++) {
    	par[x]=x;
    	val[x]=1;
    }
  }
  int ffind(int x) {
    if (par[x] != x) {
      par[x] = ffind(par[x]);
    }
    return par[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (val[xr] > val[yr]) swap(xr,yr);
    par[xr] = yr;
    val[yr]+=val[xr];
  }
};
UnionFind uf;

int sortedg[mn],g2w[mn];
bool cmpw(const int &x, const int &y) {
	return g2w[x]>g2w[y];
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int bn=rint(),gn=rint();
  uf.init(bn);
  for (int g=1;g<=gn;g++) {
  	int b0=rint(),b1=rint(); g2w[g]=rint();
  	g2b[g][0]=b0;g2b[g][1]=b1;
  	b2g[b0].PB(g);
  	b2g[b1].PB(g);
  	sortedg[g-1]=g;
  }
  sort(sortedg,sortedg+gn,cmpw);
  memset(bcg,-1,sizeof bcg);
  int final=0;
  for (int gi=0;gi<gn;gi++) {
  	int g=sortedg[gi];
  	for (int bi=0;bi<2;bi++) {
  		int b=g2b[g][bi];
  		int br=uf.ffind(b);
  		if (uf.val[br]>0) {
  			uf.val[br]--;
  			uf.funion(br, g2b[g][bi^1]);
  			final+=g2w[g];
  			break;
  		}
  	}
  }
  printf("%d\n",final);
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
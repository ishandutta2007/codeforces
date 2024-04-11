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
const int mn=100000+2;
vi lv2e[mn];
int e2lv[mn],e2hv[mn],v2lo[mn],v2hi[mn];
ll prod[mn];
ll ans = 0;
void upd(int v) {
	ll nprod=v2lo[v]*(ll)v2hi[v];
	ans+=nprod-prod[v];
	prod[v]=nprod;
}

void decv(int v) {
	v2lo[v]++;
	v2hi[v]--;
	upd(v);
}

void incv(int v) {
	v2lo[v]--;
	v2hi[v]++;
	upd(v);
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  for (int e=0;e<m;e++) {
  	int lv=rint(); int hv=rint();
  	if (lv>hv) swap(lv,hv);
  	e2lv[e]=lv;
  	e2hv[e]=hv;
  	lv2e[lv].PB(e);
  	v2lo[lv]++;
  	v2hi[hv]++;
  }
  for (int v=1;v<=n;v++) {
  	prod[v]=v2lo[v]*(ll)v2hi[v];
  	ans+=prod[v];
  }
  printf("%lld\n",ans);
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
  	int upv=rint();
  	for (auto &e:lv2e[upv]) {
  		int dnv=e2hv[e];
  		assert(dnv!=upv);
  		decv(dnv);
  		incv(upv);
  		lv2e[dnv].PB(e);
  		swap(e2lv[e],e2hv[e]);
  	}
  	lv2e[upv].clear();
  	printf("%lld\n",ans);
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
    char ch=*stdinPos;
    ++stdinPos;
    return ch;
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
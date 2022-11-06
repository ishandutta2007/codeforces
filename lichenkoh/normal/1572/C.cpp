#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
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
const int INF=1<<30;
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
const int mn=3004;
int tmp[mn];
int a[mn];
int k[mn];
int f[mn][mn];
pii myread() {
	int n=rint();
	int last=-1;
	int idx=1;
	for (int p=1;p<=n;p++) {
		int x=rint();
		if (x!=last) {
			last=x;
			a[idx]=x;
			idx++;
		}
	}
	return MP(idx-1,n);
}
void go() {
	pii got=myread();
	int n=got.fst;
	int rawn=got.snd;
	vvi v(rawn+1);
	for (int p=1;p<=n;p++) {
		int c=a[p];
		//printf("%d ",c);
		k[p]=v[c].size();
		v[c].PB(p);
	}
	//printf(" end a\n");
	for (int x=1;x<=n;x++) f[x][x]=1;
	for (int d=1;d<n;d++) {
		for (int r=d+1;r<=n;r++) {
			int l=r-d;
			int lc=a[l],rc=a[r];
			int ans=INF;
			if (lc==rc) {
				chkmin(ans, f[l+1][r-1]+1);
				int kl=k[l];
				int sl=v[lc].size();
				for (int xl=kl;xl<sl;xl++) {
					int l2=v[lc][xl];
					if (l2>=r) break;
					chkmin(ans, f[l][l2] + f[l2+1][r] -1);
				}
			} else {
				int kl=k[l],kr=k[r];
				int sl=v[lc].size();
				for (int xl=kl;xl<sl;xl++) {
					int l2=v[lc][xl];
					if (l2>=r) break;
					chkmin(ans, f[l][l2] + f[l2+1][r]);
				}
				for (int xr=kr;xr>=0;xr--) {
					int r2=v[rc][xr];
					if (r2<=l) break;
					chkmin(ans, f[l][r2-1] + f[r2][r]);
				}
			}
			f[l][r]=ans;
			//printf("l:%d r:%d f:%d\n",l,r,f[l][r]);
		}
	}
	printf("%d\n",max(0,f[1][n]-1));
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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
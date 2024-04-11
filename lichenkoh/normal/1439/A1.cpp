#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int mn=104;
vvi a;
vpii final;

void go(pii p) {
	final.PB(p);
	a[p.fst][p.snd]^=1;
}

void solve(int sx, int sy) {
	vpii v[2];
	for (int x=sx;x<sx+2;x++) {
		for (int y=sy;y<sy+2;y++) {
			v[a[x][y]].PB(MP(x,y));
		}
	}
	int cnt=v[1].size();
	if (cnt==0) return;
	else if (cnt==3) {
		for (int i=0;i<3;i++) go(v[1][i]);
		return;
	}
	else if (cnt==2) {
		for (int i=0;i<2;i++) go(v[0][i]);
		go(v[1][0]);
		solve(sx,sy);
		return;
	} else if (cnt==1) {
		go(v[1][0]);
		for (int i=0;i<2;i++) go(v[0][i]);
		solve(sx,sy);
		return;
	}
	else if (cnt==4) {
		for (int i=0;i<3;i++) go(v[1][i]);
		solve(sx,sy);
		return;
	}
	else {
		assert(0);
	}
}

void test() {
	a.clear(); final.clear();
	int xlim,ylim; cin>>xlim>>ylim;
	a.resize(xlim);
	for (int x=0;x<xlim;x++) {
		a[x].resize(ylim);
		string s; cin>>s;
		for (int y=0;y<ylim;y++) {
			a[x][y]=(s[y]-'0');
		}
	}
	for (int x=0;x<xlim-1;x+=2) for (int y=0;y<ylim-1;y+=2) {
		solve(x,y);
	}
	if (xlim%2) {
		for (int y=0;y<ylim-1;y+=2) {
			solve(xlim-2,y);
		}
	}
	if (ylim%2) {
		for (int x=0;x<xlim-1;x+=2) {
			solve(x, ylim-2);
		}
	}
	if ((xlim%2==1) && (ylim%2==1)) {
		solve(xlim-2,ylim-2);
	}
	int sz=final.size();
	assert(sz%3==0);
	printf("%d\n",sz/3);
	for (int q=0;q<sz;q+=3) {
		for (int i=q;i<q+3;i++) {
			printf("%d %d ",final[i].fst+1,final[i].snd+1);
		}
		printf("\n");
	}

}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) test();
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
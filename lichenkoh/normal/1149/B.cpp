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
const int mn=(1e5)+4;
const int mc=32;
string s;
int nx[mn][mc];

const int mx=256;
int dp[mx][mx][mx];
vector<char> t[3];

int f(array<int,3> const& x) {
	int dpval=dp[x[0]][x[1]][x[2]];
	if (dpval!=-1) return dpval;
	int final=INF;
	for (int r=0;r<3;r++) {
		if (x[r]>0) {
			array<int,3> y=x;
			--y[r];
			int cand=f(y);
			if (cand<INF) {
				int ans=nx[cand][t[r][y[r]]];
				chkmin(final,ans);
			}
		}
	}
	dp[x[0]][x[1]][x[2]]=final;
	return final;
}

void reset(int r, int q) {
	if (r==0) {
		memset(dp[q],-1,sizeof dp[q]);
	} else if (r==1) {
		for (int x=0;x<mx;x++) memset(dp[x][q],-1,sizeof dp[x][q]);
	} else {
		for (int x=0;x<mx;x++) for (int y=0;y<mx;y++) dp[x][y][q]=-1;
	}
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,q; cin>>n>>q>>s;
  for (int c=0;c<mc;c++) nx[n][c]=INF;
  for (int i=n-1;i>=0;i--) {
  	memcpy(nx[i],nx[i+1],sizeof nx[0]);
  	nx[i][s[i]-'a']=i+1;
  }
  memset(dp,-1,sizeof dp);
  for (int qi=0;qi<q;qi++) {
  	string op; int r; cin>>op>>r;
  	--r;
  	if (op[0]=='+') {
  		string inpc; cin>>inpc;
  		char c=inpc[0]-'a';
  		t[r].PB(c);
  	} else {
  		reset(r, t[r].size());
  		t[r].pop_back();
  	}
		dp[0][0][0]=0;
		array<int,3> x;
		for (int k=0;k<3;k++) x[k]=t[k].size();
		int ans=f(x);
		printf(ans<INF?"YES\n":"NO\n");
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
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
const int mn=10,mc=52;
using vvvi = vector<vvi>;
char h[128],invh[128];
vvvi nxt;
vvi pos2cnt;
vvvi cnt2pos;
int n;
vector<string> a;
int dp[mc][1<<mn];
pii pre[mc][1<<mn];
int f(int c, int z) {
	if (dp[c][z]!=-1) return dp[c][z];
	int vpos[mn];
	for (int x=0;x<n;x++) {
		int pos=cnt2pos[(z>>x)&1][x][c];
		vpos[x]=pos;
		if (pos==-1) {return dp[c][z]=-INF;}
	}
	pair<int,pii> ans=MP(0,MP(-1,-1));
	for (int e=0;e<mc;e++) {
		int nz=0;
		for (int x=0;x<n;x++) {
			int pos=nxt[x][vpos[x]+1][e];
			if (pos==INF) {nz=-1; break;}
			int cnt=pos2cnt[x][pos];
			nz|=cnt<<x;
		}
		if (nz!=-1) {
			chkmax(ans, MP(f(e,nz),MP(e,nz)));
		}
	}
	pre[c][z]=ans.snd;
	return dp[c][z]=ans.fst + 1;
}

void go() {
	nxt.clear();
	pos2cnt.clear();
	cnt2pos.clear();
	cin>>n;
	a.resize(n);
	for (int x=0;x<n;x++) {
		cin>>a[x];
		for (int y=0;y<a[x].length();y++) {
			a[x][y]=h[a[x][y]];
		}
	}
	nxt.resize(n);
	pos2cnt.resize(n);
	cnt2pos.resize(2,vvi(n,vi(mc,-1)));
	for (int x=0;x<n;x++) {
		int len=a[x].length();
		int next=INF;
		nxt[x].resize(len+1);
		nxt[x][len].resize(mc,INF);
		for (int y=len-1;y>=0;y--) {
			nxt[x][y]=nxt[x][y+1];
			nxt[x][y][a[x][y]]=y;
		}
		pos2cnt[x].resize(len);
		vi vcnt(mc);
		for (int y=0;y<len;y++) {
			char c=a[x][y];
			pos2cnt[x][y]=vcnt[c];
			cnt2pos[vcnt[c]][x][c] = y;
			vcnt[a[x][y]]++;
		}
	}
	memset(dp,-1,sizeof dp);
	pair<int,pii> final=MP(0,MP(-1,-1));
	for (int c=0;c<mc;c++) {
		{
			int z=0;
			chkmax(final, MP(f(c,z), MP(c,z)));
		}
	}
	printf("%d\n",final.fst);
	pii cz=final.snd;
	for (int i=0;i<final.fst;i++) {
		printf("%c",invh[cz.fst]);
		//printf("%c c:%d z:%d\n",invh[cz.fst],cz.fst,cz.snd);
		cz=pre[cz.fst][cz.snd];
	}
	printf("\n");
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int k=0;
  for (char c='a';c<='z';c++) {invh[k]=c; h[c]=k++;}
  for (char c='A';c<='Z';c++) {invh[k]=c; h[c]=k++;}
  int t; cin>>t; for (int i=0;i<t;i++) go();
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
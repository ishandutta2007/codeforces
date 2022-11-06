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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

vector<vvi> splitgraph(vvi const & g) {
	vector<vvi> res;
	int n=g.size();
	vvi dg(n);
	for (int x=0;x<n;x++) {
		for (int y:g[x]) {
			dg[x].PB(y); dg[y].PB(x);
		}
	}
	vector<bool> seen(n,false);
	for (int init=0;init<n;init++) {
		if (seen[init]) continue;
		seen[init]=true;
		vi v; v.PB(init);
		queue<int> q; q.push(init);
		while(!q.empty()) {
			int x=q.front(); q.pop();
			for (int y:dg[x]) {
				if (!seen[y]) {
					seen[y]=true;
					q.push(y);
					v.PB(y);
				}
			}
		}
		sort(v.begin(),v.end());
		vvi h(v.size());
		for (int xi=0;xi<v.size();xi++) {
			int x=v[xi];
			for (int y:g[x]) {
				int yi=bins(v,y);
				h[xi].PB(yi);
			}
		}
		res.PB(h);
	}
	return res;
}
const int mn=20;

int solve(vvi const & g) {
	int n=g.size();
	vi gin(n);
	for (int x=0;x<n;x++) {
		int z=0;
		for (auto &y:g[x]) { z|=1<<y; }
		gin[x]=z;
	}
	int zlim=1<<n;
	vi f(zlim,INF);
	for (int x=0;x<n;x++) f[1<<x]=0;
	for (int z=0;z<zlim;z++) {
		if (f[z]==INF) continue;
		for (int x=0;x<n;x++) {
			if (z&(1<<x)) continue;
			int cand=f[z]+1;
			if (gin[x]&z) cand++;
			chkmin(f[z|(1<<x)], cand);
		}
	}
	return f[zlim-1];
}

void go() {
	vvi gin(mn);
	string a,b;
	int slen; cin>>slen>>a>>b;
	for (int i=0;i<slen;i++) {
		int x=a[i]-'a',y=b[i]-'a';
		if (x!=y) gin[y].PB(x);
	}
	vector<vvi> gs=splitgraph(gin);
	int final=0;
	for (auto &g: gs) {
		int ans=solve(g);
		final+=ans;
	}
	printf("%d\n",final);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
const int mn=250001;
int dlim;
ll fbase;
int dp[mn];
vector<vector<pii> > g,origh;
vector<vector<pii> > outg;
vvi vq;
vector<vector<ll> > vs;
vi order;
bitset<mn> seen;
void dfs(int x, int p) {
	seen[x]=true;
	for (auto &edge:g[x]) {
		int y=edge.fst;
		if (y!=p) {
			outg[x].PB(edge);
			dfs(y,x);
		}
	}
	order.PB(x);
}
void f(int x) {
	vector<int> v; v.reserve(outg[x].size());
	ll ans=0;
	for (auto &w:outg[x]) {
		int y=w.fst; int c=w.snd;
		int ytake=c-dp[y];
		if (ytake>0) {
			v.PB(ytake);
		}
	}
	if ((int)(vq[x].size()+v.size()) <= dlim-1) {
		if (vs[x].size()) ans+=vs[x].back();
		for (auto &w:v) ans+=w;
		dp[x]=0;
		fbase+=ans;
		return;
	}
	sort(v.begin(),v.end(),greater<int>());
	if (vq[x].size()==0) {
		for (int i=0;i<min(dlim-1,(int)v.size());i++) {
			ans+=v[i];
		}
		if ((dlim-1)<(int)v.size()) {
			dp[x]=v[dlim-1];
		}
	} else if (v.size()==0) {
		auto &q=vq[x];
		int qir=min(dlim-1,(int)q.size());
		ans+=vs[x][qir];
		if ((dlim-1)<(int)q.size()) {
			dp[x]=q[dlim-1];
		}
	}
		else {
		int want=dlim-1;
		v.PB(0);
		int vmin=0,vmax=min(want,(int)v.size());
		auto &q=vq[x];
		while(vmin<vmax) {
			int vmid=(vmin+vmax)/2;
			int thresh=v[vmid];
			// Take everything greater than thresh
			int has=vmid;
			//if (thresh<INT_MAX) {
				int qmin=0,qmax=min((int)q.size(),want-vmid);
				while(qmin<qmax) {
					int qmid=(qmin+qmax)/2;
					if (q[qmid]>thresh) qmin=qmid+1;
					else qmax=qmid;
				}
				has+=qmin;
			//}
			if (has<want) vmin=vmid+1;
			else vmax=vmid;
		}
		// Take v[0..vmin-1]. Then take remainder from q.
		int rem=want; int vidx;
		for (vidx=0;vidx<vmin;vidx++) {ans+=v[vidx]; if (v[vidx]) rem--;}
		//assert(rem>=0);
		int qir=min(rem,(int)q.size());
		ans+=vs[x][qir];
		int hi=0;
		if (vidx<v.size()) chkmax(hi,v[vidx]);
		if (qir<q.size()) chkmax(hi,q[qir]);
		dp[x]=hi;
	}
	fbase+=ans+dp[x];
}
int old2new[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); g.resize(n+1);
  int slim=min(n,4);
  ll total=0;
  for (int i=1;i<n;i++) {
  	int a=rint(),b=rint(),c=rint();
  	g[a].PB(MP(b,c)); g[b].PB(MP(a,c));
  	total+=c;
  }
  origh=g;
	order.clear(); order.reserve(n);
  outg.clear(); outg.resize(g.size()); vq.resize(g.size()); vs.resize(g.size());
  for (int x=1;x<=n;x++) {seen[x]=false;}
  for (int x=1;x<=n;x++) {if (!seen[x]) {dfs(x,-1);}}
  printf("%lld ",total);
  for (dlim=1;dlim<slim;dlim++) {
  	fbase=0;
  	for (auto &x:order) {f(x);}
  	printf("%lld ",total-fbase);
  }
  while(slim<n) {
  	int nslim=min(n,slim*2);
  	//printf("slim:%d nslim:%d\n",slim,nslim);
	  g.clear();
	  vi new2old; new2old.PB(-1);
	  for (int x=1;x<=n;x++) if (origh[x].size()>slim) new2old.PB(x);
	  int newlim=((int)new2old.size())-1;
		memset(old2new,-1,sizeof old2new);
		for (int y=1;y<=newlim;y++) old2new[new2old[y]]=y;
		g.resize(newlim+1);
		vq.clear(); vq.resize(g.size()); vs.clear(); vs.resize(g.size());
		ll base=0;
		for (int ox=1;ox<=n;ox++) {
			for (auto &edge:origh[ox]) {
				int oy=edge.fst,cost=edge.snd;
				if (ox<oy) {
					int nx=old2new[ox],ny=old2new[oy];
					//printf("nx:%d ny:%d cost:%d\n",nx,ny,cost);
					if (nx==-1&&ny==-1) base+=cost;
					else if (nx==-1) vq[ny].PB(cost);
					else if (ny==-1) vq[nx].PB(cost);
					else {
						//printf("Adding to g\n");
						g[nx].PB(MP(ny,cost));
						g[ny].PB(MP(nx,cost));
					}
				}
			}
		}
		for (int y=1;y<=newlim;y++) {
			sort(vq[y].begin(),vq[y].end(),greater<int>());
			int sz=vq[y].size();
			vs[y].resize(sz+1);
			for (int i=0;i<sz;i++) {vs[y][i+1]=vs[y][i]+vq[y][i];}
		}
		order.clear(); order.reserve(n);
	  outg.clear(); outg.resize(g.size());
	  for (int x=1;x<=newlim;x++) {seen[x]=false;}
	  for (int x=1;x<=newlim;x++) {if (!seen[x]) {dfs(x,-1);}}
	  for (dlim=slim;dlim<nslim;dlim++) {
	  	fbase=0;
	  	for (auto &x:order) {f(x);}
	  	printf("%lld ",total-fbase-base);
	  }
	  slim=nslim;
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
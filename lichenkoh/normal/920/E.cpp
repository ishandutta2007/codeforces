#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=200001;
int vx[mn];
int vy[mn];
int bins(const vector<int> &vbin, int key) {
	int imin=0,imax=vbin.size();
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		if (vbin[imid]<key) imin=imid+1;
		else imax=imid;
	}
	if (imin<vbin.size()&&vbin[imin]==key) return imin;
	return -1;
}
const int ms=sqrt(mn)+1;
bitset<ms> g[ms];
class UnionFind {
	static const int mx=ms;
  typedef int UFTYPE;
public:
  UFTYPE ufIdentity = -1;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return x+y;
  }
  inline UFTYPE getInitialValue(int x) {
    return 1;
  }
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  int getDataFast(int x) {
    return ufData[x];
  }
};
UnionFind uf;
vector<int> h[mn];
bitset<mn> seen;
bitset<mn> lob;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
  	int x=rint(),y=rint();
  	h[x].PB(y); h[y].PB(x);
  	vx[i]=x; vy[i]=y;
  }
  for (int x=1;x<=n;x++) sort(h[x].begin(),h[x].end());
  pii lop=MP(INF,INF);
  for (int x=1;x<=n;x++) {chkmin(lop,MP((int)(h[x].size()),x));}
  int lox=lop.snd;
//printf("lox:%d\n",lox);
	for (auto &y:h[lox]) lob[y]=true;
	queue<int> q; for (int x=1;x<=n;x++) if (!lob[x]) {q.push(x); seen[x]=true;}
	vi f[2]; f[0]=h[lox];
	int cur=0;
	while(!q.empty()) {
		int nxt=cur^1;
		f[nxt].clear();
		int x=q.front(); q.pop();
		for (auto &y:f[cur]) {
			if (seen[y]) continue;
			if (bins(h[x],y)!=-1) {
				//printf("x:%d y:%d OK\n",x,y);
				f[nxt].PB(y);
			}
			else {
				q.push(y);
				seen[y]=true;
			}
		}
		cur^=1;
	}


	vector<int> vbin=f[cur];
	sort(vbin.begin(),vbin.end());
	//for (auto &w:vbin) printf("%d ",w); printf("\n");
	//printf("lox:%d\n",lox);
	int slim=vbin.size();
	for (int x=0;x<slim;x++) g[x].set();
	for (int i=0;i<m;i++) {
		int ox=vx[i],oy=vy[i];
		int x=bins(vbin, ox); if (x==-1) continue;
		int y=bins(vbin, oy); if (y==-1) continue;
		//printf("ox:%d oy:%d x:%d y:%d\n",ox,oy,x,y);
		if (x<y) swap(x,y);
		g[x][y]=false;
	}
	uf.init(slim);
	for (int x=0;x<slim;x++) {
		for (int y=g[x]._Find_first();y<x;y=g[x]._Find_next(y)) {
			//printf("x:%d y:%d\n",x,y);
			uf.funion(x,y);
		}
	}
	vi vans;
	vans.PB(n-vbin.size());
	for (int x=0;x<slim;x++) {
		int r=uf.ffind(x);
		if (r==x) {
			vans.PB(uf.getDataFast(r));
		}
	}
	printf("%d\n",(int)(vans.size()));
	sort(vans.begin(),vans.end());
	for (auto &w:vans) printf("%d ",w);
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
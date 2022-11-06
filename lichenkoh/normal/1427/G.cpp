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
 template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

int n;
int valsz;
vi vval;
int getv(int x, int y) {
	assert(1<=x&&x<=n-2);
	assert(1<=y&&y<=n-2);
	return (x-1)*(n-2) + y;
}

/*
void pr(int id) {
	int l=getv(n-2,n-2,valsz-1);
	if (id==l+1) {printf(" (src) "); return;}
	if (id==l+2) {printf(" (des) "); return;}
	int k=id%valsz;
	id/=valsz;
	int y=id%(n-2);
	id/=n-2;
	int x=id;
	printf(" (x:%d y:%d k:%d val:%d) ",x,y,k,vval[k]);
}
*/

template<typename C, typename T> struct Dinic {
	struct edge {
		int a, b; C cap; T flow;
	};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
*/
int dinic_numnodes, dinic_src, dinic_dest;
vector<edge> dinic_edge;
vi d, ptr, q;
vvi dinic_graph;
void init(int numnodes) {
	d.resize(numnodes); ptr.resize(numnodes); q.resize(numnodes); dinic_graph.resize(numnodes);
	dinic_numnodes = numnodes;
}
int addEdge (int a, int b, C cap) {
	//pr(a); pr(b); printf(" cap:%lld\n",cap);
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	int id=(int) dinic_edge.size();
	dinic_graph[a].push_back (id);
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((int) dinic_edge.size());
	dinic_edge.push_back (e2);
	return id;
}
void addEdgeBi(int a, int b, C cap) {
	//pr(a); pr(b); printf(" cap:%lld\n",cap);
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, cap, 0 };
	int id=(int) dinic_edge.size();
	dinic_graph[a].push_back (id);
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((int) dinic_edge.size());
	dinic_edge.push_back (e2);
}

void rmEdge(int id) {
	dinic_edge[id].cap=0;
}

void resetFlow() {
	for (auto &e: dinic_edge) e.flow=0;
}

T getEdgeFlow(int id) {
	return dinic_edge[id].flow;
}

bool dinic_bfs() {
	int qh=0, qt=0;
	q[qt++] = dinic_src;
	fill(d.begin(),d.end(),-1);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			int id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[dinic_dest] != -1;
}
 
T dinic_dfs (int v, T flow) {
	if (!flow)  return 0;
	if (v == dinic_dest)  return flow;
	for (; ptr[v]<(int)dinic_graph[v].size(); ++ptr[v]) {
		int id = dinic_graph[v][ptr[v]],
			to = dinic_edge[id].b;
		if (d[to] != d[v] + 1)  continue;
		T pushed = dinic_dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
		if (pushed) {
			dinic_edge[id].flow += pushed;
			dinic_edge[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

T dinic(int src, int dest, T maxf) {
	if (src==dest) return maxf;
	dinic_src = src;
	dinic_dest = dest;
	T flow = 0;
	while(flow<maxf) {
		if (!dinic_bfs())  break;
		fill(ptr.begin(),ptr.end(),0);
		while (T pushed = dinic_dfs (dinic_src, maxf-flow)) {
			flow += pushed;
		}
	}
	return flow;
}
void dinic_clear() {
	dinic_edge.clear();
	for (int v=0;v<dinic_numnodes;v++) dinic_graph[v].clear();	
}

T reverseFlow(int id) {
	T ret=0;
	if (dinic_edge[id].flow>0) {
		int old_src=dinic_src, old_dest=dinic_dest;
		int a=dinic_edge[id].a;
		ret=dinic(a,old_src,dinic_edge[id].flow);
		//printf("ret:%d flow:%d\n",ret,dinic_edge[id].flow); fflush(stdout);
		assert(ret==dinic_edge[id].flow);
		dinic_src=old_src; dinic_dest=old_dest;
		dinic_edge[id].flow=0;
		dinic_edge[id^1].flow=0;
	}
	return ret;
}

};

const int mn=202;

int a[mn][mn];
int eid[mn][mn];
Dinic<int,int> D;
enum {
	DOSRC,DODEST
};
const int mk=4*mn;
vector<pair<pii,pii> > k2ev[mk];
vi k2id[mk];
void proc(int sx, int sy, int rx, int ry) {
	if (a[rx][ry]==0) {
		k2ev[bins(vval, a[sx][sy])].PB(MP(MP(sx,sy),MP(rx,ry)));
	}
}

void doop(int type,int k,int src,int dest, pii s, pii r) {
	int sx=s.fst,sy=s.snd; int rx=r.fst,ry=r.snd;
	if (a[rx][ry]==0) {
		if (type==DOSRC) {
			D.addEdge(src,getv(rx,ry),1);
		} else {
			int id=D.addEdge(getv(rx,ry),dest,1);
			k2id[k].PB(id);
		}
	}
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
  	a[x][y]=rint();
  	if (a[x][y]>0) vval.PB(a[x][y]);
  }
  ll initScore=0;
  for (int x=1;x<n;x++) {
  	initScore += abs(a[x][0]-a[x-1][0]);
  	initScore += abs(a[0][x]-a[0][x-1]);
  	initScore += abs(a[x][n-1]-a[x-1][n-1]);
  	initScore += abs(a[n-1][x]-a[n-1][x-1]);
  }
  makeunique(vval);
  valsz=int(vval.size())-1;
  int src=getv(n-2,n-2)+1;
  int dest=src+1;
  ll final=0;
	D.init(dest+1);
  for (int x=1;x<=n-2;x++) for (int y=1;y<=n-2;y++) {
  	int vnow=getv(x,y);
  	if (a[x][y]==-1) continue;
  	assert(a[x][y]==0);
  	if (x+1<=n-2 && a[x+1][y]==0) {
  		int vo=getv(x+1,y);
  		D.addEdgeBi(vnow, vo, 1);
  	}
  	if (y+1<=n-2 && a[x][y+1]==0) {
  		int vo=getv(x,y+1);
  		D.addEdgeBi(vnow, vo, 1);
  	}
  }

  for (int x=1;x<=n-2;x++) {
		proc(x,0,x,1);
		proc(0,x,1,x);
		proc(x,n-1,x,n-2);
		proc(n-1,x,n-2,x);
  }
  for (int k=1;k<=valsz;k++) {
  	for (auto &ev:k2ev[k]) {
  		doop(DODEST,k,src,dest,ev.fst,ev.snd);
  	}
  }
  int lastFlow=0;
  for (int k=0;k<valsz;k++) {
		for (auto &ev: k2ev[k]) {
			doop(DOSRC,k,src,dest,ev.fst,ev.snd);
		}
		if (k>0) {
			for (auto id:k2id[k]) {
				lastFlow-=D.reverseFlow(id);
				D.rmEdge(id);
			}
		}
		//D.resetFlow();

	  int newFlow=D.dinic(src,dest,INT_MAX);
	  lastFlow+=newFlow;
	  //printf("k:%d newFlow:%d klo:%d k2ignore[k]:%d\n",k,newFlow,klo,k2ignore[k]);
	  final+=lastFlow * ll(vval[k+1]-vval[k]);
	}
  final+=initScore;
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
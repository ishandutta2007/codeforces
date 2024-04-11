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

struct edge {
	int a, b, cap, flow;
};
template<int MAXG> class Dinic {
public:
	/*
	Set
	dinic_numnodes: number of nodes
	dinic_src: Source vertex
	dinic_dest: Target vertex
	No need to initialize anything else. Run ge.clear() and dinic_graph.clear() between runs.
	*/
	int dinic_numnodes, dinic_src, dinic_dest, d[MAXG], ptr[MAXG], q[MAXG];
	vector<edge> dinic_edge;
	vector<int> dinic_graph[MAXG];
	 
	void addEdge (int a, int b, int cap) {
		//printf("%lld->%lld:%lld\n",a,b,cap);
		edge e1 = { a, b, cap, 0 };
		edge e2 = { b, a, 0, 0 };
		dinic_graph[a].push_back ((int) dinic_edge.size());
		dinic_edge.push_back (e1);
		dinic_graph[b].push_back ((int) dinic_edge.size());
		dinic_edge.push_back (e2);
	}

	void addEdgeBi(int a, int b, int cap) {
		//printf("%d <-> %d\n",a,b);
		addEdge(a,b,cap);addEdge(b,a,cap);
	}

	bool dinic_bfs() {
		int qh=0, qt=0;
		q[qt++] = dinic_src;
		memset (d, -1, dinic_numnodes * sizeof d[0]);
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
	 
	int dinic_dfs (int v, int flow) {
		if (!flow)  return 0;
		if (v == dinic_dest)  return flow;
		for (; ptr[v]<(int)dinic_graph[v].size(); ++ptr[v]) {
			int id = dinic_graph[v][ptr[v]],
				to = dinic_edge[id].b;
			if (d[to] != d[v] + 1)  continue;
			int pushed = dinic_dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
			if (pushed) {
				dinic_edge[id].flow += pushed;
				dinic_edge[id^1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
	 
	int maxflow(int src, int dest, int numnodes) {
		if (src==dest) return INF;
		dinic_src = src;
		dinic_dest = dest;
		dinic_numnodes = numnodes;
		int flow = 0;
		for (;;) {
			if (!dinic_bfs())  break;
			memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
			while (int pushed = dinic_dfs (dinic_src, INF))
				flow += pushed;
		}
		return flow;
	}
	void dinic_clear(int numnodes) {
		dinic_edge.clear();
		for (int v=0;v<numnodes;v++) dinic_graph[v].clear();	
	}
};
const int mn=304;
Dinic<mn*mn+3> D;
int rn,cn;
int f(int r, int c) {
	return r*cn + c;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>rn>>cn;
  vector<string> a(rn);
  int HOR=rn*cn+1;
  int VER=rn*cn+2;
  int GN=VER+1;
  for (int r=0;r<rn;r++) {
  	cin>>a[r];
  }
  //printf("HOR:%d VER:%d\n",HOR,VER);
  for (int r=0;r<rn;r++) {
  	for (int c=0;c<cn;c++) {
  		int v=f(r,c);
  		assert(a[r][c]=='#'||a[r][c]=='.');
  		if (a[r][c]=='#') {
  			if (c-1<0 || a[r][c-1]=='.') {
  				D.addEdgeBi(v,VER,1);
  			} else {
  				assert(a[r][c-1]=='#');
  				D.addEdgeBi(v, f(r,c-1),1);
  			}
  			if (c+1>=cn || a[r][c+1]=='.') {
  				D.addEdgeBi(v,VER,1);
  			}

  			if (r-1<0 || a[r-1][c]=='.') {
  				D.addEdgeBi(v,HOR,1);
  			} else {
  				assert(a[r-1][c]=='#');
  				D.addEdgeBi(v, f(r-1,c),1);
  			}
  			if (r+1>=rn || a[r+1][c]=='.') {
  				D.addEdgeBi(v,HOR,1);
  			}
  		}
  	}
  }
  int flow=D.maxflow(HOR,VER,GN);
  //printf("flow:%d\n",flow); return 0;
  assert(flow%2==0);
  int ans=flow/2;
  printf("%d\n",ans);
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
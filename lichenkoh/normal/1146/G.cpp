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
const int INF=(1<<30)-2;
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

class Dinic {
public:
	typedef int FT;
	const FT DINF=INF;
	struct edge {
		int a, b; FT cap, flow;
	};
	int dinic_numnodes, dinic_src, dinic_dest; vi d, ptr, q; vector<edge> dinic_edge;
	vvi dinic_graph;

	void add_edge (int a, int b, FT cap) {
		//printf("%d->%d:%d\n",a,b,cap);
		int c=max(a,b); if (c>=(int)dinic_graph.size()) dinic_graph.resize(c+1);
		edge e1 = { a, b, cap, 0 };
		edge e2 = { b, a, 0, 0 };
		dinic_graph[a].push_back ((int) dinic_edge.size());
		dinic_edge.push_back (e1);
		dinic_graph[b].push_back ((int) dinic_edge.size());
		dinic_edge.push_back (e2);
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
	 
	FT dinic_dfs (int v, FT flow) {
		if (!flow)  return 0;
		if (v == dinic_dest)  return flow;
		for (; ptr[v]<(int)dinic_graph[v].size(); ++ptr[v]) {
			int id = dinic_graph[v][ptr[v]],
				to = dinic_edge[id].b;
			if (d[to] != d[v] + 1)  continue;
			FT pushed = dinic_dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
			if (pushed) {
				dinic_edge[id].flow += pushed;
				dinic_edge[id^1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
	 
	FT get_flow(int src, int dest, int numnodes=-1) {
		if (src==dest) return DINF;
		if (numnodes==-1) numnodes = max(max(src,dest)+1,(int)dinic_graph.size());
		d.resize(numnodes); ptr.resize(numnodes); q.resize(numnodes);
		dinic_src = src;
		dinic_dest = dest;
		dinic_numnodes = numnodes;
		FT flow = 0;
		for (;;) {
			if (!dinic_bfs())  break;
			fill(ptr.begin(),ptr.end(),0);
			while (FT pushed = dinic_dfs (dinic_src, DINF))
				flow += pushed;
		}
		return flow;
	}
	void reset(int numnodes=-1) {
		if (numnodes==-1) numnodes = (int)dinic_graph.size();
		dinic_edge.clear();
		for (int v=0;v<numnodes;v++) dinic_graph[v].clear();	
	}
};
Dinic D;
int n,hlim,m;
int posH(int pos, int h) {assert(pos>=1&&h>=1);return m+(pos-1)*hlim+(h-1);}
int con(int c) {return c;}
void assert_unique(vi v) {
	sort(v.begin(),v.end()); for (int i=1;i<v.size();i++) assert(v[i]!=v[i-1]);
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),hlim=rint(),m=rint();
  int src=posH(n,hlim)+1; int dest=src+1;
  {
  	vi tmp;
  	for (int pos=1;pos<=n;pos++) for (int h=1;h<=hlim;h++) tmp.PB(posH(pos,h));
  	for (int c=0;c<m;c++) tmp.PB(con(c));
  	tmp.PB(src); tmp.PB(dest);
  	assert_unique(tmp);
  }
  for (int pos=1;pos<=n;pos++) {
  	for (int h=hlim;h>=2;h--) D.add_edge(posH(pos,h),posH(pos,h-1),INF);
  	for (int h=hlim;h>=1;h--) D.add_edge(src,posH(pos,h),2*h-1);
  }
//printf("CONS\n");
  for (int c=0;c<m;c++) {
  	int l=rint(),r=rint(),x=rint(),cost=rint();
  	if (x+1>hlim) continue;
  	for (int pos=l;pos<=r;pos++) {D.add_edge(posH(pos,x+1),con(c),INF);}
  	D.add_edge(con(c),dest,cost);
  }
  int f=D.get_flow(src,dest);
  //printf("f:%d\n",f);
  int all=n*(hlim*hlim);
  int ans=all-f;
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
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

typedef unsigned long long ull;
const LL INF = 1e18;
const int N = 1005,M = 70;
int n,m,w[N],val[N],S,T,a[N],b[N];
int id[N],tmp[N],ans[N];
list<int> G[N];
list<int>::iterator it,itt;
namespace Flow {
	const int N = ::N + 5,M = ::N * ::M * 2;
	int fir[N],to[M],nxt[M],cnt = 1,d[N],cur[N];
	LL fl[M];
	I addedge(int u,int v,LL f) {
		to[++cnt] = v;
		fl[cnt] = f;
		nxt[cnt] = fir[u];
		fir[u] = cnt;
	}
	I addflow(int u,int v,LL f) {
		addedge(u,v,f); addedge(v,u,0);
//		cout << u << ' ' << v << ' ' << f << endl;
	}
	I clear(int l,int r) {
		cnt = 1;
		fr(i,l,r) fir[id[i]] = 0;
		fir[S] = fir[T] = 0;
	}
	inline int bfs(int l,int r) {
		queue<int> q; d[S] = 0; q.push(S);
		fr(i,l,r) d[id[i]] = -1,cur[id[i]] = fir[id[i]];
		d[T] = -1; cur[S] = fir[S],cur[T] = fir[T];
		while(!q.empty()) {
			int u = q.front(); q.pop();
			foredge(i,u,v) if(fl[i] && d[v] == -1)
				q.push(v),d[v] = d[u] + 1;
		}
		return d[T] != -1;
	}
	LL Dinic(int u,LL flow) {
		if(u == T) return flow;
		LL rest = flow;
		for(int i = cur[u],v;v = to[i],(i && rest);i = nxt[i]) {
			cur[u] = i;
			if(fl[i] && d[v] == d[u]+1) {
				LL res = Dinic(v,min(rest,fl[i]));
				fl[i] -= res,fl[i^1] += res,rest -= res;
			}
		}
		return flow-rest;
	}
	bool vis[N];
	inline int solve(int l,int r) {
		fr(i,l,r) vis[id[i]] = 1;
		fr(i,l,r) for(it = G[id[i]].begin();it != G[id[i]].end();)
			if(vis[*it]) addflow(id[i],*it,INF),++it;
			else itt = it,++it,G[id[i]].erase(itt);
		fr(i,l,r) if(val[id[i]] >= 0)
			addflow(S,id[i],val[id[i]]);
		else addflow(id[i],T,-val[id[i]]);
		while(bfs(l,r)) while(Dinic(S,INF));;
		clear(l,r); int pl = l-1,pr = r+1;
		fr(i,l,r) if(d[id[i]] == -1) tmp[++pl] = id[i];
		else tmp[--pr] = id[i];
		fr(i,l,r) vis[id[i] = tmp[i]] = 0;
		return pl;
	}
}
void solve(int l,int r,int L,int R) {
	if(l > r) return;
	int mid = L + R >> 1;
	fr(i,l,r) val[id[i]] = -(abs(w[id[i]]-(mid+1))-abs(w[id[i]]-mid));
	int md = Flow::solve(l,r);
	if(L == R-1) {
		fr(i,l,md) ans[id[i]] = L;
		fr(i,md+1,r) ans[id[i]] = R;
		return;
	}
	solve(l,md,L,mid),solve(md+1,r,mid,R);
}
I build();
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m; S = n+1,T = S+1;
	fr(i,1,n) cin >> w[i];
	build(); fr(i,1,n) id[i] = i; solve(1,n,0,(int)(1e9));
	fr(i,1,n) cout << ans[i] << ' ';
	return 0;
}
bool mk[N];
I build() {
	for(int i = 1,u,v;i <= m;++i)
		cin >> u >> v,G[u].push_back(v);
}
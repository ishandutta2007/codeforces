# include <bits/stdc++.h>
using namespace std;


const int maxn = 2e5 + 10;
int fa[maxn], sz[maxn], dm[maxn];
int top(int x) { if(fa[x]==x) return x; return fa[x] = top(fa[x]); }

vector<int> g[maxn];
int n, m, q;

vector< int > dis[maxn];

short int inqr[maxn];
int dist[maxn];
int dd[maxn];
void bfs(int s) {
	int &dim = dm[s];
	auto &ds = dis[s];
	queue<int> q; q.push(s); dist[s] = 0; inqr[s]=1;
	while(!q.empty()) {
		int x = q.front(); q.pop();  s = x;
		for(auto y: g[x]) if(inqr[y]!=1) { inqr[y] = 1; q.push(y); }
	}

	q.push(s); dist[s] = 0; inqr[s]=2;
	while(!q.empty()) {
		int x = q.front(); q.pop(); s = x;
		for(auto y: g[x]) if(inqr[y]!=2) { 
			dist[y] = dist[x] + 1; 
			dd[y] = max(dist[y], dd[y]);
			inqr[y] = 2; q.push(y);
		}
	}

	dim = dist[s];
	ds.resize(dim + 1);
	for(int i = 0; i <= dim; ++i) ds[i] = 0;

	q.push(s); dist[s] = 0; inqr[s]=3;
	while(!q.empty()) {
		int x = q.front(); q.pop(); 
		for(auto y: g[x]) if(inqr[y]!=3) { 
			dist[y] = dist[x] + 1; 
			dd[y] = max(dist[y], dd[y]);
			inqr[y] = 3; q.push(y); 
		}
		ds[dd[x]] ++;
	}

	for(int i = dim - 1; i >= 0; --i) ds[i] += ds[i+1];
}

struct query {
	int l, r, id;
}qr[maxn];

bool cmp(query a,query b) {
	return make_pair(a.l, a.r) < make_pair(b.l, b.r);
}

double ans[maxn];

double calc(int u,int v) {
	int sa = dm[u], sb = dm[v];
	auto &a = dis[u], &b = dis[v];
	double ans = sa;

	for(int i = 0; i <= sb; ++i) {
		ans += (double) b[i] * a[sa - i] / sz[u] / sz[v];
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
	for(int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
		u = top(u); v = top(v); 
		if(u != v) fa[v] = u, sz[u] += sz[v];
	}
	for(int i = 1; i <= n; ++i) if(top(i) == i) bfs(i);
	for(int i = 0; i < q; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		u = top(u), v = top(v);
		if(dm[u] < dm[v]) swap(u, v);
		qr[i] = {u, v, i};
	}
	sort(qr, qr + q, cmp);
	for(int i = 0; i < q; ++i) {
		if(qr[i].l == qr[i].r) ans[qr[i].id] = -1;
		else if(i && qr[i-1].l==qr[i].l && qr[i-1].r == qr[i].r) ans[qr[i].id] = ans[qr[i-1].id];
		else ans[qr[i].id] = calc(qr[i].l, qr[i].r);
	}
	for(int i = 0; i < q; ++i) 
		printf("%.10lf\n", ans[i]);
	return 0;
}
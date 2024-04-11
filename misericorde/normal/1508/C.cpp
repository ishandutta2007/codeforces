#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 2222;
int n,m,u[maxn],v[maxn],w[maxn],rk[maxn],G[1005][1005],x[maxn],y[maxn],z[maxn],sum,tl;

namespace dsu {
	int fa[maxn];
	void reset() { std::memset(fa,0,sizeof(fa)); }
	int getf(int x) { return fa[x] ? fa[x] = getf(fa[x]) : x; }
	int merge(int x,int y) {
		x = getf(x); y = getf(y);
		if (x == y) return 0;
		fa[x] = y;
		return 1;
	}
}

namespace MST {
	int u[maxn],v[maxn],w[maxn],rk[maxn],tl;
	void reset() { tl = 0; }
	void add(int x,int y,int z) { 
		rk[++tl] = tl; u[tl] = x; v[tl] = y; w[tl] = z;
	}
	ll work() {
		ll ans = 0;
		dsu::reset();
		std::sort(rk+1,rk+tl+1,[](int a,int b) { return w[a] < w[b];});
		for (int i = 1; i <= tl; ++ i) {
			int x = u[rk[i]], y = v[rk[i]], z = w[rk[i]];
			ans += dsu::merge(x,y) * z;
		} return ans;
	}
}

ll find_useful() {
	dsu::reset();
	ll ans = 0;
	for (int i = 1; i <= m; ++ i) {
		int j = rk[i];
		if (dsu::merge(u[j],v[j])) { 
			x[++tl] = u[j]; y[tl] = v[j]; z[tl] = w[j];
			ans += z[tl];
		}
	} return ans;
}

std::set<int> s;
std::set<std::pair<int,int> > e;
int vis[maxn];
void bfs (int x,int lab)
{
    std::queue<int> q;
    s.erase(x);
    q.push(x);
    vis[x] = lab;
    while (q.size()){
        int u = q.front();
        q.pop();
        for (auto it = s.begin() ; it != s.end();){
            int v = *it++;
            if (e.count({u , v})) continue;
            s.erase(v);
            q.push(v);
            vis[v] = lab;
        }
    }
    return ;
}

int find_component() {
	for (int i = 1 ; i <= n ; i++) s.insert(i);
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) if (!vis[i]) { ans++; bfs(i,ans); }
    return ans;
}

ll work() {
	dsu::reset();
	ll ans = 0;
	for (int i = 1; i <= m; ++ i) {
		int x = u[rk[i]], y = v[rk[i]], z = w[rk[i]];
		x = vis[x]; y = vis[y];
		ans += z * dsu::merge(x,y);
	} return ans;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		e.insert({u[i],v[i]});
        e.insert({v[i],u[i]});
		rk[i] = i;
		sum ^= w[i];
	} std::sort(rk + 1, rk + m + 1,[](int a,int b) { return w[a] < w[b]; });
	int cnt = find_component();
//	printf(">%d\n",cnt);
	ll full = (ll) n * ( n - 1 ) / 2;
	if ((ll) n - ( full - m ) != cnt) { printf("%lld",work()); return 0; }
	else {
		ll ans = 1e18;
		assert(n <= 1000);
		for (int i = 1; i <= m; ++ i) 
			G[u[i]][v[i]] = G[v[i]][u[i]] = 1; 
		for (int i = 1; i <= n; ++ i) 
			for (int j = i + 1; j <= n; ++ j) 
				if (!G[i][j]) { x[++tl] = i; y[tl] = j; z[tl] = 0; }
		int ed = tl;
		find_useful();
		for (int i = 1; i <= ed; ++ i) {
			MST::reset();
			for (int j = 1; j <= tl; ++ j) {
				if (j != i) MST::add(x[j],y[j],z[j]);
				else MST::add(x[j],y[j],sum);
			} ans = std::min(ans,MST::work());
		} 
		printf("%lld",ans);
	}				
	return 0;
}
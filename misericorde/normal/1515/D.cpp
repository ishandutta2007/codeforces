#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
int n,l,r,c[maxn][2];

void solve() {
	scanf("%d%d%d",&n,&l,&r);
	for (int i = 1; i <= n; ++ i) {
		c[i][0] = c[i][1] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		int x;
		scanf("%d",&x);
		int d = (i > l);
		if (c[x][d^1]) c[x][d^1] --;
		else c[x][d] ++;
	} 
	std::priority_queue<std::pair<int,int> > L,R;
	auto ins = [&](int x) {
		if (c[x][0]) L.push({c[x][0]%2,x});
		if (c[x][1]) R.push({c[x][1]%2,x});
	};
	for (int i = 1; i <= n; ++ i) {
		ins(i);
	} 
	while (L.size() && R.size()) {
		if (L.size() && R.size()) {
			auto p = L.top(); L.pop();
			auto q = R.top(); R.pop();
			int u = p.second;
			int v = q.second;
			c[u][0] --;
			c[v][1] --;
			ans ++;
			ins(u);
			ins(v);
		} 
	} int cw = 0;
	while (L.size()) {
		auto u = L.top().second; L.pop();
		cw += c[u][0] % 2;
		ans += c[u][0] / 2;
	} while (R.size()) {
		auto u = R.top().second; R.pop();
		cw += c[u][1] % 2;
		ans += c[u][1] / 2;
	} ans += cw;
			
	printf("%d\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}
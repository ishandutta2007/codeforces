#include <bits/stdc++.h>

using pii = std::pair<int,int>;
int sum,dis[505][505],n,c[505],k;
std::pair<pii,pii>pre[505][505];
std::vector<int>v[2];

void bfs() {
	std::queue<pii>q;
	std::memset(dis,63,sizeof(dis));
	dis[n][0] = 0;
	q.push({n,0});
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		int v0 = u.first, v1 = u.second;
	//	printf("<%d %d>\n",v0,v1);
		assert(v0 + v1 == n);
		for (int i = 0; i <= v0 && i <= k; ++ i) {
			int j = k - i;
			if (j > v1) continue;
			int x = v0 - i + j;
			int y = v1 - j + i;
		//	printf("-> %d %d\n",x,y);
			if (dis[x][y] > dis[v0][v1] + 1) {
				dis[x][y] = dis[v0][v1] + 1;
				pre[x][y] = {{v0,v1},{i,j}};
				q.push({x,y});
			}
		}
	}
}

int query(std::vector<int>g) {
	printf("? ");
	for (int x:g) printf("%d ",x);
	puts("");
	for (int x:g) {
		v[c[x]].erase(std::find(v[c[x]].begin(),v[c[x]].end(),x));
		c[x] ^= 1;
		v[c[x]].push_back(x);
	} 
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}

void output(int x,int y) {
	if (x == n && y == 0) return ;
	auto P = pre[x][y];
	int i = P.first.first, j = P.first.second;
	int c0 = P.second.first, c1 = P.second.second;
	output(i,j);
	std::vector<int>g;
	for (int i = 0; i < c0; ++ i) g.push_back(v[0][i]);
	for (int i = 0; i < c1; ++ i) g.push_back(v[1][i]);
	sum ^= query(g);
}

int main() {
	scanf("%d%d",&n,&k);
	bfs();
	if (dis[0][n] > 5000) {
		puts("-1"); 
		fflush(stdout);
		return 0;
	} for (int i = 1; i <= n; ++ i) v[0].push_back(i); 
	output(0,n);
	assert(v[1].size() == n);
	printf("! %d",sum);
	fflush(stdout);
	return 0;
}
# include <vector>
# include <cstring>
# include <map>
# include <set>
# include <algorithm>
# include <vector>

using namespace std;

map< vector<int> , int > hs;

const int maxn = 100010;
int dep[maxn];
vector<int> G[maxn];

int Id(vector<int> vec) {
	static int cnt = 0;
	sort(vec.begin(), vec.end());
	if(hs.count(vec) == 0) 
		hs[vec] = cnt++;
	return hs[vec];
}

int f[maxn][2];
int get(int u,int v) {
	int &val = f[dep[u] > dep[v] ? u : v][dep[u] > dep[v]];
	if(val != -1) return val;
	vector<int> vec;
	for (auto p: G[u]) if(p != v) vec.push_back(get(p, u));
	return val = Id(vec);
}

void dfs(int u,int par) {
	dep[u] = dep[par] + 1;
	for(auto v: G[u]) if(v != par) dfs(v, u);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 1);
	vector<int> vec;
	int val = Id(vec);
	memset(f, -1, sizeof(f));
	set<int> S;
	for(int i = 1; i <= n; ++i) {
		if(G[i].size() < 4) {
			vec.clear();
			vec.push_back(val);
			for(auto u: G[i]) 
				vec.push_back(get(u, i));
			S.insert(Id(vec));
		}
	}
	printf("%d\n", (int)S.size());
	return 0;
}
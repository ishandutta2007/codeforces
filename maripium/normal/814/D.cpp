#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
const double PI = acos(-1);

int n;
int x[N], y[N], r[N];
int par[N];
vector<int> child[N];
int f[N][2][2];
 
bool contain(int u, int v) {
    return (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]) <= (r[u] - r[v]) * (r[u] - r[v]);
}

void dfs(int u) {
	int g[2][2] = {{ 0 }};
	for (int i = 0;i < child[u].size();++i) {
		int v = child[u][i];
		dfs(v);
		for (int j = 0;j < 2;++j) 
			for (int k = 0;k < 2;++k) 
				g[j][k] += f[v][j][k];
	}
	
	for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            f[u][i][j] = std::max(
                g[i ^ 1][j] + r[u] * r[u] * (i == 0 ? 1 : -1),
                g[i][j ^ 1] + r[u] * r[u] * (j == 0 ? 1 : -1)
            );
        }
}

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;++i) cin >> x[i] >> y[i] >> r[i];
	for (int i = 0; i < n; ++i) {
        par[i] = -1;
        for (int j = 0; j < n; ++j)
            if (r[j] > r[i] && contain(i, j)) {
                if (par[i] == -1 || r[par[i]] > r[j]) par[i] = j;
            }
        if (par[i] >= 0) child[par[i]].push_back(i);
    }
	
	int ans = 0;
	for (int i = 0;i < n;++i) if (par[i] == -1) {
		dfs(i);
		ans += f[i][0][0];
	}
	cout << fixed << setprecision(8) << (double) ans * PI << endl;
	
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//	ordered_set<int> s;

const int INF = (1 << 20);
int n, c, dp[110][110], dp2[110][110], cp[110], cp2[110];
int odl[110], p[110], odw[110];
vector <int> g[110];
vector <int> ans;

//void dfs(int w) {
	//for (int x : g[w]) {
		//dfs(x);
	//}
	//for (int i = 0; i <= n; ++i) {
		//dp[w][i] = INF;
		//dp2[w][i] = INF;
	//}
	//dp[w][1] = 0;
	//dp2[w][1] = 0;
	//for (int x : g[w]) {
		//for (int i = 0; i <= n; ++i) {
			//cp[i] = INF;
			//cp2[i] = INF;
		//}
		//for (int i = 1; i <= n; ++i) { // ile w w
			//for (int j = 1; j <= i; ++j) { // ile w x
				//cp[i] = min(cp[i], dp[w][i - j] + dp[x][j] + 2);
				//cp2[i] = min(cp2[i], dp[w][i - j] + dp2[x][j] + 1);
			//}
		//}
		//for (int i = 0; i <= n; ++i) {
			//dp[w][i] = min(dp[w][i], cp[i]);
			//dp2[w][i] = min(dp2[w][i], cp2[i]);
		//}
	//}
//}

void dfs(int w, int o) {
	odl[w] = o;
	for (int x : g[w]) {
		dfs(x, o + 1);
	}
}

void gen(int w) {
	if (c == 0) {
		return;
	}
	if (!odw[w]) {
		--c;
	}
	ans.push_back(w);
	for (int i : g[w]) {
		if (c == 0) {
			return;
		}
		if (!odw[i]) {
			ans.push_back(w);
			gen(i);
			ans.push_back(w);
		}
	}
}

void solve() {
	int k;
	scanf("%d%d", &n, &k);
	c = k;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
	for (int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		p[i] = x;
		g[x].push_back(i);
	}
	dfs(1, 0);
	//printf("%d\n", min(dp[1][k], dp2[1][k]));
	
	int ww = 0;
	int wo = 0;
	for (int i = 1; i <= n; ++i) {
		if (odl[i] + 1 <= k) {
			if (odl[i] + 1 > wo) {
				ww = i;
				wo = odl[i] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		odw[i] = 0;
	}
	int x = ww;
	vector <int> v;
	while (x != 1) {
		v.push_back(x);
		odw[x] = 1;
		x = p[x];
		--c;
	}
	v.push_back(1);
	odw[1] = 1;
	--c;
	reverse(v.begin(), v.end());
	ans.clear();
	for (int i : v) {
		ans.push_back(i);
		gen(i);
	}
	vector <int> ans2;
	ans2.clear();
	ans2.push_back(ans[0]);
	for (int i = 1; i < (int)ans.size(); ++i) {
		if (ans[i] != ans[i - 1]) {
			ans2.push_back(ans[i]);
		}
	}
	printf("%d\n", (int)ans2.size() - 1);
	for (int y : ans2) {
		printf("%d ", y);
	}
	printf("\n");
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
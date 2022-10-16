#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 100100;

int n, m;
bool iscat[maxn];
bool mk[maxn];
vi ady[maxn];

int dfs(int s, int tc){
	mk[s] = true;

	if (iscat[s]) ++tc;
	else tc = 0;

	int ans = 0;

	if (tc > m) ans = 0;
	else if (s != 1 && ady[s].size() == 1) ans = 1;
	else{
		for (auto nx : ady[s]){
			if (mk[nx]) continue;
			ans += dfs(nx, tc);
		}
	}

	// cout << s << " " << ans << endl;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int v; cin >> v;
		iscat[i + 1] = v == 1;
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	int ans = dfs(1, 0);
	// if (ady[1].size() == 1) ++ans;
	cout << ans << endl;

	return 0;
}
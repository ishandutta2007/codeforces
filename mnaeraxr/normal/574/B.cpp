#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 5010;

int rec[maxn];
bool kn[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pii> lst(m);
	for (int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		rec[u]++; rec[v]++;
		lst[i] = {u, v};
		kn[u][v] = kn[v][u] = true;
	}

	int ans = -1;

	for (int i = 0; i < m; ++i){
		int u = lst[i].first, v = lst[i].second;
		for (int j = 1; j <= n; ++j){
			if (!kn[j][u] || !kn[j][v]) continue;
			int val = rec[u] + rec[v] + rec[j] - 6;
			if (ans == -1 || val < ans) ans = val;
		}
	}

	cout << ans << endl;

	return 0;
}
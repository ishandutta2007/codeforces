#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000 + 10;

bool mk[maxn];
vi adj[maxn];

pii dfs(int s){
	mk[s] = true;
	pii ans(1, (int)adj[s].size());
	for (auto v : adj[s]){
		if (!mk[v]){
			pii cur = dfs(v);
			ans.first += cur.first;
			ans.second += cur.second;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i){
		if (!mk[i]){
			pii cur = dfs(i);
			if ( (cur.first - 1) * 2 == cur.second) ++ans;
		}
	}

	cout << ans << endl;


	return 0;
}
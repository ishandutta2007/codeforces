#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int nval[6010];
pii val[6010];

vi ady[6010];
pair<int,pii> data[6010];
bool mk[6010];

int dfs(int s, int from, int val){
	mk[s] = true;

	int ans = 0;

	if (nval[s] < val){
		ans = data[s].second.second;
		if (from != data[s].first)
			ans = data[s].second.first;
	}

	for (auto e : ady[s]){
		if (mk[e]) continue;
		int cur = dfs(e, s, val);
		ans = max(ans, cur);
	}

	return ans;
}

void update(int s){
	memset(mk, 0, sizeof mk);
	mk[s] = true;
	data[s] = {-1, {1, 1}};

	for (auto e : ady[s]){
		int cur = dfs(e, s, nval[s]) + 1;
		if (cur > data[s].second.first){
			data[s] = {e, {cur, data[s].second.first}};
		}
		else if (cur > data[s].second.second){
			data[s].second.second = cur;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;	
	for (int i = 1; i <= n; ++i){
		cin >> nval[i];
		val[i] = {nval[i], i};
		data[i] = {-1, {0, 0}};
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	sort(val + 1, val + n + 1);

	int ans = 0;

	for (int i = 1; i <= n; ++i){
		update(val[i].second);
		ans = max(ans, data[val[i].second].second.first);
		// cout << val[i].first << " " << val[i].second << endl;
		// auto tmp = data[val[i].second];
		// cout << tmp.first << " " << tmp.second.first << " " << tmp.second.second << endl;
		// cout << "------" << endl;
	}

	cout << ans << endl;

	return 0;
}
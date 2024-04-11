#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200 * 1000 + 10;

bool team[N];
int max_size[N];
int size[N];
vector<int> g[N];

void dfs(int v, int p) {
	size[v] = team[v] ? 1 : 0;
	for (int to : g[v])
		if (to != p) {
			dfs(to, v);
			size[v] += size[to];
			max_size[v] = max(max_size[v], size[to]);
		}
}

vector<int> cur;

void dfs2(int v, int p) {
	if (team[v])
		cur.push_back(v);
	for (int to : g[v])
		if (to != p)
			dfs2(to, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	k *= 2;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		team[x] = true;
	}
	dfs(0, 0);
	int v = -1;
	int tot = size[0];
	assert (tot == k);
	for (int i = 0; i < n; i++) 
		if ((tot - size[i]) * 2 <= tot && max_size[i] * 2 <= tot)
			v = i;
	assert (v >= 0);
	cout << 1 << " " << v + 1 << "\n";
	if (team[v]) {
		cur.push_back({v});
	}
	for (int to : g[v]) 
		dfs2(to, v);
	assert (cur.size() == k);
	for (int i = 0; i < k / 2; i++)
		cout << cur[i] + 1 << " " << cur[i + k / 2] + 1 << " " <<  v + 1 << "\n"; 
}
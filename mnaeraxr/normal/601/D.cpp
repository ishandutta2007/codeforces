#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 300001;

int trie[maxn][26], tTrie;

int c[maxn];
string nodeValue;
vi adj[maxn];

int nodeTrieId[maxn];
int curNode;

pii query[maxn];

void dfs(int s, int f, int ptrie){
	int b = curNode;

	// Trie update
	int cval = nodeValue[s] - 'a';
	if (!trie[ptrie][cval])
		trie[ptrie][cval] = tTrie++;
	ptrie = trie[ptrie][cval];

	for (auto u : adj[s]) if (u != f){
		dfs(u, s, ptrie);
	}

	int e = curNode++;
	nodeTrieId[e] = ptrie;
	query[e] = make_pair(b, c[s]);
}

int last[maxn];
int bit[maxn];

void update(int idx, int val){
	while (idx < maxn){
		bit[idx] += val;
		idx += idx & -idx;
	}
}

int read(int idx){
	int ans = 0;
	while (idx){
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	cin >> nodeValue;

	for (int i = 1; i < n; ++i){
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	tTrie = 1;
	curNode = 0;
	dfs(0, -1, 0);

	int ans1 = 0;
	int ans2 = 0;

	for (int i = 0; i < n; ++i){
		int begin = query[i].first;
		int cValue = query[i].second;
		cValue += read(i) - read(begin);

		if (cValue > ans1) ans1 = cValue, ans2 = 0;
		if (cValue == ans1) ++ans2;

		int curElement = nodeTrieId[i];
		if (last[curElement]) update(last[curElement], -1);
		last[curElement] = i + 1;
		update(i + 1, 1);
	}

	cout << ans1 + 1 << endl;
	cout << ans2 << endl;

	return 0;
}
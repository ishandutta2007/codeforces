#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int was[1200];
vector<vector<int>> go[1200];
vector<int> tmp2;
int n;
vector<pair<int, int> > ed;
int sz[1200];
char s[120000];

vector<int> dfs1(int v) {
	if (was[v]) {
		cout << -1 << "\n";
		exit(0);
	}
	was[v] = 1;
	vector<int> cur;
	cur.push_back(v);
	for (int i = 0; i < go[v].size(); ++i) {
		if (go[v][i][0] == 0)
			continue;
		int bst = go[v][i][0];
		for (int j: go[v][i])
			if (sz[j] > sz[bst])
				bst = j;
		ed.push_back(make_pair(v, bst));
		vector<int> tmp = dfs1(bst);
		if (tmp != go[v][i]) {
			cout << -1 << "\n";
			exit(0);
		}
		tmp2.clear();
		merge(cur.begin(), cur.end(), tmp.begin(), tmp.end(), back_inserter(tmp2));
		cur = tmp2;
	}
	return cur;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", s);
		int len = strlen(s);
		vector<int> tmp;
		int cur = 0;
		while (cur < len) {
			int ad = 0;
			int k;
			tmp.clear();
			sscanf(s + cur, "%d:%n", &k, &ad);
			cur += ad;
			for (int j = 0; j < k; ++j) {
				int x;
				sscanf(s + cur, "%d%n", &x, &ad);
				--x;
				tmp.push_back(x);
				cur += ad;
				if (j != k - 1)
					++cur;
			}
			sort(tmp.begin(), tmp.end());
			go[i].push_back(tmp);
			if (tmp[0] != 0)
				sz[i] += tmp.size();
			if (cur != len) {
				++cur;
			}
		}
	}
	dfs1(0);
	cout << n - 1 << "\n";
	for (int i = 0; i < ed.size(); ++i) {
		cout << ed[i].first + 1 << " " << ed[i].second + 1 << "\n";
	}
	return 0;
}
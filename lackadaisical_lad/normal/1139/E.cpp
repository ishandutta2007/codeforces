// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 5001;
int used[N], mt[N];
vector<int> g[N];

bool go(int v) {
	if (used[v])  return 0;
	used[v] = 1;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || go(mt[to])) {
			mt[to] = v;
			return 1;
		}
	}
	return 0;
}
 
void mex(int& ans) {
	int prev;
	do {
		prev = ans;
		fill(used, used + N, 0);
		ans += go(ans);
	} while(ans > prev);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	fill(mt, mt + m, -1);
	vector<int> p(n), c(n);
	for (int& i : p) {
		cin >> i;
	}
	for (int& i : c) {
		cin >> i;
		i--;
	}
	int d;
	cin >> d;
	vector<int> kek(d), lol(n);
	for (int& i : kek) {
		cin >> i;
		i--;
		lol[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!lol[i]) {
			g[p[i]].push_back(c[i]);
		}
	}
	int ans = 0;
	reverse(kek.begin(), kek.end());
	vector<int> result;
	for (int i : kek) {
		mex(ans);
		result.push_back(ans);
		g[p[i]].push_back(c[i]);
	}
	reverse(result.begin(), result.end());
	for (int i : result) {
		cout << i << endl;
	}
	return 0;
}
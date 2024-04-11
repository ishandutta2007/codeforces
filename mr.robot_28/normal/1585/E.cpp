#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N = 2e6 + 100;
const int mod = 998244353;
int a[N];
vector <int> g[N];
int pref[N];
vector <vector <int> > queries[N];
int coun[N];
int ans[N];
int n, q;
int get(int x, int k) {
	int l = -1, r = n;
	while (r - l > 1) {
		int midd = (r + l) / 2;
		if (pref[midd] - pref[x - 1] >= k) {
			r = midd;
		}
		else {
			l = midd;
		}
	}
	if (pref[r] - pref[x - 1] < k) {
		return -1;
	}
	return r;
}
vector <int> vec[N];
void dfs(int v) {
	pref[coun[a[v]]]--;
	coun[a[v]]++;	
	vec[coun[a[v]]].push_back(a[v]);
	for (auto to : g[v]) {
		dfs(to);
	}
	for (auto query : queries[v]) {
		int idx = get(query[0], query[1]);
		if (idx == -1) {
			ans[query[2]] = -1; 
		}
		else {
			while (coun[vec[idx].back()] != idx) {
				vec[idx].pop_back();
			}
			ans[query[2]] = 1 + vec[idx].back();
		}
	}
	coun[a[v]]--;
	vec[coun[a[v]]].push_back(a[v]);
	pref[coun[a[v]]]++;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			vec[0].push_back(a[i]);
		}
		for (int i = 0; i <= n; i++) {
			pref[i] = n;
		}
		for (int i = 1; i < n; i++) {
			int p;
			cin >> p;
			p--;
			g[p].push_back(i);
		}
		for (int i = 0; i < q; i++) {
			int v, l, k;
			cin >> v >> l >> k;
			v--;
			queries[v].push_back({l, k, i});
		}
		dfs(0);
		for (int i = 0; i < q; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i++) {
			g[i].clear();
			vec[i].clear();
			queries[i].clear();
		}
	}
	return 0;
}
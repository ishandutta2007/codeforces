#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

const int N = 1e5;
int comp[N];
int cou[N];

int coll(int i) {
	if (comp[i] != i) comp[i] = coll(comp[i]);
	return comp[i];
}

bool join(int a, int b) {
	a = coll(a);
	b = coll(b);
	if (a == b) return false;
	bool res = (cou[a] > 0) && (cou[b] > 0);
	comp[b] = a;
	cou[a] += cou[b];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> xs(k);
	for (int i = 0; i < k; ++i) {
		cin >> xs[i];
		--xs[i];
	}
	
	for (int i = 0; i < n; ++i) comp[i] = i;
	for (int j = 0; j < k; ++j) cou[xs[j]] = 1;

	vector<pair<ll, pair<int, int>>> edges(m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;
		edges[i] = {w, {a, b}};
	}
	sort(edges.begin(), edges.end());
	
	int cs = k;
	ll ans = -1;
	for (int i = 0; i < m; ++i) {
		if (join(edges[i].second.first, edges[i].second.second)) --cs;
		if (cs == 1) {
			ans = edges[i].first;
			break;
		}
	}

	for (int i = 0; i < k; ++i) cout << ans << ' '; cout << '\n';
}
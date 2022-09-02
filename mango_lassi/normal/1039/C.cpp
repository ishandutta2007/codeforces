#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

// If exactly one of the two servers gets infected by a virus with value keys[as[i]] ^ keys[bs[i]], we fail.
// for every xor-value, find all pairs that fail to that xor.
// for xors such that no edge fails, answer is 2^n
// for xors such that one edge fails, answer is 2^(n-1)
// answer is 2^(number of components).

const int MOD = 1e9 + 7;
const int N = 5 * (int)1e5;
const int M = 5 * (int)1e5;

ll keys[N];
int tps[N+1];

int group[N];
int siz[N];
vector<int> joins;

bool join(int a, int b) {
	while(group[a] != a) a = group[a];
	while(group[b] != b) b = group[b];
	if (a == b) return 0;
	
	if (siz[a] < siz[b]) swap(a, b);
	joins.push_back(b);

	siz[a] += siz[b];
	group[b] = a;
	return 1;
}

void undo() {
	int b = joins.back();
	int a = group[b];
	joins.pop_back();

	siz[a] -= siz[b];
	group[b] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	tps[0] = 1;
	for (int i = 1; i <= n; ++i) tps[i] = (tps[i-1] * 2) % MOD;
	for (int i = 0; i < n; ++i) {
		group[i] = i;
		siz[i] = 1;
	}

	for (int i = 0; i < n; ++i) cin >> keys[i];

	vector<pair<ll, pair<int, int>>> edges(m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edges[i] = {keys[a] ^ keys[b], {a, b}};
	}
	sort(edges.begin(), edges.end());
	
	// Count xors that appear
	ll res = 0;
	ll xors = 0;
	int i = 0;
	while(i < m) {
		++xors;

		ll v = edges[i].first;
		int groups = n;
		while((i < m) && (edges[i].first == v)) {
			groups -= join(edges[i].second.first, edges[i].second.second);
			++i;
		}
		while(joins.size() > 0) undo();
		res += tps[groups];
	}
	
	// Xors that didn't appear count 2^n times.
	ll full = (ll)1 << k;
	res += ((full - xors) % MOD) * tps[n];
	cout << res % MOD << '\n';
}
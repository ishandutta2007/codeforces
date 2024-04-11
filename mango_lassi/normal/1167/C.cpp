#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 5 * (int)1e5;
int gr[N];
int sz[N];

int coll(int i) {
	if (gr[i] != i) gr[i] = coll(gr[i]);
	return gr[i];
}
void join(int a, int b) {
	a = coll(a);
	b = coll(b);
	if (gr[a] == gr[b]) return;
	if (sz[a] < sz[b]) swap(a, b);
	gr[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		gr[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		if (k == 0) continue;
		int p;
		cin >> p;
		for (int j = 1; j < k; ++j) {
			int p2;
			cin >> p2;
			join(p-1, p2-1);
			p = p2;
		}
	}
	for (int i = 0; i < n; ++i) cout << sz[coll(i)] << ' '; cout << '\n';
}
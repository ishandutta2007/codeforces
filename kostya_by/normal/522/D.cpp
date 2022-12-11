#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 500500;
const int INF = 1000000000;

int n, q;
int a[MAXN];
int x[MAXN];
int y[MAXN];
pair<int, int> tmp[MAXN];

vector<int> tree[4 * MAXN];
vector<int> tree_prefix_min_x[4 * MAXN];

void calculate_x_y(int n, int a[]) {
	for (int i = 1; i <= n; i++) {
		tmp[i] = make_pair(a[i], i);
	}
	sort(tmp + 1, tmp + n + 1);
	int ptr = 1;
	while (ptr <= n) {
		int left = ptr;
		int right = ptr;
		while (true) {
			if (right == n) {
				break;
			}
			if (tmp[left].first != tmp[right + 1].first) {
				break;
			}
			++right;
		}
		for (int i = left; i < right; i++) {
			int pos = tmp[i].second;
			x[pos] = tmp[i + 1].second - tmp[i].second;
			y[pos] = tmp[i + 1].second;
		}
		x[tmp[right].second] = INF;
		y[tmp[right].second] = INF;
		ptr = right + 1;
	}
	// for (int i = 1; i <= n; i++) {
	// 	cerr << x[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	cerr << y[i] << " ";
	// }
	// cerr << "\n";
}

void build_tree(int v, int l, int r) {
	if (l == r) {
		tree[v].resize(1);
		tree_prefix_min_x[v].resize(1);
		tree[v][0] = l;
		tree_prefix_min_x[v][0] = x[l];
		return;
	}
	int _x = (l + r) / 2;
	build_tree(v + v, l, _x);
	build_tree(v + v + 1, _x + 1, r);
	tree[v].resize(tree[v + v].size() + tree[v + v + 1].size());
	tree_prefix_min_x[v].resize(tree[v + v].size() + tree[v + v + 1].size());
	merge(
		tree[v + v].begin(), tree[v + v].end(),
		tree[v + v + 1].begin(), tree[v + v + 1].end(),
		tree[v].begin(), 
		[](int a, int b) { 
			return y[a] < y[b]; 
		}
	);
	int mn_x = INF;
	for (int i = 0; i < tree[v].size(); i++) {
		mn_x = min(mn_x, x[tree[v][i]]);
		tree_prefix_min_x[v][i] = mn_x;
	}
	// cerr << v << " " << l << ":" << r << "\n";
	// for (int index : tree[v]) {
	// 	cerr << index << " ";
	// }
	// cerr << "\n";
}

int query_tree(int v, int l, int r, int ll, int rr) {
	if (l == ll && rr == r) {
		auto it = upper_bound(tree[v].begin(), tree[v].end(), n + 1, 
			[](int a, int b) {
				return y[a] < y[b];
			});
		if (it == tree[v].begin()) {
			return INF;
		}
		int pos = (int)(it - tree[v].begin()) - 1;
		return tree_prefix_min_x[v][pos];
	}
	int x = (l + r) / 2;
	int result = INF;
	if (ll <= x) {
		result = min(result, query_tree(v + v, l, x, ll, min(x, rr)));
	}
	if (x + 1 <= rr) {
		result = min(result, query_tree(v + v + 1, x + 1, r, max(ll, x + 1), rr));
	}
	return result;
}

void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	calculate_x_y(n, a);
	build_tree(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		y[n + 1] = r;
		int result = query_tree(1, 1, n, l, r);
		if (result == INF) {
			result = -1;
		}
		printf("%d\n", result);
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}
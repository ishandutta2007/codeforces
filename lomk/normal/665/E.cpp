/*input
3 1
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 1000005
#define bit(x,y) ((x>>y)&1LL)

int n, k;
int a[N];

namespace Trie {
	struct data {
		int child[2], cnt[2];
		data() {
			child[0] = child[1] = -1;
			cnt[0] = cnt[1] = 0;
		}
	};
	vector<data> tree;
	void getMore() {
		tree.resize(tree.size() + (1 << 20));
	}
	int peak = 0;
	void add(const int num) {
		int k = 0;
		for (int lev = 30; lev >= 0; lev--) {
			tree[k].cnt[bit(num, lev)]++;
			if (lev == 0) return;
			if (tree[k].child[bit(num, lev)] == -1) {
				if (peak + 5 > tree.size()) getMore();
				tree[k].child[bit(num, lev)] = ++peak;
			}
			k = tree[k].child[bit(num, lev)];
		}
	}
	int get(int k, int lev, const int num, const int lim) {
		if (k == -1) return 0;
		int ret = 0;
		if (bit(lim, lev) == 0) {
			if (bit(num, lev) == 0) {
				ret = tree[k].cnt[1];
				if (tree[k].child[0] == -1) ret += tree[k].cnt[0];
				else ret += get(tree[k].child[0], lev - 1, num, lim);
			}
			else {
				ret = tree[k].cnt[0];
				if (tree[k].child[1] == -1) ret += tree[k].cnt[1];
				else ret += get(tree[k].child[1], lev - 1, num, lim);
			}
		}
		else {
			if (bit(num, lev) == 0) {
				if (tree[k].child[1] == -1) ret = tree[k].cnt[1];
				else ret = get(tree[k].child[1], lev - 1, num, lim);
			}
			else {
				if (tree[k].child[0] == -1) ret = tree[k].cnt[0];
				else ret = get(tree[k].child[0], lev - 1, num, lim);
			}
		}
		return ret;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cur = 0;
	long long ans = 0;
	Trie::getMore();
	Trie::add(0);
	for (int i = 1; i <= n; i++) {
		cur ^= a[i];
		ans += Trie::get(0, 30, cur, k);
		Trie::add(cur);
	}
	cout << ans << endl;
}
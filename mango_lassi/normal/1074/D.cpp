#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;


unordered_map<int, int> par;
unordered_map<int, int> path_xor;

int comp(int i) {
	if (par[i] != i) {
		int t = comp(par[i]);
		path_xor[i] ^= path_xor[par[i]];
		par[i] = t;
	}
	return par[i];
}

void init(int i) {
	if (par.find(i) == par.end()) {
		par[i] = i;
		path_xor[i] = 0;
	}
}

void join(int a, int b, int x) {
	init(a);
	init(b);
	int r1 = comp(a);
	int r2 = comp(b);
	if (r1 == r2) return;
	par[r1] = r2;
	path_xor[r1] = path_xor[a] ^ path_xor[b] ^ x;
}

int get(int a, int b) {
	init(a);
	init(b);
	int r1 = comp(a);
	int r2 = comp(b);
	if (r1 != r2) return -1;
	return path_xor[a] ^ path_xor[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	int last = 0;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (r < l) swap(l, r);

			++r;
			join(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (r < l) swap(l, r);

			++r;
			last = get(l, r);
			cout << last << '\n';
			if (last == -1) last = 1;
		}
	}
}
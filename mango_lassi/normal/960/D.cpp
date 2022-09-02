#include <iostream>
using namespace std;
typedef long long ll;

const int K = 64;
ll node_shift[K];
ll val_shift[K];

ll map(ll val, ll shift, int lvl) {
	if (lvl == 0) return val;
	ll bs = ((ll)1)<<(lvl);
	val -= bs;
	val += shift;
	val %= bs;
	if (val < 0) val += bs;
	val += bs;
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	
	for (int j = 0; j < q; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x, k;
			cin >> x >> k;
			int lvl = 0;
			while(x > 1) {
				x >>= 1;
				++lvl;
			}
			val_shift[lvl] += k;
			val_shift[lvl] %= ((ll)1<<((ll)lvl));
			if (val_shift[lvl] < 0) {
				val_shift[lvl] += ((ll)1<<((ll)lvl));
			}
		} else if (t == 2) {
			ll x, k;
			cin >> x >> k;
			int lvl = 0;
			while(x > 1) {
				x >>= 1;
				++lvl;
			}
			node_shift[lvl] += k;
			node_shift[lvl] %= ((ll)1<<((ll)lvl));
			if (node_shift[lvl] < 0) {
				node_shift[lvl] += ((ll)1<<((ll)lvl));
			}
		} else {
			ll x;
			cin >> x;

			int lvl = 0;
			ll tmp = x;
			while(tmp > 1) {
				tmp >>= 1;
				++lvl;
			}

			x = map(x, val_shift[lvl], lvl);
			while(lvl > 0) {
				std::cout << map(x, -val_shift[lvl], lvl) << ' ';
				//std::cout << "node val val_shift: " << x << ' ' << map(x, -val_shift[lvl], lvl) << ' ' << val_shift[lvl] << '\n';
				//std::cout << "shift map: " << node_shift[lvl] << ' ' << map(x, node_shift[lvl], lvl) << '\n';
				x = map(x, node_shift[lvl], lvl) >> 1;
				--lvl;
			}
			std::cout << "1\n";
		}
	}
}
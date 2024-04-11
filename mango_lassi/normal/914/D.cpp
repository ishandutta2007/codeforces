#include <iostream>

const int inf = 1e9 + 7;
const int N = 5 * (1e5);
int seg[4*N];
int h;

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void count(int a, int b, int ia, int ib, int i, int x, int& r) {
	if (r >= 2) return;
	if (ib < a || b < ia) return;
	if (a <= ia && ib <= b) {
		if (gcd(seg[i], x) == x) {
			return;
		} else if (ia == ib) {
			++r;
			return;
		}
	}
	int mid = (ia + ib) >> 1;
	count(a, b, ia, 	mid, 	2 * i, 		x, r);
	count(a, b, mid + 1, 	ib, 	2 * i + 1, 	x, r);
}
void set(int i, int v) {
	i += h;
	seg[i] = v;
	while(i > 1) {
		i >>= 1;
		seg[i] = gcd(seg[2 * i], seg[2 * i + 1]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	h = 1;
	while(h < n) h <<= 1;

	for (int i = 0; i < n; ++i) {
		std::cin >> seg[i + h];
	}
	for (int i = h-1; i >= 1; --i) {
		seg[i] = gcd(seg[2*i], seg[2*i+1]);
	}

	int q;
	std::cin >> q;

	for (int i = 0; i < q; ++i) {
		int t;
		std::cin >> t;
		if (t == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			--l; --r;
			int res = 0;
			count(l, r, 0, h-1, 1, x, res);
			if (res >= 2) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
			}
		} else {
			int i, y;
			std::cin >> i >> y;
			set(i-1, y);
		}
	}	
}
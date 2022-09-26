#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

using point = pair<int, int>;
using rect = pair<point, point>;

int n, m;
long long f[2505][2505];
map<rect, long long> mp;

void upd(int a,int b, long long val) {
	for (int x = a; x <= n; x += x & -x) {
		for (int y = b; y <= m; y += y & -y) {
			f[x][y] ^= val;
		}
	}
}

int get(int a,int b) {
	long long ans = 0;
	for (int x = a; x > 0; x -= x & -x) {
		for (int y = b; y > 0; y -= y & -y) {
			ans ^= f[x][y];
		}
	}
	return ans;
}

int main() {
	int q;
	scanf("%d %d %d", &n, &m, &q);
	while (q--) {
		int op, lx, ly, rx, ry;
		scanf("%d %d %d %d %d", &op, &lx, &ly, &rx, &ry);
		if (op == 3) {
			puts(get(lx, ly) == get(rx, ry) ? "Yes" : "No"); 
		} else {
			long long &val = mp[rect(point(lx, ly), point(ly, ry))];
			if (op == 1) {
				val = rng();
			}
			upd(lx, ly, val);
			upd(lx, ry + 1, val);
			upd(rx + 1, ly, val);
			upd(rx + 1, ry + 1, val);
		}
	}
}
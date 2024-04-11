#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 1e9 + 123;

int n, m;
int pw[N], hs[15][N];
int pos[15][N];

int get(int id,int l,int r) {
	int ret = hs[id][r] - 1LL * hs[id][l - 1] * pw[r - l + 1] % mod;
	if (ret < 0) ret += mod; return ret; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) pw[i] = 1LL * pw[i - 1] * 1007 % mod;
	for (int id = 0; id < m; ++id) {
		hs[id][0] = 0;
		for (int i = 1; i <= n; ++i) {
			int x; cin >> x;
			pos[id][x] = i;
			hs[id][i] = (1LL * hs[id][i - 1] * 1007 % mod + x) % mod;
		}
	}
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		auto ok = [&](int len) {
			int val = -1;
			for (int id = 0; id < m; ++id) {
				if (pos[id][i] + len - 1 > n) return false;
				int cur = get(id, pos[id][i], pos[id][i] + len - 1);
				if (val == -1) val = cur;
				if (cur != val) return false;
			} 
			return true;
		};
		int low = 1, high = n;
		while (low < high) {
			int mid = (low + high + 1) >> 1;
			if (ok(mid)) low = mid;
			else high = mid - 1;
		}
		res += low;
	}
	cout << res << '\n';
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define repd(i, n) for (int i = n; i >= 1; --i)
using namespace std;

const int N = 1e6 + 1;

int n;
vector<int> cnt(N);
int ptr = 1, mx = 0;

vector<int> calc(int r,int c,int x,int y) {
	vector<int> ret(N, 0);
	if (x < 1 || y < 1 || x > r || y > c) return ret;
	rep(i, r) rep(j, c) ret[abs(i - x) + abs(j - y)]++;
	return ret;
}

void solve(int r,int c) {
	int x = ptr, y = mx + 1 - r + ptr;
	if (calc(r, c, x, y) == cnt) {
		cout << r << ' ' << c << '\n';
		cout << x << ' ' << y << '\n';
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		int x; cin >> x;
		cnt[x]++;
		mx = max(mx,x);
	}
	if (cnt[0] != 1) return cout << -1 << '\n',0;
	while (cnt[ptr] == 4 * ptr) ptr++;
	for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
		solve(i, n / i), solve(n / i, i);
	}
	cout << -1;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<18)
#define MOD 1000000007  //998244353
#define M -1000000000
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

int a[2][(2 * N)];
vector<int>b;
int rl[(2 * N)];
int rr[(2 * N)];
int sa, sb;

void init(void) {
	rep(i, 2 * N) {
		a[0][i] = M;
		a[1][i] = M;
	}
	rl[1] = 0;
	rr[1] = N;
	rep2(i, 1, N) {
		rl[(2 * i)] = rl[i];
		rr[(2 * i)] = (rl[i] + rr[i]) / 2;
		rl[(2 * i) + 1] = (rl[i] + rr[i]) / 2;
		rr[(2 * i) + 1] = rr[i];
	}
	return;
}
void update(int mode, int k, int val) {
	a[mode][N + k] = val;
	int x = (N + k) / 2;
	while (x >= 1) {
		a[mode][x] = max(a[mode][(2 * x)], a[mode][(2 * x) + 1]);
		x /= 2;
	}
	return;
}
int ma(int mode, int l, int r,int k) {
	if ((rl[k] >= l) && (r >= rr[k]))return a[mode][k];
	if ((rr[k] <= l) || (r <= rl[k]))return M;
	int vl = ma(mode, l, r, 2 * k);
	int vr = ma(mode, l, r, 2 * k + 1);
	return max(vl, vr);
}


int main() {
	int n;
	vector<pair<pii, bool> >c;
	int x, y, sz;
	bool v = true;
	cin >> n;
	rep(i, n) {
		cin >> x >> y;
		if ((x <= n) && (y > n)) {
			c.pb({ {x,y - n - 1},false });
		}
		else if ((y <= n) && (x > n)) {
			c.pb({ {y,x - n - 1},true });
		}
		else v = false;
	}
	if (!v) {
		cout << -1 << endl;
		return 0;
	}
	sort(all(c));
	init();
	if (c[0].second == false) {
		update(0, N - 1, 0);
		update(1, N - 1, 1);
	}
	else {
		update(0, N - 1, 1);
		update(1, N - 1, 0);
	}
	b.pb(N - 1);
	rep2(i, 1, n - 1) {
		if (c[i - 1].first.second < c[i].first.second) {
			x = ma(0, c[i].first.second + 1, N, 1);
			y = ma(1, c[i].first.second + 1, N, 1);
			x += sa;
			y += sb;
			sa = 0;
			sb = 0;
			sz = b.size();
			rep(j, sz) {
				update(0, b[j], M);
				update(1, b[j], M);
			}
			b.clear();
			if (c[i].second == false) {
				update(0, c[i - 1].first.second, y);
				update(1, c[i - 1].first.second, x + 1);
			}
			else {
				update(0, c[i - 1].first.second, y + 1);
				update(1, c[i - 1].first.second, x);
			}
			b.pb(c[i - 1].first.second);
		}
		else {
			x = ma(0, c[i].first.second + 1, N, 1);
			y = ma(1, c[i].first.second + 1, N, 1);
			update(0, c[i - 1].first.second, y + sb - sa);
			update(1, c[i - 1].first.second, x + sa - sb);
			if (c[i].second == false) sb += 1;
			else sa += 1;
			b.pb(c[i - 1].first.second);
		}
	}
	x = ma(0, 0, N, 1);
	y = ma(1, 0, N, 1);
	x += sa;
	y += sb;
	x = max(x, y);
	if (x < 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << n - x << endl;
	return 0;
}
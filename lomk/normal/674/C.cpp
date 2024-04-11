/*input
6 2
1 2 4 8 16 32
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] = "; coln(x);}
void _co() {} template<typename T, typename... Ts> void _co(const T& value, const Ts&... values) {cout << ' ' << value; _co(values...);} template<typename T, typename... Ts> void co(const T& value, const Ts&... values) {cout << value; _co(values...);} template<typename T, typename... Ts> void coln(const T& value, const Ts&... values) {cout << value; _co(values...); cout << endl;}
const int N = 200005;

int n, m;
double _sum[N]; int a[N];
double _invsum[N];

auto sum(int l, int r) {
	return _sum[r] - _sum[l - 1];
}
auto invsum(int l, int r) {
	return _invsum[r] - _invsum[l - 1];
}

struct State {
	int l, r, L, R;
	State(int _l, int _r, int _L, int _R): l(_l), r(_r), L(_L), R(_R) {};
};
void solve(double f[N], double pre[N]) {
	vector<State> q, nxt;
	q.push_back({1, n, 0, n});
	while (true) {
		nxt = vector<State>();
		int L = 1, R = 0; double cost = 0;
		for (auto &[l, r, fl, fr] : q) {
			int mid = (l + r) / 2; int fmid = -1;
			while (R < mid) {
				R++;
				cost += 1.0 * sum(L, R) / a[R];
				// debug(L, R, cost);
			}
			loop(i, fl, min(fr, mid - 1)) {
				while (L < i + 1) {
					cost -= invsum(L, R) * a[L];
					L++;
					// debug(L, R, cost);
				}
				if (pre[i] + cost < f[mid]) {
					f[mid] = pre[i] + cost;
					fmid = i;
				}
			}
			if (l <= mid - 1) nxt.push_back({l, mid - 1, fl, fmid});
			if (mid + 1 <= r) nxt.push_back({mid + 1, r, fmid, fr});
		}
		if (nxt.empty()) break;
		q.swap(nxt); nxt = vector<State>();
	}
}

double dp[52][N];
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	loop(i, 1, n) {
		cin >> a[i];
		_sum[i] = _sum[i - 1] + a[i];
		_invsum[i] = _invsum[i - 1] + 1.0 / a[i];
	}
	loop(i, 0, 51) fill(dp[i], dp[i] + N, 1e18);
	dp[0][0] = 0.0;
	loop(i, 1, m) solve(dp[i], dp[i - 1]);
	cout << setprecision(6) << fixed << dp[m][n] << endl;
}
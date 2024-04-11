#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e12;
const ld EPS = (ld)1 / INF;

const int N = 1e5;
ld ps[N];
ld vs[N];
ld best;

// x_t+k, with quest pv
ld advance(ld xt, ll k, int i) {
	pair<ld, ld> pv = {1 - ps[i], best - vs[i]};

	for (ll j = 1; j <= k; j <<= 1) {
		if (k & j) {
			xt = xt * pv.first + pv.second;
		}
		pv.second *= (1 + pv.first);
		pv.first *= pv.first;
	}
	
	return xt;
}

// Find min k such that x_t+k >= l or k == high_k, while we're picking option i until that happens
ll bins(ld xt, ld bound, ll high_k, int i) {
	ll low_k = 0;
	while(low_k != high_k) {
		ll mid = (low_k + high_k) >> 1;
		if (advance(xt, mid, i) >= bound) high_k = mid;
		else low_k = mid + 1;
	}
	return low_k;
}

// Collision point of two lines
ld collPoint(int a, int b) {
	// x = (vs[b]-vs[a]) / (ps[a]-ps[b])
	ld dp = ps[a] - ps[b];
	ld dv = vs[b] - vs[a];
	return dv / dp;
}

vector<int> hull; // Indexes in ps, vs
void addLine(int c) {
	if ((! hull.empty()) && (abs(ps[c] - ps[hull.back()]) < EPS)) {
		if (vs[hull.back()] > vs[c]) return;
		else hull.pop_back();
	}
	while(hull.size() >= 2) {
		int n = hull.size();
		int a = hull[n-2];
		int b = hull[n-1];

		if (collPoint(b, c) <= collPoint(a, b)) hull.pop_back();
		else break;
	}
	hull.push_back(c);
}


int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	*/

	// When we manage to upgrade a quest, upgrade the one that after upgrade gives the greatest expected return, and do that for the rest of the time.
	// At time t+1, quest i has expected return:
	// p_i (a_i + t * best) + (1 - pi) DP[t]

	// So we have:
	// DP[t+1] = max_i(p_i (a_i + t * best) + (1 - pi) DP[t])
	// 		= DP[t] + max_i(p_i (t * best - DP[t]) + p_i a_i)
	// 		= DP[t] + max_i(p_i x_t + v_i) (after setting x, a_i = a_i p_i)

	// x_t = t * best - DP[t] is increasing
	// 		why?
	// 		x_(t+1) - x_t = best - (DP[t+1] - DP[t]) = (DP[t] + best) - DP[t+1] >= 0
	//		Since getting to do the optimal quest cannot harm you

	// How does x_t change when i is constant? We'll just have to find the spot when x_t makes us want to switch to the next line
	//		x_t+1 = (t+1) * best - DP[t+1]
	// 			= x_t + (best + DP[t] - DP[t+1])
	// 			= x_t + (best + DP[t] - (DP[t] + pi x_t + v_i))
	// 			= x_t + best - pi x_t - v_i
	// 			= x_t (1 - pi) + best - v_i

	// We can calculate how the situation changes in k steps with matrix power:
	// 		[p 1]^k [x] = [y]
	// 		[0 1]   [v]   [v]
	// where:
	// 	p = 1 - pi
	// 	x = x_t
	// 	y = x_t+k
	// 	v = best - vi
	// 	res = [x_t+k v]

	// Once we know x_T, we have
	// 	ans = DP[T] = t*best - x_T
	// And we get our answer from that

	int n; ll t;
	cin >> n >> t;

	// Best is defined in global scope
	vector<pair<ld, int>> ord(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b >> ps[i];
		best = max(best, ps[i] * b);
		vs[i] = a * ps[i];

		ord[i] = {ps[i], i};
	}

	sort(ord.begin(), ord.end());
	for (int i = 0; i < n; ++i) addLine(ord[i].second);

	vector<ld> x_bounds(hull.size());
	x_bounds[0] = 0;
	for (int i = 1; i < hull.size(); ++i) {
		x_bounds[i] = collPoint(hull[i-1], hull[i]);
	}

	/*
	for (int i = 0; i < n; ++i) cout << ps[i] << ' ' << vs[i] << '\n';
	for (auto i : hull) cout << i << ' '; cout << '\n';
	for (int i = 0; i < hull.size(); ++i) cout << x_bounds[i] << ' '; cout << '\n';
	*/

	ll ct = 0;
	ld xt = 0; // x_0 = 0
	int j = 0; // ind in hull
	while((j+1 < hull.size()) && (x_bounds[j+1] <= xt)) {
		++j;
	}
	
	// Take hull[j] until next x_bounds
	while(ct < t) {
		ll k;
		if (j+1 < hull.size()) {
			k = bins(xt, x_bounds[j+1], t - ct, hull[j]);
		} else {
			k = t - ct;
		}
		// cout << ct << ' ' << xt << ' ' << j << ": " << k << '\n';

		xt = advance(xt, k, hull[j]);
		ct += k;
		++j;
	}

	ld ans = best * t - xt;
	cout << fixed << setprecision(10) << ans << '\n';
}
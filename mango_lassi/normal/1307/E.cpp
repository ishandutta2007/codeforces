#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = (int)1e9 + 7;

ll modAdd(ll a, ll b) {
	if (a+b >= MOD) return a+b - MOD;
	else return a+b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> sweetness(n);
	for (int& v : sweetness) cin >> v;

	vector<vector<pair<int, int>>> offs(n);
	for (int i = 0; i < m; ++i) {
		int s, h;
		cin >> s >> h;

		int a = 0;
		for (int need = h; a < n; ++a) {
			if (sweetness[a] == s) --need;
			if (need == 0) break;
		}

		int b = n-1;
		for (int need = h; b >= 0; --b) {
			if (sweetness[b] == s) --need;
			if (need == 0) break;
		}
		offs[s-1].push_back({a, b});
	}

	// No cow has same hunger and sweetness
	// -> We can pick any subset of cows for the left and right side, as long as they don't collide
	// First pick the maximum coordinate that some cow reaches from the left. How many ways are there to pick cows, such that
	// 1. We pick at least one cow reaching this coordinate from the left
	// 2. We pick only cows reaching at most this coordinate from the left, and at most this coordinate + 1 from the right
	
	// Grass does not grow back! We can only pick one cow of each type on both sides!
	// For each type of eater, count 

	vector<pair<int, ll>> res;
	for (int a = -1; a < n; ++a) {
		int cou = 0;
		ll v0 = (a != -1);
		ll v1 = (a == -1);
		for (auto& vec : offs) {
			ll dp[2][2][2];
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					for (int t = 0; t < 2; ++t) {
						dp[i][j][t] = 0;
					}
				}
			}
			dp[0][0][0] = v0;
			dp[0][0][1] = v1;

			for (auto pr : vec) {
				int le = (pr.first <= a) + (pr.first == a);
				int ri = (pr.second >= a+1);

				for (int i = 1; i >= 0; --i) {
					for (int j = 1; j >= 0; --j) {
						for (int t = 1; t >= 0; --t) {
							if (le && i) {
								if (le == 2 && t == 1) {
									dp[i][j][t] = modAdd(dp[i][j][t], modAdd(dp[0][j][0], dp[0][j][1]));
								} else if (le == 1) {
									dp[i][j][t] = modAdd(dp[i][j][t], dp[0][j][t]);
								}
							}
							if (ri && j) {
								dp[i][j][t] = modAdd(dp[i][j][t], dp[i][0][t]);
							}
						}
					}
				}
			}

			if (dp[1][1][0] || dp[1][1][1]) {
				cou += 2;
				v0 = dp[1][1][0];
				v1 = dp[1][1][1];
			} else if (dp[1][0][0] || dp[1][0][1] || dp[0][1][0] || dp[0][1][1]) {
				++cou;
				v0 = modAdd(dp[1][0][0], dp[0][1][0]);
				v1 = modAdd(dp[1][0][1], dp[0][1][1]);
			}
		}
		res.push_back({cou, v1});
	}
	sort(res.begin(), res.end());

	ll ans = 0;
	int mc = res.back().first;
	while(! res.empty() && res.back().first == mc) {
		ans = modAdd(ans, res.back().second);
		res.pop_back();
	}
	cout << mc << ' ' << ans << '\n';
}
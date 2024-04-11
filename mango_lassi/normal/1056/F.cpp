#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld INF = 1e18;
const ld MULT = (ld)1 / 0.9;
const int N = 100;
const int P = 10;
ld dp[N*P+1][N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n;
		cin >> n;

		ld coeff, tim;
		cin >> coeff >> tim;

		vector<pair<int, int>> ques(n);
		for (int i = 0; i < n; ++i) {
			cin >> ques[i].first >> ques[i].second;
		}
		sort(ques.begin(), ques.end());

		for (int s = 0; s <= n*P; ++s) {
			for (int i = 0; i <= n; ++i) {
				dp[s][i] = INF;
			}
		}
		dp[0][0] = 0;
		
		int psum = 0;
		for (int j = 0; j < n; ++j) {
			for (int s = psum; s >= 0; --s) {
				for (int i = 0; i <= j; ++i) {
					ld offer = (dp[s][i] + ques[j].first) * MULT;
					if (offer >= INF) continue;
					dp[s + ques[j].second][i + 1] = min(dp[s + ques[j].second][i + 1], offer);
				}
			}
			psum += ques[j].second;
		}
		int res = 0;
		
		for (int s = 0; s <= psum; ++s) {
			for (int i = 0; i <= n; ++i) {
				// Can we achieve this?
				// What is the optimal amount of training for this? If we train for k minutes, the time this takes is:
				ld d = i * 10 - tim;
				// We want:
				// i * 10 + k + dp[s][i] / (1 + Ck) <= t
				// k + d + dp[s][i] / (1 + Ck) <= 0
				// (1 + Ck)(k + d) + dp[s][i] <= 0
				// Ck^2 + (dC + 1)k + (d + dp[s][i]) <= 0
				// Does such a Ck exist?
				ld a = coeff;
				ld b = d * coeff + 1;
				ld c = d + dp[s][i];
				// ax^2 + bx + c <= 0
				// 2ax + b = 0
				// x = -b/2a

				ld x = max((ld)0, -b/(2*a));
				ld off = (a*x + b)*x + c;
				if ((a < 0) || (off <= 0)) res = max(res, s);
			}
		}
		
		cout << fixed << setprecision(10) << res << '\n';
	}
}
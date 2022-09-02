#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool check(const string& str, int i) {
	// BANS:
	// 0011
	// 0101
	// 1110
	// 1111

	if (str[i] == '0' && str[i+3] == '1' && (str[i+1] != str[i+2])) return false;
	else if (str[i] == '1' && str[i+1] == '1' && str[i+2] == '1') return false;
	return true;
}


// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

const ll MOD = (int)1e9 + 7;
ll mult1 = rand<int>(0, MOD-1);
ll mult2 = rand<int>(0, MOD-1);

vector<pair<ll, pair<int, int>>> hashes;

const int N = 3000 + 4;
ll dp[N];
int fi[N];

void updateHash(pair<int, int>& hash, char c) {
	int v = c - '0' + 1;
	hash.first = ((ll)hash.first * mult1 + v) % MOD;
	hash.second = ((ll)hash.second * mult2 + v) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	
	string str;
	for (int n = 1; n <= m; ++n) {
		char c;
		cin >> c;
		str.push_back(c);
	}

	for (int n = 1; n <= m; ++n) {
		pair<int, int> hash = {0, 0};
		for (int i = n-1; i >= 0; --i) {
			updateHash(hash, str[i]);
			ll packed_hash = hash.first + (ll)hash.second * MOD;
			hashes.push_back({packed_hash, {i, n-1}});
		}
	}
	
	sort(hashes.begin(), hashes.end());
	int r = 0;
	for (int j = 0; j+r < hashes.size(); ++j) {
		swap(hashes[j], hashes[j + r]);
		if (j > 0 && hashes[j].first == hashes[j-1].first) {
			++r;
			--j;
		}
	}

	for (int i = 0; i < m; ++i) fi[i] = -1;
	for (int j = 0; j+r < hashes.size(); ++j) {
		fi[hashes[j].second.second] = max(fi[hashes[j].second.second], hashes[j].second.first);
	}

	ll ans = 0;
	for (int n = 1; n <= m; ++n) {
		dp[n] = 1;
		dp[n+1] = 0;
		dp[n+2] = 0;
		dp[n+3] = 0;
		for (int i = n-1; i >= 0; --i) {
			// Update DP
			dp[i] = 0;
			if (i+1 <= n) dp[i] += dp[i+1];
			if (i+2 <= n) dp[i] += dp[i+2];
			if (i+3 <= n) dp[i] += dp[i+3];
			if (i+4 <= n && check(str, i)) dp[i] += dp[i+4];
			dp[i] %= MOD;

			if (i <= fi[n-1]) {
				// cout << "Adding " << i << ' ' << n << ' ' << dp[i] << " to solution\n";
				ans = (ans + dp[i]) % MOD;
			}
		}
		cout << ans << '\n';
	}
}
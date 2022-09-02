#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

const int P1 = (int)1e9 + 7;
const int P2 = 9 * (int)1e8 + 11;
const int M1 = rand(1, P1 - 1);
const int M2 = rand(1, P2 - 1);

const int N = 2 * (int)1e5 + 10;
int pw[N][2];

pair<pair<int, int>, int> add(pair<pair<int, int>, int> x, int b) {
	x.first.first = ((ll)x.first.first * M1 + b) % P1;
	x.first.second = ((ll)x.first.second * M2 + b) % P2;
	++x.second;
	return x;
}
pair<pair<int, int>, int> sub(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
	int d = x.second - y.second;
	x.first.first = (x.first.first - (ll)y.first.first * pw[d][0]) % P1;
	x.first.second = (x.first.second - (ll)y.first.second * pw[d][1]) % P2;
	if (x.first.first < 0) x.first.first += P1;
	if (x.first.second < 0) x.first.second += P2;
	x.second = d;
	return x;
}

pair<pair<int, int>, int> dp[N];
int nxt[N];
int pre[N];

pair<pair<int, int>, int> get(int a, int b) {
	if (pre[b] >= a) {
		auto res = dp[a];
		int d = (nxt[a] - a) % 2;
		res = add(res, d);
		res = sub(res, dp[pre[b]]);
		return res;
	} else {
		return {{0, 0}, 0};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	pw[0][0] = 1;
	pw[0][1] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i][0] = ((ll)pw[i-1][0] * M1) % P1;
		pw[i][1] = ((ll)pw[i-1][1] * M2) % P2;
	}

	// We are only interested in
	// 1. Length
	// 2. Number of zeroes
	// 3. Parity of number of ones between zeroes
	// Two strings are reachable from eachother if and only if all three of these match

	// Length is guaranteed, number of zeroes is correct, 

	int n;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 0; i < n; ++i) {
		if (str[i] == '0') pre[i] = i;
		else {
			if (i > 0) pre[i] = pre[i-1];
			else pre[i] = -1;
		}
	}

	int b = 0;
	dp[n] = {{0, 0}, 0};
	nxt[n] = n;
	for (int i = n-1; i >= 0; --i) {
		if (str[i] == '0') {
			dp[i] = add(dp[i+1], b);
			nxt[i] = i;
			b = 0;
		} else {
			dp[i] = dp[i+1];
			nxt[i] = nxt[i+1];
			b ^= 1;
		}
	}

	int q;
	cin >> q;
	for (; q; --q) {
		int a, b, k;
		cin >> a >> b >> k;
		--a; --b;
		auto v1 = get(a, a+k-1);
		auto v2 = get(b, b+k-1);
		if (v1 == v2) cout << "Yes\n";
		else cout << "No\n";
	}
}
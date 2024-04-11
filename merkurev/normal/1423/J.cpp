#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}

const int B = 15;
const int S = (1 << B);
const int L = 60 - B;
const int M = 8;
int a[L];
ll dp[L + 1][M + 1];
int mem[S + 3][M];
int b[2 * M + 1][2];

int solve(ll x, int h = -1) {
	for (int i = 0; i < L; i++) {
		a[i] = x & 1;
		x /= 2;
	}
	for (int i = 0; i <= L; i++)
		for (int x = 0; x < M; x++)
			dp[i][x] = 0;
	if (h == -1) {
		dp[L][0] = 1;
	} else {
		for (int i = 0; i < M; i++)
			dp[L][i] = mem[h][i];
	}
	for (int i = L - 1; i >= 0; i--) {
		for (int x = 0; x < M; x++) {
			int y = 2 * x + a[i];
			dp[i][b[y][0]] += dp[i + 1][x];
			dp[i][b[y][1]] -= dp[i + 1][x];
		}
		for (int x = 1; x < M; x++)
			dp[i][x] += dp[i][x - 1];
		if ((i & 7) == 0) {
			for (int x = 0; x < M; x++)
				dp[i][x] %= MOD;
		}
	}
	return dp[0][0];
}

int solve2(ll x) {
	int h = (x >> L);
	x -= (ll)h << L;
	return solve(x, h);
}

bool isspace(char c) {
	return c == ' ' || c == '\n';
}

ll readLL() {
	ll x = 0;
	char c = ' ';
	while(isspace(c)) c = _getchar_nolock();
	while(!isspace(c)) {
		x = 10 * x + (int)(c - '0');
		c = _getchar_nolock();
	}
	return x;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 0; x <= 2 * M; x++) {
		b[x][0] = max(0, x - M + 1);
		b[x][1] = min(M, x + 1);
	}

	for (int x = 0; x < (1 << B); x++) {
		solve(x);
		for (int i = 0; i < M; i++)
			mem[x][i] = dp[0][i];
	}

	int t;
	scanf("%d", &t);
//	t = 500000;
	while(t--) {
		ll x;
//		scanf("%lld", &x);
		x = readLL();
//		x = (ll)1e18;
		printf("%d\n", solve2(x));
	}

	return 0;
}
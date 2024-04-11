#pragma comment(linker, "/STACK:1024000000")
#define _CRT_SECURE_NO_WARNINGS
#undef NDEBUG
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <functional>
/*#ifndef room111
#include <sys/resource.h>
#endif*/
#include <unordered_set>
#include <unordered_map>
#include <array>
using namespace std;
#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

bool stress = false;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	/*#ifndef room111
	const rlim_t kStackSize = 1024L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
	if (rl.rlim_cur < kStackSize)
	{
	rl.rlim_cur = kStackSize;
	result = setrlimit(RLIMIT_STACK, &rl);
	if (result != 0)
	{
	fprintf(stderr, "setrlimit returned result = %d\n", result);
	}
	}
	}
	#endif*/

	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve(true);
		++testNumber;
		//++timer;
	}
#ifdef room1111
	while (true)
		solve(false);
#endif

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}
void precalc() {}

template<typename T>
void relax(T& cur, T val) {
	cur = min(cur, val);
}

#define int li
//const int mod = 1000000007;

void solve(bool read) {
	int n, p;
	cin >> n >> p;
	vector<int> a(n), b(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		swap(a[i], b[i]);
		sum += b[i];
	}
	if (sum <= p) {
		cout << "-1\n";
		return;
	}

	double L = 0, R = 1e12;
	for (int w = 0; w < 200; ++w) {
		double T = (L + R) / 2;
		double need = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < T * b[i]) {
				need += T * b[i] - a[i];
			}
		}
		if (need > p * T) {
			R = T;
		}
		else {
			L = T;
		}
	}

	cout << L << endl;

}
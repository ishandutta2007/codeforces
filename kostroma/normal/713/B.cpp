#pragma comment(linker, "/STACK:1024000000")
#define _CRT_SECURE_NO_WARNINGS
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
using namespace std;
//#define FILENAME ""
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
	//freopen("in.txt", "r", stdin);
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
	const rlim_t kStackSize = 128L * 1024L * 1024L;   // min stack size = 64 Mb
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

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

/*const int C = 7000500;

int least_prime[C];*/

void precalc() {

	/*for (int i = 2; i < C; ++i) {
	if (!least_prime[i]) {
	least_prime[i] = i;
	for (li j = i * 1LL * i; j < C; j += i) {
	least_prime[j] = i;
	}
	}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
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

//#define int li

//const int mod = 1000000007;

struct Rectangle {
	int r[2], c[2];
	Rectangle(int r1, int c1, int r2, int c2) {
		r[0] = r1;
		r[1] = r2;
		c[0] = c1;
		c[1] = c2;
	}
	void print(bool pere = true) {
		cout << r[0] + 1 << ' ' << c[0] + 1 << ' ' << r[1] << ' ' << c[1];
		if (pere) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
	bool operator == (const Rectangle& ot) const {
		bool res = true;
		for (int i = 0; i < 2; ++i) {
			res &= (r[i] == ot.r[i]);
			res &= (c[i] == ot.c[i]);
		}
		return res;
	}
};

/*vector<Rectangle> into(2, Rectangle(0, 0, 0, 0));

bool inside(Rectangle inner, Rectangle outer) {
	return inner.r[1] <= outer.r[1] && inner.r[0] >= outer.r[0] && inner.c[1] <= outer.c[1] && inner.c[0] >= outer.c[0];
}

int calc(Rectangle q) {
	int res = 0;
	for (int i = 0; i < 2; ++i) {
		if (inside(into[i], q)) {
			++res;
		}
	}
	return res;
}*/

int ask(Rectangle query, int rev) {
	cout << "? ";
	if (rev) {
		for (int i = 0; i < 2; ++i) {
			swap(query.c[i], query.r[i]);
		}
	}
	query.print();

	int res;
	cin >> res;
	return res;
	//return calc(query);
}

void print(vector<Rectangle> res, int rev) {
	cout << "! ";
	for (int i = 0; i < 2; ++i) {
		if (rev) {
			for (int j = 0; j < 2; ++j) {
				swap(res[i].c[j], res[i].r[j]);
			}
		}
		res[i].print(i == 1);
	}
	//assert(res[0] == into[0] && res[1] == into[1] || res[0] == into[1] && res[1] == into[0]);
}

void solve(bool read) {
	/*into[0] = Rectangle(2, 1, 4, 3);
	into[1] = Rectangle(3, 3, 4, 5);*/
	int n;
	cin >> n;
	for (int rev = 0; rev < 2; ++rev) {
		int L = 0, R = n;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (ask(Rectangle(0, 0, M, n), rev) == 2) {
				R = M;
			}
			else {
				L = M;
			}
		}

		int border[2];

		border[0] = R;
		L = 0;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (ask(Rectangle(0, 0, M, n), rev) == 1) {
				R = M;
			}
			else {
				L = M;
			}
		}
		border[1] = R;

		if (ask(Rectangle(0, 0, border[1], n), rev) == 1 && ask(Rectangle(border[1], 0, border[0], n), rev) == 1) {
			
			L = 0, R = border[1];
			while (L + 1 < R) {
				int M = (L + R) / 2;
				if (ask(Rectangle(M, 0, border[1], n), rev) == 1) {
					L = M;
				}
				else {
					R = M;
				}
			}
			int start[2];
			start[1] = L;

			L = border[1], R = border[0];
			while (L + 1 < R) {
				int M = (L + R) / 2;
				if (ask(Rectangle(M, 0, border[0], n), rev) == 1) {
					L = M;
				}
				else {
					R = M;
				}
			}
			start[0] = L;

			vector<Rectangle> result;

			for (int w = 0; w < 2; ++w) {
				L = 0, R = n;
				while (L + 1 < R) {
					int M = (L + R) / 2;
					if (ask(Rectangle(start[w], 0, border[w], M), rev) == 1) {
						R = M;
					}
					else {
						L = M;
					}
				}
				int y_border = R;
				L = 0, R = y_border;
				while (L + 1 < R) {
					int M = (L + R) / 2;
					if (ask(Rectangle(start[w], M, border[w], n), rev) == 1) {
						L = M;
					}
					else {
						R = M;
					}
				}
				int y_start = L;
				result.push_back(Rectangle(start[w], y_start, border[w], y_border));
			}

			print(result, rev);

			return;
		}

	}

	assert(false);

}
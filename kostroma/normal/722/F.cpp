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

int n;

vector<int> a;

const int L = 30;

vector<int> ANS;

vector<vector<pair<int, int>>> have;

bool can(int mx, bool find_ans = false) {
	have.clear();
	have.resize(L);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			int cur = (a[i] >> j);
			if (cur > mx) {
				continue;
			}
			if (cur == 0) {
				continue;
			}
			int sz = 0;
			while ((1 << sz) <= cur) {
				++sz;
			}
			have[sz].push_back({ cur, i });
			//cout << a[i] << ' ' << sz << ' ' << cur << "\n";
		}
	}
	/*for (int i = 0; i < L; ++i) {
		for (int j = 0; j + 1 < have[i].size(); ++j) {
			if (have[i][j].first > have[i][j + 1].first) {
				cout << "look: " << i << ' ' << have[i][j].first << ' ' << have[i][j + 1].first << endl;
			}
		}
		//sort(all(have[i]));
	}*/
	vector<int> taken(n, -1);
	for (int i = L - 1; i >= 0; --i) {
		for (int j = 0; j < have[i].size();) {
			int r = j;
			while (r < have[i].size() && have[i][j].first == have[i][r].first) {
				++r;
			}
			for (int z = j; z < r; ++z) {
				int x = have[i][z].second;
				if (taken[x] == -1) {
					taken[x] = have[i][j].first;
					break;
				}
			}
			j = r;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (taken[i] == -1) {
			return false;
		}
	}
	if (find_ans) {
		ANS = taken;
	}
	return true;
}

int get_real(int cur) {
	while (cur < (1 << 30)) {
		cur <<= 1;
	}
	return cur;
}

struct Snapshot {
	int step;
	int rem;
	int str;
};

bool consistent(Snapshot cur, Snapshot now) {
	int g = min(cur.step, now.step);
	return cur.rem % g == now.rem % g;
}

void solve(bool read) {
	vector<int> primes;
	for (int i = 2; i <= 40; ++i) {
		int cur = i;
		bool f = true;
		for (int j = 2; j * j <= cur; ++j) {
			if (cur % j == 0) {
				f = false;
				break;
			}
		}
		if (f) {
			primes.push_back(i);
		}
	}

	int n, m;
	cin >> n >> m;
	/*n = 100000;
	m = 100000;*/
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		//k = 2;
		a[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
			//a[i][j] = 1 + ((rand() << 16) | rand()) % m;
			--a[i][j];
		}
	}
	/*for (int i = 0; i < n; ++i) {
		a.push_back(vector<int>(n));
		for (int j = 0; j + 1 < a[i].size(); ++j) {
			a.back()[j] = a[i][j + 1];
			a.back().back() = a[i][0];
		}
	}
	n *= 2;*/

	vector<vector<pair<int, int>>> poses(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			poses[a[i][j]].push_back({ i, j });
		}
	}

	vector<vector<int>> profile(n, vector<int>(primes.size(), 1));
	vector<vector<int>> used(n);
	for (int i = 0; i < n; ++i) {
		int cur = a[i].size();
		for (int j = 0; j < primes.size(); ++j) {
			if (cur % primes[j] == 0) {
				used[i].push_back(j);
			}
			while (cur % primes[j] == 0) {
				profile[i][j] *= primes[j];
				cur /= primes[j];
			}
		}
	}

	vector<deque<Snapshot>> rems(primes.size());
	for (int cur = 0; cur < m; ++cur) {
		rems.clear();
		rems.resize(primes.size());
		int res = 0;

		int last = -100;
		int left_border = -100;
		for (auto item : poses[cur]) {
			int str = item.first;
			int pos = item.second;
			if (str > last + 1) {
				rems.clear();
				rems.resize(primes.size());
				left_border = str;
			}
			else {
				for (int pr_id : used[str]) {
					Snapshot cur_snapshot = { profile[str][pr_id], pos % profile[str][pr_id], str };
					while (!rems[pr_id].empty() && !consistent(rems[pr_id].front(), cur_snapshot)) {
						left_border = max(left_border, rems[pr_id].front().str + 1);
						rems[pr_id].pop_front();
					}
				}
			}

			for (int pr_id : used[str]) {
				Snapshot cur_snapshot = { profile[str][pr_id], pos % profile[str][pr_id], str };
				while (!rems[pr_id].empty() && cur_snapshot.step >= rems[pr_id].back().step) {
					rems[pr_id].pop_back();
				}
				rems[pr_id].push_back(cur_snapshot);
			}

			res = max(res, str - left_border + 1);
			last = str;
		}
		res = min(res, n);
		cout << res << "\n";
	}

}
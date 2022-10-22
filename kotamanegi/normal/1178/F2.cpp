#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<complex<double>>  DFT(vector<complex<double>> a) {
	int n = a.size();
	if (n == 1) return a;
	vector<complex<double>> a0(n / 2), a1(n / 2);
	REP(i, n) {
		if (i % 2 == 0) {
			a0[i / 2] = a[i];
		}
		else {
			a1[i / 2] = a[i];
		}
	}
	vector<complex<double>> inversed_a0 = DFT(a0), inversed_a1 = DFT(a1);
	vector<complex<double>> inversed_a(n);
	for (int i = 0; i < n; ++i) {
		complex<double> zeta = complex<double>(cos(2 * Ma_PI * i / n), sin(2 * Ma_PI * i / n));
		inversed_a[i] = inversed_a0[i % (n / 2)] + zeta * inversed_a1[i % (n / 2)];
	}
	return inversed_a;
}
vector<complex<double>> IDFT(vector<complex<double>> inversed_a) {
	int n = inversed_a.size();
	vector<complex<double>> now = DFT(inversed_a);
	reverse(now.begin(), now.end());
	for (int q = now.size() - 1; q >= 1; --q) {
		swap(now[q], now[q - 1]);
	}
	REP(i, n) {
		now[i] /= complex<double>(n, 0);
	}
	return now;
}
vector<complex<double>> conv(vector<complex<double>> a, vector<complex<double>> b) {
	int deg = a.size() + b.size() - 1;
	int n = 1;
	while (n < deg) n <<= 1;
	a.resize(n);
	b.resize(n);
	vector<complex<double>> inversed_a = DFT(a),inversed_b = DFT(b);
	vector<complex<double>> inversed_c(n);
	REP(i, n) {
		inversed_c[i] = inversed_a[i] * inversed_b[i];
	}
	return IDFT(inversed_c);
}
long long dp[2001][2001] = {};
int main() {
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> tmp, geko;
	REP(i, m) {
		int a;
		cin >> a;
		tmp.push_back(a);
	}
	stack<long long> neko;
	geko.push_back(tmp[0]);
	for (int q = 1; q < tmp.size(); ++q) {
		if (tmp[q] == tmp[q - 1]) continue;
		geko.push_back(tmp[q]);
	}
	if (geko.size() >= 2000) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = n; i >= 1; --i) {
		for (int q = 0; q < geko.size(); ++q) {
			if (geko[q] == i) {

				long long tmp_back_dp[2002] = {};
				tmp_back_dp[q] = 1;
				for (int j = q - 1; j >= 0; --j) {
					if (tmp_back_dp[j + 1] == 0) continue;
					for (int t = j; t >= 0; --t) {
						tmp_back_dp[t] += tmp_back_dp[j + 1] * dp[t][j];
						tmp_back_dp[t] %= MOD;
					}
				}
				long long now_maxitr = q;
				long long multi = 1;

				for (int p = q + 1; p < geko.size(); ++p) {
					if (geko[p] != i)continue;
					long long tmp_mid_dp[2002] = {};
					tmp_mid_dp[now_maxitr] = 1;
					for (int t = q + 1; t < p; ++t) {
						for (int j = t; j < p; ++j) {
							tmp_mid_dp[j] += tmp_mid_dp[t - 1] * dp[t][j];
							tmp_mid_dp[j] %= MOD;
						}
					}
					now_maxitr = p;
					multi *= tmp_mid_dp[now_maxitr - 1];
					multi %= MOD;
				}

				long long tmp_front_dp[2002] = {};
				tmp_front_dp[now_maxitr] = 1;
				for (int j = now_maxitr + 1; j < geko.size(); ++j) {
					if (tmp_front_dp[j - 1] == 0) continue;
					for (int t = j; t < geko.size(); ++t) {
						tmp_front_dp[t] += tmp_front_dp[j - 1] * dp[j][t];
						tmp_front_dp[t] %= MOD;
					}
				}

				for (int j = 0; j <= q; ++j) {
					if (tmp_back_dp[j] == 0) continue;
					for (int t = now_maxitr; t < geko.size(); ++t) {
						if (tmp_front_dp[t] == 0) continue;
						dp[j][t] += (((tmp_back_dp[j] * tmp_front_dp[t]) % MOD) * multi) % MOD;
						dp[j][t] %= MOD;
					}
				}
				break;
			}
		}
	}
	long long gea[2003] = {};
	gea[0] = 1;
	for (int i = 0; i < geko.size(); ++i) {
		for (int q = i; q < geko.size(); ++q) {
			gea[q + 1] += gea[i] * dp[i][q];
			gea[q + 1] %= MOD;
		}
	}
	cout << gea[geko.size()] << endl;
}
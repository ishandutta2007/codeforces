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

int main() {
	int n;
	cin >> n;
	for (int i = n; i <= n + n / 2; ++i) {
		int ok = 1;
		for (int q = 2; q <= sqrt(i); ++q) {
			if (i % q == 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
			vector<pair<int, int>> vertexs;
			for (int q = 1; q < n; ++q) {
				vertexs.push_back(make_pair(q, q + 1));
			}
			vertexs.push_back(make_pair(1, n));
			for (int t = 0; t < i - n; ++t) {
				vertexs.push_back(make_pair(1 + t, n / 2 + 1 + t));
			}
			cout << vertexs.size() << endl;
			REP(q, vertexs.size()) {
				cout << vertexs[q].first << " " << vertexs[q].second << endl;
			}
			return 0;
		}
	}
	return 0;
}
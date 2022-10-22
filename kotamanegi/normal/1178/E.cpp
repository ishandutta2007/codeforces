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
long long left_move[3000000][3];
int main() {
	srand(time(NULL));
	string s;
	cin >> s;
	REP(i, 3) {
		left_move[0][i] = -1;
	}
	for (int i = 0; i < s.length(); ++i) {
		REP(q, 3) {
			left_move[i + 1][q] = left_move[i][q];
		}
		left_move[i + 1][s[i] - 'a'] = i;
	}
	REP(trial, 100) {
		string a, back;
		int now = s.length();
		for (int i = 0; i < s.length()-1; ++i) {
			if (now <= i) {
				break;
			}
			if (left_move[now][s[i+1] - 'a'] <= i+1||left_move[now][s[i] - 'a'] > left_move[now][s[i+1] - 'a']) {
				//take s
				now = left_move[now][s[i] - 'a'];
				if (now <= i) {
					a.push_back(s[i]);
					break;
				}
				a.push_back(s[i]);
				back.push_back(s[i]);
			}
			else {
				i++;
				now = left_move[now][s[i] - 'a'];
				if (now <= i) {
					a.push_back(s[i]);
					break;
				}
				a.push_back(s[i]);
				back.push_back(s[i]);
			}
		}
		reverse(back.begin(), back.end());
		string nexter = a + back;
		int hoge = s.length() / 2;
		if (hoge <= nexter.size()) {
			cout << nexter << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
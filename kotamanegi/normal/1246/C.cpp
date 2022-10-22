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
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
long long down[3000][3000];
long long yoko[3000][3000];
int cnt_yoko[3000][3000];
int cnt_tate[3000][3000];
long long ans[3000][3000];
int main() {
#define int long long
	long long n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1 << endl;
		return 0;
	}
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, m) {
			if (s[q] == 'R') {
				cnt_yoko[i][q]++;
				cnt_tate[i][q]++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int q = 0; q < m; ++q) {
			cnt_yoko[i][q + 1] += cnt_yoko[i][q];
			cnt_yoko[i][q + 1] %= MAX_MOD;
		}
	}
	REP(q, m) {
		REP(i, n) {
			cnt_tate[i + 1][q] += cnt_tate[i][q];
		}
	}
	yoko[0][0] = 1;
	yoko[0][m - cnt_yoko[0][m]] = MAX_MOD-1;
	for (int i = 0; i < n; ++i) {
		for (int q = 0; q < m; ++q) {
			yoko[i][q + 1] += yoko[i][q];
			down[i + 1][q] += down[i][q];

			down[i+1][q] += yoko[i][q];
			down[i + 1][q] %= MAX_MOD;
			int target = n - cnt_tate[n][q] + cnt_tate[i][q];
			down[target][q] += MAX_MOD - yoko[i][q];
			down[target][q] %= MAX_MOD;

			yoko[i][q + 1] += down[i][q];
			yoko[i][q+1] %= MAX_MOD;
			target = m - cnt_yoko[i][m] + cnt_yoko[i][q];
			yoko[i][target] += MAX_MOD - down[i][q];
			yoko[i][target] %= MAX_MOD;
		}
	}
	cout << (yoko[n-1][m-1] + down[n-1][m-1]) % MAX_MOD << endl;
}
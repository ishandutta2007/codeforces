
/*

This Submission is to determine how many 120/240 min const. delivery point there are.

*/
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
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int grid[3000][3000];
pair<long long,long long> cnt_tate[3000];
pair<long long,long long> cnt_yoko[3000];
int ans[3000][3000];
int main() {
	long long n, k;
	cin >> n >> k;
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, n) {
			if (s[q] == 'W') {
				grid[i][q] = 1;
			}
		}
	}
	REP(i, 3000) {
		cnt_tate[i] = make_pair(10000, -1);
		cnt_yoko[i] = make_pair(10000, -1);
	}
	REP(i, n) {
		REP(q, n) {
			if (grid[i][q] == 0) {
				cnt_yoko[i].first = min(cnt_yoko[i].first, q);
				cnt_yoko[i].second = max(cnt_yoko[i].second, q);
				cnt_tate[q].first = min(cnt_tate[q].first, i);
				cnt_tate[q].second = max(cnt_tate[q].second, i);
			}
		}
	}
	int pre_ans = 0;
	REP(i, n) {
		if (cnt_tate[i].first == 10000) {
			pre_ans++;
			cnt_tate[i] = make_pair(-10000, 10000);
		}
		if (cnt_yoko[i].first == 10000) {
			pre_ans++;
			cnt_yoko[i] = make_pair(-10000, 10000);
		}
	}
	REP(i, n - k + 1) {
		int now = 0;
		for (int q = 0; q < n; ++q) {
			if (cnt_tate[q].first >= i && cnt_tate[q].second < i + k) {
				now++;
			}
			if (q - k >= 0) {
				if (cnt_tate[q-k].first >= i && cnt_tate[q-k].second < i + k) {
					now--;
				}
			}
			if (q - k + 1 >= 0) {
				ans[i][q - k + 1] += now;
			}
		}
		now = 0;
		for (int q = 0; q < n; ++q) {
			if (cnt_yoko[q].first >= i && cnt_yoko[q].second < i + k) {
				now++;
			}
			if (q - k >= 0) {
				if (cnt_yoko[q-k].first >= i && cnt_yoko[q-k].second < i + k) {
					now--;
				}
			}
			if (q - k + 1 >= 0) {
				ans[q - k + 1][i] += now;
			}
		}
	}
	int final_ans = 0;
	REP(i, n) {
		REP(q, n) {
			final_ans = max(final_ans, ans[i][q]);
		}
	}
	cout << pre_ans + final_ans<< endl;
}
#define _CRT_SECUintRE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128(void)
{
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t;
	t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int first_grid[1000][1000] = {};
int second_grid[1000][1000] = {};
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		REP(q, m) {
			cin >> first_grid[i][q];
		}
	}
	REP(i, n) {
		REP(q, m) {
			cin >> second_grid[i][q];
		}
	}
	for (int q = 0; q < m-1; ++q) {
		for (int i = 0; i < n - 1; ++i) {
			if (first_grid[i][q] != second_grid[i][q]) {
				first_grid[i][q]++;
				first_grid[i + 1][q]++;
				first_grid[i + 1][q + 1]++;
				first_grid[i][q + 1]++;
				first_grid[i][q] %= 2;
				first_grid[i + 1][q] %= 2;
				first_grid[i + 1][q + 1] %= 2;
				first_grid[i][q + 1] %= 2;
			}
		}
	}
	REP(i, n) {
		REP(q, m) {
			if (first_grid[i][q] != second_grid[i][q]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
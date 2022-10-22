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
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
long double memo[2][10][10] = {};
int up[10][10];
void find_ans(int a, int b) {
	if (a == 0 && b == 0) return;
	if (memo[0][a][b]) return;
	if (up[a][b] != 0) {
		find_ans(a - up[a][b], b);
	}
	long double with_ladder = memo[0][a - up[a][b]][b];
	if (up[a][b] == 0) {
		with_ladder = 100000;
	}
	long double without_ladder = 0; //maybe +1 is required
	int now_x = a;
	int now_y = b;
	for (int q = 1; q <= 6; ++q) {
		if (now_x % 2 == 0) {
			if (now_y == 0) {
				now_x--;
			}
			else {
				now_y--;
			}
		}
		else {
			if (now_y == 9) {
				now_x--;
			}
			else {
				now_y++;
			}
		}
		find_ans(now_x, now_y);
		without_ladder += memo[1][now_x][now_y] + 1.0;
	}
	without_ladder /= 6.0;
	memo[0][a][b] = without_ladder;
	memo[1][a][b] = min(with_ladder, without_ladder);
}
int main(){
	REP(i, 10) {
		REP(q, 10) {
			cin >> up[i][q];
		}
	}
	for (int q = 1; q <= 6; ++q) {
		long double ans = 0;
		long double now = 1.0;
		for (int j = 0; j < 1000; ++j) {
			ans += now;
			for (int t = 1; t < q; ++t) {
				ans += (now / 6.0) * memo[0][0][q - t];
			}
			now *= ((long double)(6 - q)) / 6.0;
		}
		memo[0][0][q] = ans;
	}
	REP(q, 6) {
		memo[1][0][q + 1] = memo[0][0][q + 1];
	}
	find_ans(9, 0);
	cout << fixed << setprecision(30);
	cout << memo[1][9][0] << endl;
}
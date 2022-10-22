//J^!w

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
int cnt[200000][3] = {};
int main() {
	string s;
	cin >> s;
	REP(i, s.length()) {
		if (s[i] == 'x') {
			cnt[i + 1][0]++;
		}
		else if (s[i] == 'y') {
			cnt[i + 1][1]++;
		}
		else {
			cnt[i + 1][2]++;
		}
		REP(j, 3) {
			cnt[i + 1][j] += cnt[i][j];
		}
	}
	int m;
	cin >> m;
	REP(q, m) {
		int a, b;
		cin >> a >> b;
		a--;
		int maxe = 0;
		int mine = 1000000;
		REP(q, 3) {
			int now = cnt[b][q] - cnt[a][q];
			maxe = max(maxe, now);
			mine = min(mine, now);
		}
		if (maxe - mine <= 1||b - a <= 2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
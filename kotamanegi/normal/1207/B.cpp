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
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int go[60][60];
int B[60][60];
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		REP(q, m) {
			cin >> go[i][q];
		}
	}
	vector<pair<int, int>> ans;
	REP(i, n-1) {
		REP(q, m-1) {
			int ok = 1;
			REP(j, 2) {
				REP(t, 2) {
					if (go[i + j][q + t] == 0) {
						ok = 0;
					}
				}
			}
			if (ok == 1) {
				REP(j, 2) {
					REP(t, 2) {
						B[i + j][q + t] = 1;
					}
				}
				ans.push_back(make_pair(i + 1, q + 1));
			}
		}
	}
	REP(i, n) {
		REP(q, m) {
			if (go[i][q] != B[i][q]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
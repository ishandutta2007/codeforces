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
int main() {
#define int long long
	int t;
	cin >> t;
	REP(i, t) {
		int n;
		cin >> n;
		vector<string> ans;
		REP(i, n) {
			string b;
			cin >> b;
			ans.push_back(b);
		}
		int answer = 0;
		for (int i = 0; i < 4; ++i) {
			REP(q, n) {
				int bad[10] = {};
				int ok = 0;
				bad[ans[q][i] - '0'] = 1;
				for (int j = 0; j < n; ++j) {
					if (q == j) continue;
					if (ans[q] == ans[j]) {
						ok = 1;
					}
					bad[ans[j][i] - '0'] = 1;
				}
				if (ok == 1) {
					answer++;
					for (int j = 0; j < 10; ++j) {
						if (bad[j] == 0) {
							ans[q][i] = j + '0';
							break;
						}
					}
				}
			}
		}
		cout << answer << endl;
		REP(i, n) {
			cout << ans[i] << endl;
		}
	}
}
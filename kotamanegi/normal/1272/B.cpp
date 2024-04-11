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
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(t, query) {
		string s;
		cin >> s;
		int cnt[4] = {};
		string se = "LRUD";
		REP(q, s.length()) {
			REP(t, 4) {
				if (se[t] == s[q]) {
					cnt[t]++;
				}
			}
		}
		if ((cnt[0] == 0 || cnt[1] == 0) || cnt[2] == 0 || cnt[3] == 0) {
			if (cnt[0] == 0 || cnt[1] == 0) {
				if (cnt[2] >= 1 && cnt[3] >= 1) {
					cout << 2 << endl;
					cout << "UD" << endl;
					continue;
				}
			}
			if (cnt[2] == 0 || cnt[3] == 0) {
				if (cnt[0] >= 1 && cnt[1] >= 1) {
					cout << 2 << endl;
					cout << "LR" << endl;
					continue;
				}
			}
			cout << 0 << endl;
			cout << endl;
			continue;
		}
		int ans = min(cnt[0], cnt[1]) + min(cnt[2], cnt[3]);
		cout << ans * 2 << endl;
		REP(i, min(cnt[0], cnt[1])) {
			cout << "L";
		}
		REP(i, min(cnt[2], cnt[3])) {
			cout << "U";
		}
		REP(i, min(cnt[0], cnt[1])) {
			cout << "R";
		}
		REP(i, min(cnt[2], cnt[3])) {
			cout << "D";
		}
		cout << endl;
	}
}
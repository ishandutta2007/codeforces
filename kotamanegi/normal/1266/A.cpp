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
int main() {
	int n;
	cin >> n;
	vector<string> inputs;
	REP(i, n) {
		string s;
		cin >> s;
		inputs.push_back(s);
	}
	REP(i, n) {
		int cnt[10] = {};
		REP(q, inputs[i].size()) {
			cnt[inputs[i][q] - '0']++;
		}
		int ok = 1;
		if (cnt[0] == 0) {
			ok = 0;
		}
		else {
			cnt[0]--;
			int hoge = 0;
			REP(t, 10) {
				hoge += cnt[t] * t;
			}
			int bo = 0;
			REP(t, 10) {
				if (t % 2 == 0) {
					if (cnt[t] != 0) {
						bo = 1;
					}
				}
			}
			if (hoge % 3 != 0||bo == 0) {
				ok = 0;
			}
		}
		string s[2] = { "red","cyan" };
		cout << s[1-ok] << endl;
	}
}
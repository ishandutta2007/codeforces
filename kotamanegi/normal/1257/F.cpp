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
map<vector<int>, int> nya;
int main() {
	int n;
	cin >> n;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	for (int i = 0; i < (1 << 15); ++i) {
		vector<int> now;
		REP(q, inputs.size()) {
			int cnt = 0;
			for (int t = 0; t < 15; ++t) {
				if ((((inputs[q] ^ i) & (1 << t))) == (1 << t)) {
					cnt++;
				}
			}
			now.push_back(cnt);
		}
		nya[now] = i;
	}
	for (int tmp = 0; tmp < (1 << 15); ++tmp) {
		int i = (tmp << 15);
		vector<int> now;
		REP(q, inputs.size()) {
			int cnt = 0;
			for (int t = 15; t < 30; ++t) {
				if ((((inputs[q] ^ i) & (1 << t))) == (1 << t)) {
					cnt++;
				}
			}
			now.push_back(cnt);
		}
		for (int t = 0; t < 31; ++t) {
			vector<int> findings;
			REP(q, inputs.size()) {
				if (t - now[q] < 0) {
					findings.clear();
					break;
				}
				findings.push_back(t - now[q]);
			}
			if (findings.empty() == true) continue;
			if (nya.find(findings) != nya.end()) {
				cout << nya[findings]+i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
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
	int r, c;
	cin >> r >> c;
	vector<string> inputs;
	REP(i, r) {
		string a;
		cin >> a;
		inputs.push_back(a);
	}
	int ans = 0;
	REP(i, r) {
		REP(q, c) {
			int hoge = 1;
			REP(j, r) {
				if (inputs[j][q] == 'S') {
					hoge = 0;
				}
			}
			ans += hoge;
			if (hoge == 1) continue;
			hoge = 1;
			REP(j, c) {
				if (inputs[i][j] == 'S') hoge = 0;
			}
			ans += hoge;
		}
	}
	cout << ans << endl;
}
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
int inputs[4];
int go[4];
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 3 << endl;
		cout << 3 << endl;
		return 0;
	}
	REP(i, n) {
		cin >> inputs[i];
	}
	if (n == 1) {
		cout << "YES" << endl;
		cout << inputs[0] << endl;
		REP(q, 2) {
			cout << inputs[0] * 3 << endl;
		}
		return 0;
	}
	for (int i = 0; i <= 2000; ++i) {
		for (int q = 0; q <= 2000; ++q) {
			int j = 0;
			for (; j < n;++j) {
				go[j] = inputs[j];
			}
			if (j < 4) {
				go[j] = i;
				j++;
			}
			if (j < 4) {
				go[j] = q;
			}
			sort(go, go + 4);
			if ((go[3] - go[0]) * 4 != go[0] + go[1] + go[2] + go[3]) {
				continue;
			}
			if ((go[3] - go[0]) * 2 != go[1] + go[2]) {
				continue;
			}
			cout << "YES" << endl;
			if (n <= 3) {
				cout << i << endl;
			}
			if (n <= 2) {
				cout << q << endl;
			}
			return 0;
		}
	}
	cout << "NO" << endl;
}
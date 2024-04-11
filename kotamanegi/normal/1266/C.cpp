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
long long re[3000], ce[3000];
int main() {
	iostream::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << "0" << endl;
		return 0;
	}
	if (r == 1) {
		REP(q, c) {
			cout << q + 2 << " ";
		}
		cout << endl;
		return 0;
	}
	if (c == 1) {
		REP(q, r) {
			cout << q + 2 << endl;
		}
		return 0;
	}
	long long cnt = 1;
	for (int i = 0; i < r; ++i) {
		re[i] = cnt;
		cnt++;
	}
	for (int i = 0; i < c; ++i) {
		ce[i] = cnt;
		cnt++;
	}
	REP(i, r) {
		REP(q, c) {
			cout << re[i] * ce[q] << " ";
		}
		cout << endl;
	}
}
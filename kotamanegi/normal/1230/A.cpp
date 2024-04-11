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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	vector<long long> inputs;
	long long bo = 0;
	REP(i, 4) {
		long long s;
		cin >> s;
		inputs.push_back(s);
		bo += s;
	}
	REP(i, 1 << 4) {
		int hoge = 0;
		int te = i;
		for (int q = 0; te != 0; ++q) {
			hoge += inputs[q] * (te % 2);
			te /= 2;
		}
		if (hoge * 2 == bo) {
			cout << "yes" << endl;
			return 0;
		}
	}
	cout << "no" << endl;
}
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
int dp[2][200000];
int main() {
	int n;
	cin >> n;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	dp[0][0] = 1;
	for (int i = 0; i < inputs.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			if (dp[j][i] == 0) continue;
			for (int q = 1; i + q <= inputs.size(); q += 2) {
				if (inputs[i] % 2 == 1 && inputs[i+q-1] % 2 == 1) {
					dp[(j + 1) % 2][i + q] = 1;
				}
			}
		}
	}
	if (dp[1][inputs.size()] == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
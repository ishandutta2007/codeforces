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
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		vector<int> inputs;
		REP(i, n) {
			int a;
			cin >> a;
			inputs.push_back(a);
		}
		int can_do[1000] = {};
		for (int q = 1; q <= n; ++q) {
			for (int i = q; i < inputs.size(); ++i) {
				if (inputs[i] == q) {
					for (int j = i; j >= 1; --j) {
						if (can_do[j - 1] == 1) break;
						if (inputs[j - 1] < inputs[j]) break;
						can_do[j - 1] = 1;
						swap(inputs[j - 1], inputs[j]);
					}
				}
			}
		}
		REP(i, inputs.size()) {
			cout << inputs[i] << " ";
		}
		cout << endl;
	}
}
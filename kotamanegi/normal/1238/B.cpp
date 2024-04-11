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
	int query;
	cin >> query;
	REP(i, query) {
		int n,r;
		cin >> n >> r;
		vector<int> inputs;
		REP(i, n) {
			int a;
			cin >> a;
			inputs.push_back(a);
		}
		sort(inputs.begin(), inputs.end());
		int ans = 0;
		int go = 0;
		for (int i = 0; i < inputs.size(); ++i) {
			int itr = inputs.size() - i - 1;
			if (inputs[itr] <= r * go) {
				break;
			}
			if (i == 0 || inputs[itr] != inputs[itr + 1]) {
				go++;
				ans++;
			}
		}
		cout << ans << endl;
	}
}
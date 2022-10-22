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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long cnt[3000000];
long long cost[3000000];
int main() {
	long long n, k;
	cin >> n >> k;
	long long ans = 1e9;
	vector<long long> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	REP(i, n) {
		long long a = inputs[i];
		long long now_cost = 0;
		while (a != 0) {
			cnt[a]++;
			cost[a] += now_cost;
			if (cnt[a] >= k) {
				ans = min(ans, cost[a]);
			}
			now_cost++;
			a /= 2;
		}
	}
	cout << ans << endl;
}
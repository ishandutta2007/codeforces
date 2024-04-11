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
	iostream::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n;
	cin >> n;
	vector<pair<long long, int>> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(make_pair(a, 0));
	}
	REP(i, n) {
		cin >> inputs[i].second;
	}
	long long ans = 0;
	sort(inputs.begin(), inputs.end());
	vector<long long> can_go;
	for (int i = 1; i < inputs.size(); ++i) {
		if (inputs[i].first == inputs[i - 1].first) {
			can_go.push_back(inputs[i].first);
		}
	}
	for (int i = 0; i < inputs.size(); ++i) {
		REP(q, can_go.size()) {
			if ((can_go[q] & inputs[i].first) == inputs[i].first) {
				ans += inputs[i].second;
				break;
			}
		}
	}
	cout << ans << endl;
}
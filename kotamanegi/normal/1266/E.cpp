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
long long cnt[300000];
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> inputs;
	int ans = 0;
	REP(i, n) {
		int hoge;
		cin >> hoge;
		inputs.push_back(hoge);
		ans += hoge;
	}
	int query;
	cin >> query;
	map<pair<int, int>, int> stocks;
	REP(i, query) {
		int a, b, c;
		cin >> a >> b >> c;
		if (stocks.find(make_pair(a, b)) != stocks.end()) {
			auto tea = stocks.find(make_pair(a, b));
			int back = tea->second;
			if (cnt[back] <= inputs[back]) {
				ans++;
			}
			cnt[back]--;
			stocks.erase(make_pair(a, b));
		}
		if (c != 0) {
			stocks[make_pair(a, b)] = c - 1;
			if (cnt[c - 1] < inputs[c - 1]) {
				ans--;
			}
			cnt[c - 1]++;
		}
		cout << ans << endl;
	}
}
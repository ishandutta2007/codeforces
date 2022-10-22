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
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<int> connections[400000];
int values[400000];
map<int, int> cnt;
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	int now_max = -1e9;
	REP(i, n) {
		cin >> values[i];
		cnt[values[i]]++;
		now_max = max(now_max, values[i]);
	}
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		connections[a].push_back(b);
		connections[b].push_back(a);
	}
	int now_ans = 2e9;
	for (int i = 0; i < n; ++i) {
		int ans = values[i];
		cnt[values[i]]--;
		for (int q = 0; q < connections[i].size(); ++q) {
			int go = connections[i][q];
			cnt[values[go]]--;
			ans = max(ans, values[go] + 1);
		}
		for (int q = now_max; q >= now_max - 2; q--) {
			if (cnt[q]) {
				ans = max(ans, q + 2);
			}
		}
		now_ans = min(now_ans, ans);
		cnt[values[i]]++;
		for (int q = 0; q < connections[i].size(); ++q) {
			int go = connections[i][q];
			cnt[values[go]]++;
			ans = max(ans, values[go] + 1);
		}
	}
	cout << now_ans << endl;
}
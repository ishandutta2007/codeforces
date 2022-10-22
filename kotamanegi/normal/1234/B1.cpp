//!w

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
map<int, int> go;
int main() {
	int n, k;
	cin >> n >> k;
	int now_itr = 1;
	REP(i, n) {
		int a;
		cin >> a;
		if (go[a] < max(1, now_itr - k)) {
			go[a] = now_itr;
			now_itr++;
		}
	}
	vector<pair<int, int>> ans;
	for (auto i = go.begin(); i != go.end(); ++i) {
		if (i->second >= max(1, now_itr - k)) {
			ans.push_back(make_pair(i->second, i->first));
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		if (i != 0) cout << " ";
		cout << ans[i].second;
	}
	cout << endl;
}
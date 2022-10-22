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
long long imos[300000];
vector<pair<int,int>> tyoten[300000];
int main() {
	int k, n;
	cin >> n >> k;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		imos[a]++;
		imos[b + 1]--;
		tyoten[a].push_back(make_pair(b + 1,i+1));
	}
	priority_queue<pair<int,int>> next;
	vector<int> ans;
	for (int i = 1; i <= 200000; ++i) {
		imos[i] += imos[i - 1];
		for (int q = 0; q < tyoten[i].size(); ++q) {
			next.push(tyoten[i][q]);
		}
		while (k < imos[i]) {
			imos[i]--;
			imos[next.top().first]++;
			ans.push_back(next.top().second);
			next.pop();
		}
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
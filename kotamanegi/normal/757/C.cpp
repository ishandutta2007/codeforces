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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
vector<vector<int>> wombo;
int main() {
	int n, m;
	cin >> n >> m;
	long long wo[2000000] = {};
	wo[0] = 1;
	REP(i, m) {
		wo[i + 1] = (i + 2)*wo[i];
		wo[i + 1] %= MAX_MOD;
		wombo.push_back(vector<int>());
	}
	REP(i, n) {
		int tmp;
		cin >> tmp;
		REP(q, tmp) {
			int a;
			cin >> a;
			wombo[a-1].push_back(i);
		}
	}
	sort(wombo.begin(), wombo.end());
	int gogo = 0;
	long long ans = 1;
	for (int i = 1;i < m;++i) {
		if (wombo[i - 1] == wombo[i]) {
			gogo++;
		}
		else {
			ans *= wo[gogo];
			ans %= MAX_MOD;
			gogo = 0;
		}
	}
	ans *= wo[gogo];
	ans %= MAX_MOD;
	cout << ans << endl;
	return 0;
}
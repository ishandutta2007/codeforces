#define _CRT_SECURE_NO_WARNINGS
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
#define LONGINF 1000000000000000000
int calc[200000] = {};
int cost[200000] = {};
int n, m;
bool can_doit(int a) {
	int atfinal[110000] = {};
	for (int q = 0;q < a;++q) {
		atfinal[calc[q]] = q+1;
	}
	vector<pair<int, int>> wow;
	for (int i = 1;i <= m;++i) {
		if (atfinal[i] == 0) {
			return false;
		}
		else {
			wow.push_back(make_pair(atfinal[i], cost[i-1]));
		}
	}
	sort(wow.begin(), wow.end());
	int cnt = 0;
	for (int q = 0;q < wow.size();++q) {
		cnt += wow[q].second+1;
		if (cnt > wow[q].first) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int wow = 0;
	REP(i, n) {
		cin >> calc[i];
	}
	REP(i, m) {
		cin >> cost[i];
	}
	int top = n;
	int bot = 1;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (can_doit(mid) == true) {
			top = mid;
		}
		else bot = mid;
	}
	if (can_doit(bot) == true) {
		cout << bot << endl;
	}
	else if (can_doit(top) == true) {

		cout << top << endl;
	}
	else cout << "-1" << endl;
	return 0;
}
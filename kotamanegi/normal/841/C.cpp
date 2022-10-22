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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int ans[1000000] = {};
int main() {
	iostream::sync_with_stdio(false);
	int m;
	cin >> m;
	vector<pair<int,int>> a,b;
	REP(i, m) {
		int hoge;
		cin >> hoge;
		a.push_back(make_pair(hoge, 0));
	}
	REP(i, m) {
		int hoge;
		cin >> hoge;
		b.push_back(make_pair(hoge, i));
	}
	sort(a.begin(), a.end(), greater<pair<int,int>>());
	sort(b.begin(), b.end());
	for (int i = 0;i < m;++i) {
		ans[b[i].second] = a[i].first;
	}
	for (int i = 0;i < m;++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
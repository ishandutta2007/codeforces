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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
double p;
vector<pair<double, double>> hoge;
int can(double time) {
	double power_required = p*time;
	for (int i = 0;i < hoge.size();++i) {
		power_required -= max((double)0, hoge[i].first * time - hoge[i].second);
		if (power_required < 0) return false;
	}
	return true;
}
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n >> p;
	double tmp = 0;
	REP(i, n) {
		double a, b;
		cin >> a >> b;
		tmp += a;
		hoge.push_back(make_pair(a, b));
	}
	if (tmp <= p) {
		//can charge indefinetly
		cout << -1 << endl;
		return 0;
	}
	double bot = 0;
	double top = 1000000000000000000;
	for (int i = 0;i < 200;++i) {
		double mid = top + bot;
		mid /= 2;
		if (can(mid)) {
			bot = mid;
		}
		else top = mid;
	}
	cout << fixed << setprecision(10) << bot << endl;
	return 0;
}
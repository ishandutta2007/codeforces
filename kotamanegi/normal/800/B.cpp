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
int n;
vector<pair<double, double>> pre_name;
vector<pair<double, double>> name;
int main() {
	cin >> n;
	REP(i, n) {
		double a, b;
		cin >> a >> b;
		pre_name.push_back(make_pair(a, b));
	}
	name.push_back(pre_name[n - 1]);
	for (int i = 0;i < n;++i) {
		name.push_back(pre_name[i]);
	}
	name.push_back(pre_name[0]);
	double ans = 100000000000;
	for (int i = 1;i < name.size() - 1;++i) {
		if (name[i - 1].first - name[i + 1].first != 0) {
			double a = name[i - 1].second - name[i + 1].second;
			a /= name[i - 1].first - name[i + 1].first;
			double b = name[i - 1].second;
			b -= a*name[i - 1].first;
			//distance
			double distance = abs(-1 * a*name[i].first + name[i].second - b);
			distance /= sqrt(a*a + 1);
			ans = min(ans, distance / 2);
		}
		else {
			double distance = abs(name[i - 1].first - name[i].first);
			ans = min(ans, distance / 2);
		}
	}
	cout <<fixed << setprecision(10) << ans << endl;
	return 0;
}
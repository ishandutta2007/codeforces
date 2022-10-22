#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <random>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

double getAverage(const vector<int>& v) {
	int s = 0;
	REP(i, v.size()) s += v[i];
	double avg = s / (double)(v.size());
	return avg;
}

double getVariance(const vector<int>& v) {
    double mean = getAverage(v);
    double temp = 0;
    for (double a : v)
    	temp += (a-mean)*(a-mean);
    return temp / v.size();
}

const int INF = 0x7FFFFFFF;

void solve(int test) {
	vector<int> v(250);
	REP(i, 250) scanf("%d ", &v[i]);

	int mn = INF, mx = 0;
	REP(i, 250) {
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}

	// find distribution
	double k = getVariance(v) / getAverage(v);
	string distribution = (k > 2.0 ? "uniform" : "poisson");

	// do stats
	double avg = distribution == "poisson" ? getAverage(v) : (mx + mn) / 2.0;
	int estimate = (avg + 0.5);
	cout << estimate << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	int n; scanf("%d ", &n);
	REP(i, n) solve(i);
	return 0;
}
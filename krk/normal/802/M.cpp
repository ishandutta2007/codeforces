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
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

void solve() {
	int n, m; scanf("%d %d ", &n, &m);
	vector<int> v(n);
	REP(i, n) scanf("%d ", &v[i]);
	sort(v.begin(), v.end());
	long long s = 0;
	REP(i, m) s += v[i];
	cout << s << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	solve();
	return 0;
}
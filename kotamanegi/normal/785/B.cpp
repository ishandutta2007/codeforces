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
int main() {
#define int long long
	int n;
	cin >> n;
	vector<int> a,b;
	REP(i, n) {
		int c, d;
		cin >> c >> d;
		a.push_back(c);
		b.push_back(d);
	}
	int m;
	cin >> m;
	vector<int> c,d;
	REP(i, m) {
		int e, f;
		cin >> e >> f;
		c.push_back(e);
		d.push_back(f);
	}
	long long ans = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	ans = max(c[c.size() - 1] - b[0], a[a.size() - 1] - d[0]);
	ans = max(ans,(long long)0);
	cout << ans << endl;
	return 0;
}
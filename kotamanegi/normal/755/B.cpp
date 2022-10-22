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
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a, b;
	REP(i, n) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	REP(i, m) {
		string s;
		cin >> s;
		b.push_back(s);
	}
	int same = 0;
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			if (a[i] == b[q])same++;
		}
	}
	n -= same;
	m -= same;
	if (same % 2 == 1) m--;
	if (n > m) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
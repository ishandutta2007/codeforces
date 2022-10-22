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
int ruikei[200] = {};
int main() {
	int n, m;
	cin >> n >> m;
	int now = 0;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		now += tmp;
		ruikei[i + 1] = now;
	}
	int ans = 0;
	for (int q = 0;q < m;++q) {
		int a, b;
		cin >> a >> b;
		ans += max(0, ruikei[b] - ruikei[a - 1]);
	}
	cout << ans << endl;
	return 0;
}
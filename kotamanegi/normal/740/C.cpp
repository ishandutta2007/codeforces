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
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int maxe = 199999999;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		maxe = min(maxe, b - a);
	}
	cout << maxe + 1 << endl;
	REP(i, n) {
		cout << i % (maxe+1) << " ";
	}
	cout << endl;
	return 0;
}
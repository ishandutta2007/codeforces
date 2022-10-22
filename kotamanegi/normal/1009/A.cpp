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
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<int> hoge;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		hoge.push_back(b);
	}
	int b = 0;
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		while (b < n) {
			b++;
			if (hoge[b - 1] <= a) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
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
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	int n, m;
	cin >> n >> m;
	if (n-1 > m) {
		cout << "Impossible" << endl;
		return 0;
	}
	vector<pair<int, int>> input;
	for (int i = 1; i <= n; ++i) {
		for (int q = i+1; q <= n; ++q) {
			if (gcd(i, q) == 1) {
				input.push_back(make_pair(i, q));
				if (input.size() == m) {
					break;
				}
			}
		}
		if (input.size() == m) {
			break;
		}
	}
	if (input.size() != m) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for (int i = 0; i < input.size(); ++i) {
		cout << input[i].first << " " << input[i].second << endl;
	}
	return 0;
}
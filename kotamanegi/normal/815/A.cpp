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
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int grid[1000][1000] = {};
int cnt[2][300] = {};
int main() {
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		REP(q, m) {
			cin >> grid[i][q];
		}
	}
	int ans = 0;
	if (n < m) {
		for (int i = 0;i < n;++i) {
			int hoge = 100000000;
			for (int q = 0;q < m;++q) {
				hoge = min(hoge, grid[i][q]);
			}
			if (hoge < 0) {
				cout << "-1" << endl;
				return 0;
			}
			ans += hoge;
			cnt[0][i] = hoge;
			for (int q = 0;q < m;++q) {
				grid[i][q] -= hoge;
			}
		}
		for (int i = 0;i < m;++i) {
			int hoge = 10000000;
			for (int q = 0;q < n;++q) {
				hoge = min(hoge, grid[q][i]);
			}
			if (hoge < 0) {
				cout << -1 << endl;
			}
			ans += hoge;
			cnt[1][i] = hoge;
			for (int q = 0;q < n;++q) {
				grid[q][i] -= hoge;
			}
		}
	}else{
		for (int i = 0;i < m;++i) {
			int hoge = 10000000;
			for (int q = 0;q < n;++q) {
				hoge = min(hoge, grid[q][i]);
			}
			if (hoge < 0) {
				cout << -1 << endl;
			}
			ans += hoge;
			cnt[1][i] = hoge;
			for (int q = 0;q < n;++q) {
				grid[q][i] -= hoge;
			}
		}
		for (int i = 0;i < n;++i) {
			int hoge = 100000000;
			for (int q = 0;q < m;++q) {
				hoge = min(hoge, grid[i][q]);
			}
			if (hoge < 0) {
				cout << "-1" << endl;
				return 0;
			}
			ans += hoge;
			cnt[0][i] = hoge;
			for (int q = 0;q < m;++q) {
				grid[i][q] -= hoge;
			}
		}
	}
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			if (grid[i][q] != 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < cnt[0][i];++q) {
			cout << "row " << i + 1 << endl;
		}
	}
	for (int i = 0;i < m;++i) {
		for (int q = 0;q < cnt[1][i];++q) {
			cout << "col " << i + 1 << endl;
		}
	}
	return 0;
}
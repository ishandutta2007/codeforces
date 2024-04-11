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
#define LONG_INF 1000000000
int hoge[2000][2000] = {};
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	long long ans = n*m*4;
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			cin >> hoge[i][q];
		}
	}
	for (int i = 0;i < n;++i) {
		bool done = false;
		for (int q = 0;q < m;++q) {
			if (hoge[i][q] == 1){
				done = true;
				ans--;
			}
			else if (done == false) {
				ans--;
			}
		}
	}
	for (int i = n - 1;i >= 0;--i) {
		bool done = false;
		for (int q = m - 1;q >= 0;--q) {
			if (hoge[i][q] == 1) {
				done = true;
				ans--;
			}
			else if (done == false) ans--;
		}
	}
	for (int i = 0;i < m;++i) {
		bool done = false;
		for (int q = 0;q < n;++q) {
			if (hoge[q][i] == 1) {
				done = true;
				ans--;
			}
			else if (done == false) ans--;
		}
	}
	for (int i = 0;i < m;++i) {
		bool done = false;
		for (int q = n - 1;q >= 0;--q) {
			if (hoge[q][i] == 1) {
				done = true;
				ans--;
			}
			else if (done == false) ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
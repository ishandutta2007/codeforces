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
int wonm[100][100] = {};
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> hoge[100],calc[100];
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			int tmp;
			cin >> tmp;
			wonm[i][q] = tmp;
			calc[i].push_back(tmp);
			hoge[i].push_back(tmp);
		}
		sort(calc[i].begin(), calc[i].end());
	}
	for (int j = 0;j < n;++j) {
		int cnt = 0;
		for (int t = 0;t < m;++t) {
			if (calc[j][t] != wonm[j][t]) cnt++;
		}
		if (cnt > 2) {
			goto letsgo;
		}
	}
	cout << "YES" << endl;
	return 0;
letsgo:;
	for (int i = 0;i < m;++i) {
		for (int q = i + 1;q < m;++q) {
			for (int j = 0;j < n;++j) {
				swap(wonm[j][i], wonm[j][q]);
			}
			for (int j = 0;j < n;++j) {
				int cnt = 0;
				for (int t = 0;t < m;++t) {
					if (calc[j][t] != wonm[j][t]) cnt++;
				}
				if (cnt > 2) {
					goto failed;
				}
			}
			cout << "YES" << endl;
			return 0;
		failed:;
			for (int j = 0;j < n;++j) {
				swap(wonm[j][i], wonm[j][q]);
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
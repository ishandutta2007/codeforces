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
int hoge[5][5] = {};
int main() {
	REP(i, 4) {
		string s;
		cin >> s;
		REP(q, 4) {
			if (s[q] == 'x') {
				hoge[i][q] = 1;
			}
			else if (s[q] == '.') {
				hoge[i][q] = 2;
			}
		}
	}
	for (int i = 0;i < 4;++i) {
		for (int j = 0;j < 2;++j) {
			int cnt = 0;
			for (int t = 0;t < 3;++t) {
				if (hoge[i][j + t] == 0)goto fu;
				if (hoge[i][j + t] == 2)cnt++;
			}
			if (cnt == 1) {
				cout << "YES" << endl;
				return 0;
			}
		fu:;
			cnt = 0;
			for (int t = 0;t < 3;++t) {
				if (hoge[j + t][i] == 0) goto he;
				if (hoge[j + t][i] == 2)cnt++;
			}
			if (cnt == 1) {
				cout << "YES" << endl;
				return 0;
			}
		he:;
		}
	}
	//crossing
	for (int i = 0;i < 2;++i) {
		int cnt = 0;
		for (int q = 0;q < 3;++q) {
			if (hoge[i + q][q] == 0) goto ah;
			if (hoge[i + q][q] == 2) cnt++;
		}
		if (cnt == 1) {
			cout << "YES" << endl;
			return 0;
		}
	ah:;
		cnt = 0;
		for (int q = 0;q < 3;++q) {
			if (hoge[q][i + q] == 0) cnt = 100;
			if (hoge[q][i + q] == 2) cnt++;
		}
		if (cnt == 1) {
			cout << "YES" << endl;
			return 0;
		}
		cnt = 0;
		if (i == 0) {
			for (int q = 0;q < 3;++q) {
				if (hoge[1 + q][1 + q] == 0) cnt = 100;
				if (hoge[1 + q][1 + q] == 2) cnt++;
			}
			if (cnt == 1) {
				cout << "YES" << endl;
				return 0;
			}
		}
		cnt = 0;
		for (int q = 0;q < 3;++q) {
			if (hoge[3 - (i + q)][q] == 0) cnt = 100;
			if (hoge[3-(i + q)][q] == 2) cnt++;
		}
		if (cnt == 1) {
			cout << "YES" << endl;
			return 0;
		}
		cnt = 0;
		if (cnt == 1) {
			cout << "YES" << endl;
			return 0;
		}
		cnt = 0;
		if (i == 0) {
			for (int q = 0;q < 3;++q) {
				if (hoge[2-q][1 + q] == 0) cnt = 100;
				if (hoge[2-q][1 + q] == 2) cnt++;
			}
			if (cnt == 1) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	int cnt = 0;
	for (int q = 2;q >= 0;--q) {
		if (hoge[1+q][3 - q] == 0) cnt = 100;
		if (hoge[1+q][3 - q] == 2) cnt++;
	}
	if (cnt == 1) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
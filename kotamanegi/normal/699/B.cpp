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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int counter[2][3000] = {};
int mapping[3000][3000] = {};
int cnt = 0;
int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 1;i <= a;++i) {
		string hoge;
		cin >> hoge;
		for (int q = 1;q <= b;++q) {
			if (hoge[q - 1] == '*') {
				counter[0][i]++;
				counter[1][q]++;
				cnt++;
				mapping[i][q] = 1;
			}
		}
	}
	for (int i = 1;i <= a;++i) {
		for (int q = 1;q <= b;++q) {
			int hoge = counter[0][i] + counter[1][q];
			if (mapping[i][q] == 1) {
				hoge--;
			}
			if (hoge == cnt) {
				cout << "YES" << endl;
				cout << i << " " << q << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
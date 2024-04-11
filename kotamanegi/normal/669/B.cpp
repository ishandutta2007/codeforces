#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define  _SCL_SECURE_NO_WARNINGS
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
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int d[200000] = {};
int next_comed[200000] = {};
int main() {
	int n;
	cin >> n;
	string hoge;
	cin >> hoge;
	REP(i, n) {
		cin >> d[i];
	}
	queue<int> next_gp;
	next_gp.push(0);
	while (next_gp.size()) {
		int hogehoge = next_gp.front();
		next_gp.pop();
		if (hogehoge > -1 && hogehoge < n) {
			if (next_comed[hogehoge] == true) {
				cout << "INFINITE" << endl;
				return 0;
			}
			next_comed[hogehoge] = true;
			if (hoge[hogehoge] == '>') {
				next_gp.push(hogehoge + d[hogehoge]);
			}
			else {
				next_gp.push(hogehoge - d[hogehoge]);
			}
		}
	}
	cout << "FINITE" << endl;
}
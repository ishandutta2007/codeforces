#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	string n;
	cin >> n;
	int hoge[10] = {};
	REP(i, n.length()) {
		hoge[i + 1] = (int)n[i]-48;
	}
	swap(hoge[3], hoge[2]);
	swap(hoge[3], hoge[5]);
	long long number = hoge[1] * 10000 + hoge[2] * 1000 + hoge[3] * 100 + hoge[4] * 10 + hoge[5];
	long long answer = number;
	REP(i,4) {
		answer = answer*number % 100000;
	}
	int hogehoge[10] = {};
	hogehoge[0] = answer % 10;
	answer /= 10;
	hogehoge[1] = answer % 10;
	answer /= 10;
	hogehoge[2] = answer % 10;
	answer /= 10;
	hogehoge[3] = answer % 10;
	answer /= 10;
	hogehoge[4] = answer % 10;
	REP(i, 5) {
		cout << hogehoge[4-i];
	}
	cout << endl;
}
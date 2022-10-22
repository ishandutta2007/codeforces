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
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	queue<int> a, b;
	REP(i, n) {
		if (s[i] == 'D') {
			a.push(i);
		}
		else {
			b.push(i);
		}
	}
	while (a.empty() == false && b.empty() == false) {
		if (a.front() < b.front()) {
			int hoge = a.front();
			a.push(hoge+n);
			a.pop();
			b.pop();
		}
		else {
			int hoge = b.front();
			b.push(hoge+n);
			b.pop();
			a.pop();
		}
	}
	if (a.empty() == true) {
		cout << "R" << endl;
	}
	else cout << "D" << endl;
	return 0;
}
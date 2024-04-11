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
	string a, b;
	cin >> a >> b;
	string clear_a, clear_b;
	bool wow = false;
	for (int i = 0;i < a.length();++i) {
		if (wow == true || a[i] != '0') {
			clear_a.push_back(a[i]);
			wow = true;
		}
	}
	wow = false;
	REP(i, b.length()) {
		if (wow == true || b[i] != '0') {
			clear_b.push_back(b[i]);
			wow = true;
		}
	}
	if (clear_a.length() < clear_b.length()) {
		cout << "<" << endl;
		return 0;
	}
	else if (clear_a.length() > clear_b.length()) {
		cout << ">" << endl;
		return 0;
	}
	else {
		for (int i = 0;i < clear_a.length();++i) {
			if (clear_a[i] < clear_b[i]) {
				cout << "<" << endl;
				return 0;
			}
			else if (clear_a[i] > clear_b[i]) {
				cout << ">" << endl;
				return 0;
			}
		}
		cout << "=" << endl;
		return 0;
	}
}
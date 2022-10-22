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
string t, p;
vector<int> listings;
int dissappear[300000] = {};
int ok(int n) {
	for (int i = 0;i < n;++i) {
		dissappear[listings[i]] = 1;
	}
	for (int i = n;i < t.length();++i) {
		dissappear[listings[i]] = 0;
	}
	int pointer = 0;
	for (int i = 0;i < t.length();++i) {
		if (dissappear[i] == 0) {
			if (p[pointer] == t[i]) {
				pointer++;
				if (pointer == p.length()) return 1;
			}
		}
	}
	return 0;
}
int main() {
	cin >> t >> p;
	REP(i, t.length()) {
		int a;
		cin >> a;
		listings.push_back(a-1);
	}
	int top = listings.size() - 1;
	int bot = 0;
	while (top - bot > 1) {
		int mid = top + bot;
		mid /= 2;
		if (ok(mid)) {
			bot = mid;
		}
		else top = mid;
	}
	if (ok(top)) {
		cout << top << endl;
	}
	else {
		cout << bot << endl;
	}
	return 0;
}
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
	int x_dist = 0;
	for (int i = 0;i < n;++i) {
		int a;
		string b;
		cin >> a >> b;
		if (b == "South") {
			x_dist += a;
			if (x_dist > 20000) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else if (b == "North") {
			x_dist -= a;
			if (x_dist < 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
			if (x_dist == 0 || x_dist == 20000) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (x_dist == 0) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
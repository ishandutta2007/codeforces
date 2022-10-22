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
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int n;
	vector<int> a;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	if (n == 1) {
		if (a[0] == 15) {
			cout << "DOWN" << endl;
			return 0;
		}
		else if (a[0] == 0) {
			cout << "UP" << endl;
			return 0;
		}
		cout << "-1" << endl;
	}
	else {
		if (a[n - 2] > a[n - 1]) {
			if (a[n - 1] != 0) {
				cout << "DOWN" << endl;
			}else{
				cout << "UP" << endl;
			}
		}
		else {
			if (a[n - 1] != 15) {
				cout << "UP" << endl;
			}
			else {
				cout << "DOWN" << endl;
			}
		}
	}
}
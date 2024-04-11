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
#define LONG_INF 800000000000000000
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n/2) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	if (n % 2 == 0) {
		a.push_back(-1);
	}
	for (int i = n / 2;i < n;++i) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int wow = 0;
	if (n % 2 == 0) {
		n++;
		wow = true;
	}
	for (int i = 0;i < n;++i) {
		if (wow == false || i != n / 2) {
			if (i % 2 == 1) {
				cout << a[i] << " ";
			}
			else {
				cout << a[n - i - 1] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}
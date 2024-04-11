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
	int n, l;
	cin >> n >> l;
	vector<int> a,b;
	REP(i, n) {
		int c;
		cin >> c;
		a.push_back(c);
	}
	REP(i, n) {
		int c;
		cin >> c;
		b.push_back(c);
	}
	a.push_back(a[0]+l);
	b.push_back(b[0]+l);
	vector<int> first_diff,second_diff;
	for (int i = 1;i < a.size();++i) {
		first_diff.push_back(a[i] - a[i - 1]);
	}
	for (int q = 1;q < b.size();++q) {
		second_diff.push_back(b[q] - b[q - 1]);
	}
	for (int i = 0;i < first_diff.size();++i) {
		for (int q = 0;q < second_diff.size();++q) {
			for (int j = 0;j < first_diff.size();++j) {
				if (first_diff[(i + j) % first_diff.size()] != second_diff[(q + j) % second_diff.size()]) goto failed;
			}
			cout << "YES" << endl;
			return 0;
		failed:;
		}
	}
	cout << "NO" << endl;
	return 0;
}
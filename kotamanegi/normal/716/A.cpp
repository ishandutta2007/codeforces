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
	int n, c;
	cin >> n >> c;
	vector<int> t;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	int cnt = 1;
	for (int i = 1;i < n;++i) {
		if (t[i] - t[i - 1] > c) {
			cnt = 0;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
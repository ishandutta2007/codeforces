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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	long long n, a;
	cin >> n >> a;
	vector<long long> toku;
	int cnt = 0;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		if (tmp != a) {
			toku.push_back(tmp);
		}else{
			cnt++;
		}
	}
	n -= cnt;
	sort(toku.begin(),toku.end());
	long long min_ans;
	if (n >= 2) {
		min_ans = min(abs(a - toku[0]), abs(a - toku[n - 2])) + abs(toku[n - 2] - toku[0]);
		long long hoge = min(abs(a - toku[n - 1]), abs(a - toku[1])) + abs(toku[n - 1] - toku[1]);
		min_ans = min(hoge, min_ans);
	}
	else {
		min_ans = 0;
	}
	cout	<< min_ans << endl;
}
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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int n;
	cin >> n;
	long long left = 0;
	long long right = 0;
	vector<pair<long long, long long>> wow;
	wow.push_back(make_pair(0, 0));
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		left += a;
		right += b;
		wow.push_back(make_pair(a, b));
	}
	long long now_ans = labs(left - right);
	long long index = 0;
	for (int i = 0;i < wow.size();++i) {
		long long a = left - wow[i].first + wow[i].second;
		long long b = right - wow[i].second + wow[i].first;
		if (labs(a - b) > now_ans) {
			now_ans = labs(a - b);
			index = i;
		}
	}
	cout << index << endl;
	return 0;
}
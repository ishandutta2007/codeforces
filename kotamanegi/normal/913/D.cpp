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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
long long n, t;
vector<tuple<long long,long long,long long>> wow;
long long solve(long long border) {
	long long cnt = 0;
	long long now_time = 0;
	for (int i = 0;i < n;++i) {
		if (get<1>(wow[i]) >= border) {
			cnt++;
			now_time += get<0>(wow[i]);
			if (cnt == border) {
				if (now_time <= t) return 1;
				return 0;
			}
		}
	}
	return 0;
}
int main(){
	cin >> n >> t;
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		wow.push_back(make_tuple(b, a,i+1));
	}
	sort(wow.begin(), wow.end());
	long long bot = 0;
	long long top = n;
	while (top - bot > 1) {
		long long mid = (top + bot) / 2;
		if (solve(mid)) bot = mid;
		else top = mid;
	}
	long long estimate = 0;
	if (solve(top)) {
		estimate = top;
	}
	else estimate = bot;
	cout << estimate << endl;
	cout << estimate << endl;
	if (estimate == 0) {
		cout << endl;
		return 0;
	}
	long long cnt = 0;
	for (int i = 0;i < n;++i) {
		if (get<1>(wow[i]) >= estimate) {
			cnt++;
			cout << get<2>(wow[i]) << " ";
			if (cnt == estimate) {
				cout << endl;
				return 0;
			}
		}
	}
	assert(1 == 0);
}
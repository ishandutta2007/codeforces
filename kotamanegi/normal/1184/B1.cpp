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
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long final_ans[200000];
int main() {
	long long s, b;
	cin >> s >> b;
	vector<pair<long long,long long>> gogo;
	REP(i, s) {
		long long a;
		cin >> a;
		gogo.push_back(make_pair(a, i));
	}
	long long ans = 0;
	vector<pair<long long, long long>> inputs;
	REP(i, b) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
	}
	sort(inputs.begin(), inputs.end());
	sort(gogo.begin(), gogo.end());
	inputs.push_back(make_pair(1e10, 0));
	int now_itr = 0;
	for (int q = 0; q < gogo.size(); ++q) {
		while (inputs[now_itr].first <= gogo[q].first) {
			ans += inputs[now_itr].second;
			now_itr++;
		}
		final_ans[gogo[q].second] = ans;
	}
	REP(q, gogo.size()) {
		cout << final_ans[q] << " ";
	}
	cout << endl;
}
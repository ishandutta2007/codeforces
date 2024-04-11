//J^!w

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
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int broken[400000];
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> inputs;
	vector<tuple<int, int, int>> basics;
	REP(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		basics.push_back(make_tuple(a, b, c));
		inputs.push_back(make_tuple(a, b, c, i+1));
	}
	vector<pair<int, int>> ans;
	sort(inputs.begin(), inputs.end());
	for(int i = 1;i < n;++i){
		if (get<0>(inputs[i]) == get<0>(inputs[i - 1]) && get<1>(inputs[i]) == get<1>(inputs[i - 1])) {
			broken[get<3>(inputs[i])] = 1;
			broken[get<3>(inputs[i - 1])] = 1;
			ans.push_back(make_pair(get<3>(inputs[i - 1]), get<3>(inputs[i])));
			i++;
		}
	}
	vector<int> bobo;
	REP(i, n) {
		if (broken[get<3>(inputs[i])] == 0) {
			bobo.push_back(i);
		}
	}
	for (int i = 1; i < bobo.size();++i) {
		int a_itr = bobo[i - 1];
		int b_itr = bobo[i];
		if (get<0>(inputs[a_itr]) == get<0>(inputs[b_itr])) {
			broken[get<3>(inputs[a_itr])] = 1;
			broken[get<3>(inputs[b_itr])] = 1;
			ans.push_back(make_pair(get<3>(inputs[a_itr]), get<3>(inputs[b_itr])));
			i++;
		}
	}
	bobo.clear();
	REP(i, n) {
		if (broken[get<3>(inputs[i])] == 0) {
			bobo.push_back(get<3>(inputs[i]));
		}
	}
	REP(i, bobo.size()) {
		ans.push_back(make_pair(bobo[i], bobo[i + 1]));
		i++;
	}
	REP(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	REP(i, n) {
		broken[i + 1] = 0;
	}
}
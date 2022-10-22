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
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	string s;
	cin >> s;
	int now = 1;
	char hoge = s[0];
	vector<pair<int, char>> inputs;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == hoge) {
			now++;
		}
		else {
			inputs.push_back(make_pair(now, hoge));
			hoge = s[i];
			now = 1;
		}
	}
	inputs.push_back(make_pair(now, hoge));
	if (inputs.size() % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}
	int target = inputs.size() / 2;
	if (inputs[target].first == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int q = 0; q < target; ++q) {
		if (inputs[target - q - 1].first + inputs[target + q + 1].first <= 2 || inputs[target - q - 1].second != inputs[target + q + 1].second) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << inputs[target].first+1 << endl;
}
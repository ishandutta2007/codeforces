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
	int n, x;
	cin >> n >> x;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	map<int, int> hogea;
	hogea[inputs[0]] = 1;
	for (int i = 1; i < n; ++i) {
		if (inputs[i - 1] == inputs[i]) {
			cout << "0" << endl;
			return 0;
		}
		hogea[inputs[i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if ((inputs[i]&x) != inputs[i]) {
			if (hogea.find(inputs[i] & x) != hogea.end()) {
				cout << "1" << endl;
				return 0;
			}
		}
	}
	REP(i, n) {
		if ((inputs[i]&x) != inputs[i]) {
			if (hogea.find(inputs[i] & x) != hogea.end()) {
				cout << "2" << endl;
				return 0;
			}
		}
		hogea[(inputs[i] & x)] = 1;
	}
	cout << -1 << endl;
}
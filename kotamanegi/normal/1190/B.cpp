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
int main() {
	iostream::sync_with_stdio(false);
#define int long long
	int n;
	cin >> n;
	vector<long long> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	int cnt = 0;
	REP(i, n) {
		if (inputs[i] != 0) cnt = 1;
	}
	if (cnt == 0) {
		cout << "cslnb" << endl;
		return 0;
	}
	cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (inputs[i] == inputs[i - 1])cnt++;
	}
	if (cnt >= 2) {
		cout << "cslnb" << endl;
		return 0;
	}
	if (inputs[1] == inputs[0]) {
		if (inputs[0] == 0) {
			cout << "cslnb" << endl;
			return 0;
		}
	}
	cnt = 0;
	for (int i = 2; i < n; ++i) {
		if (inputs[i] == inputs[i - 1]) {
			if (inputs[i - 2] == inputs[i - 1] - 1LL) {
				cout << "cslnb" << endl;
				return 0;
			}
		}
	}
	long long ans = 0;
	for(long long i = 0;i < n;++i){
		ans += inputs[i] - i;
	}
	if (ans % 2 == 0) {
		cout << "cslnb" << endl;
	}
	else {
		cout << "sjfnb" << endl;
	}
	return 0;
}
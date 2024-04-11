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
int cnt[4000];

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> inputs;
	REP(i, n) {
		string s;
		cin >> s;
		inputs.push_back(s);
		REP(q, m) {
			if (s[q] == '1') {
				cnt[q]++;
			}
		}
	}
	REP(i, n) {
		int ok = 1;
		REP(q, m) {
			if (inputs[i][q] == '1') {
				if (cnt[q] == 1) ok = 0;
			}
		}
		if (ok == 1) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}
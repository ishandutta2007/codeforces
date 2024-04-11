
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
int go[10000];
int main() {
	int x, n;
	cin >> x >> n;
	REP(i, n) {
		int a;
		cin >> a;
		REP(q, 3 - a) {
			int b;
			cin >> b;
			go[b] = 1;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < x; ++i) {
		if (go[i] == 0) {
			ans1++;
			ans2++;
			if (i + 1 < x && go[i + 1] == 0) {
				i++;
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2 << endl;
}
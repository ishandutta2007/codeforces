
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
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	cout << 2 - ((r1 == r2) + (c1 == c2));
	cout << " ";
	if ((r1 + c1) % 2 != (r2 + c2) % 2) {
		cout << 0;
	}
	else {
		int xe[2] = { 1,-1 };
		int ok = 0;
		REP(t, 4) {
			REP(j, 10) {
				int x = r1 + xe[t % 2] * j;
				int y = c1 + xe[t / 2] * j;
				if (x == r2 && y == c2) {
					ok = 1;
				}
			}
		}
		cout << 2 - ok;
	}
	cout << " " << max(abs(r1 - r2),abs(c1 - c2)) << endl;
}
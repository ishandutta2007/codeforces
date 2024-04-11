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
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 262144
int main() {
#define int long long
	int a, b, f, k;
	cin >> a >> b >> f >> k;
	long long ans = 0;
	long long now_fuel = b;
	while (k != 0) {
		now_fuel -= f;
		if (now_fuel < 0) {
			cout << -1 << endl;
			return 0;
		}
		if (now_fuel - (a - f) < 0) {
			now_fuel = b;
			ans++;
		}
		else if (k != 1 && now_fuel - 2 * (a - f) < 0) {
			now_fuel = b;
			ans++;
		}
		now_fuel -= (a - f);
		if (now_fuel < 0) {
			cout << -1 << endl;
			return 0;
		}
		k--;
		if (k == 0) break;
		now_fuel -= (a - f);
		if (now_fuel < 0) {
			cout << -1 << endl;
			return 0;
		}
		if (now_fuel - f < 0) {
			now_fuel = b;
			ans++;
		}
		else if (k != 1 && now_fuel - 2 * f < 0) {
			now_fuel = b;
			ans++;
		}
		now_fuel -= f;
		if (now_fuel < 0) {
			cout << -1 << endl;
			return 0;
		}
		k--;
		if (k == 0) break;
	}
	cout << ans << endl;
	return 0;
}
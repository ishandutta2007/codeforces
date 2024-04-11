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
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	int visited[2000] = {};
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (visited[i] == 0) {
			visited[i] = 1;
			ans++;
			for (int q = i; q < a.size(); ++q) {
				if (a[q] % a[i] == 0) {
					visited[q] = 1;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
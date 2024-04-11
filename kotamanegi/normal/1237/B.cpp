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
int targets[300000];
int already_done[300000];
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a, b;
	REP(i, n) {
		int c;
		cin >> c;
		a.push_back(c);
		targets[c] = i;
	}
	REP(i, n) {
		int c;
		cin >> c;
		b.push_back(c);
	}
	int itr = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[itr] != b[i]) {
			ans++;
			already_done[targets[b[i]]] = 1;
		}
		else {
			already_done[itr] = 1;
			while (already_done[itr] == 1) {
				itr++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
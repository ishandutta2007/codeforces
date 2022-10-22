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
#define seg_size 524288
vector<pair<int, int>> vertexs[200000];
int main() {
	int n;
	cin >> n;
	int ok = 1;
	REP(i, n - 1) {
		int a, b, c;
		cin >> a >> b;
		c = 1;
		if (c != 0) {
			ok = 0;
		}
		vertexs[a].push_back(make_pair(b, c));
		vertexs[b].push_back(make_pair(a, c));
	}
	if (ok == 1) {
		cout << "YES" << endl;
		cout << "0" << endl;
		return 0;
	}
	ok = 1;
	for (int i = 1; i <= n; ++i) {
		if (vertexs[i].size() == 2) {
			ok = 0;
			break;
		}
	}
	if (ok == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
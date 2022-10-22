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
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int gogo[2000][2000] = {};
int grid[2000][2000] = {};
int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, m) {
			if (s[q] == '#') {
				gogo[i][q] = 1;
			}
		}
	}
	int xe[8] = { 1,1,1,0,0,-1,-1,-1 };
	int ye[8] = { 1,0,-1,1,-1,1,0,-1 };
	for (int i = 1; i < n - 1; ++i) {
		for (int q = 1; q < m - 1; ++q) {
			int ok = 1;
			for (int t = 0; t < 8; ++t) {
				if (gogo[i + xe[t]][q + ye[t]] == 0) {
					ok = 0;
				}
			}
			if (ok == 1) {
				for (int t = 0; t < 8; ++t) {
					grid[i + xe[t]][q + ye[t]] = 1;
				}
			}
		}
	}
	REP(i, n) {
		REP(q, m) {
			if (gogo[i][q] != grid[i][q]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
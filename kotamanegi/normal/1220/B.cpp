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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long grid[2000][2000];
int main(){
	int n;
	cin >> n;
	REP(i, n) {
		REP(q, n) {
			cin >> grid[i][q];
		}
	}
	vector<long long> kouho;
	for (int i = 1; i <= sqrt(grid[0][1]); ++i) {
		if (grid[0][1] % i == 0) {
			kouho.push_back(i);
			kouho.push_back(grid[0][1] / i);
		}
	}
	REP(i, kouho.size()) {
		vector<long long> nya;
		nya.push_back(kouho[i]);
		int ok = 1;
		for (int q = 1; q < n; ++q) {
			if (grid[0][q] % kouho[i] != 0) {
				ok = 0;
				break;
			}
			nya.push_back(grid[0][q] / kouho[i]);
		}
		if (ok == 0) continue;
		for (int q = 1; q < n; ++q) {
			for (int j = q + 1; j < n; ++j) {
				if (grid[q][j] != nya[q] * nya[j]) {
					ok = 0;
					break;
				}
			}
		}
		if (ok == 0) continue;
		cout << nya[0];
		REP(q, nya.size() - 1) {
			cout << " " << nya[q + 1];
		}
		cout << endl;
		return 0;
	}
}
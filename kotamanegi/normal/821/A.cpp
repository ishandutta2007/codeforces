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
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int grid[100][100] = {};
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		REP(q, n) {
			cin >> grid[i][q];
		}
	}
	REP(i, n) {
		REP(q, n) {
			if (grid[i][q] != 1) {
				REP(j, n) {
					REP(t, n) {
						if (grid[i][q] == grid[i][j] + grid[t][q]) goto ok;
					}
				}
				cout << "NO" << endl;
				return 0;
			}
		ok:;
		}
	}
	cout << "YES" << endl;
}
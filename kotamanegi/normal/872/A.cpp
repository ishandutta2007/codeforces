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
#define seg_size 524288
int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> geko;
	REP(i, n + m) {
		int tmp;
		cin >> tmp;
		geko[tmp]++;
		if (i >= n) {
			geko[tmp]++;
		}
	}
	for (int i = 1;i <= 9;++i) {
		if (geko[i] >= 3) {
			cout << i << endl;
			return 0;
		}
	}
	for (int i = 1;i <= 9;++i) {
		if (geko[i]) {
			cout << i;
			for (int q = i + 1;q <= 9;++q) {
				if (geko[q] > 0&&geko[q] != geko[i]) {
					cout << q << endl;
					return 0;
				}
			}
		}
	}
}
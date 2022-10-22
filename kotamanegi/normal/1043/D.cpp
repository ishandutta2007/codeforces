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
vector<int> firsting;
unordered_map<int, int> gogo[9];
int now_itr[9] = {};
int main() {
	int challenge = rand();
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) {
		int tmp;
		scanf("%d", &tmp);
		firsting.push_back(tmp);
	}
	m--;
	REP(i, m) {
		REP(q, n) {
			int a;
			scanf("%d", &a);
			gogo[i][a^challenge] = q + 1;
		}
	}
	int back = n;
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i < back) {
			back = i;
			for (int q = 0; q < m; ++q) {
				now_itr[q] = gogo[q][firsting[i] ^ challenge];
			}
		}
		int ok = 1;
		while (back != 0&&ok == 1) {
			for (int q = 0; q < m; ++q) {
				if (now_itr[q] - 1 != gogo[q][firsting[back - 1] ^ challenge]) ok = 0;
			}
			if (ok == 1) {
				for (int i = 0; i < m; ++i) {
					now_itr[i]--;
				}
				back--;
			}
		}
		ans += i - back + 1;
	}
	cout << ans << endl;
	return 0;
}
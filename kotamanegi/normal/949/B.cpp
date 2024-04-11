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
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
#define int long long
	long long n, query;
	cin >> n >> query;
	for (int i = 0; i < query; ++i) {
		int a;
		cin >> a;
		a--;
		long long now_down = 0;
		long long now_size = n;
		while (now_size != 1) {
			if (now_down % 2 == 0) {
				if (a % 2 == 0) {
					cout << (2 + now_down + a) / 2 << endl;
					goto ok;
				}
				now_down += now_size;
				now_size /= 2;
				a /= 2;
			}
			else {
				if (a % 2 == 1) {
					cout << (2 + now_down + a) / 2 << endl;
					goto ok;
				}
				now_down += now_size;
				now_size++;
				now_size /= 2;
				a /= 2;
			}
		}
		cout << n << endl;
	ok:;
	}
	return 0;
}
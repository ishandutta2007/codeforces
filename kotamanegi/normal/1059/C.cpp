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
int func(int now, int multi) {
	if (now >= 4) {
		long long geko = (now + 1) / 2;
		REP(i, geko) {
			cout << multi << " ";
		}
		now -= geko;
		func(now, multi*2);
		return 0;
	}
	if (now == 1) {
		cout << multi << endl;
		return 0;
	}
	if (now == 2) {
		cout << multi << " " << multi * 2 << endl;
		return 0;
	}
	if (now == 3) {
		cout << multi << " " << multi << " " << multi * 3 << endl;
		return 0;
	}
}
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	func(n, 1);
	return 0;
}
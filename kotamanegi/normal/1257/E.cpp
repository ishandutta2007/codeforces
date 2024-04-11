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
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int coloring[300000];
int ans[3][300000];
int main(){
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	REP(i, k1) {
		int a;
		cin >> a;
		coloring[a] = 1;
	}
	REP(i, k2) {
		int a;
		cin >> a;
		coloring[a] = 2;
	}
	REP(i, k3) {
		int a;
		cin >> a;
		coloring[a] = 3;
	}
	for (int i = 1; i <= 200000; ++i) {
		ans[0][i] = ans[0][i - 1];
		if (coloring[i] == 1) {
			ans[0][i]++;
		}
	}
	for (int i = 1; i <= 200000; ++i) {
		int hoge = 0;
		if (coloring[i] == 2) {
			hoge = 1;
		}
		ans[1][i] = max(ans[1][i - 1] + hoge, ans[0][i - 1] + hoge);
	}
	for (int i = 200000; i >= 1;--i) {
		ans[2][i] = ans[2][i + 1];
		if (coloring[i] == 3) {
			ans[2][i]++;
		}
	}
	int final_ans = 0;
	for (int i = 1; i <= 200000; ++i) {
		final_ans = max({ final_ans,ans[1][i] + ans[2][i + 1],ans[0][i] + ans[2][i + 1],ans[1][i],ans[0][i],ans[2][i] });
	}
	cout << k1 + k2 + k3 - final_ans << endl;
}
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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int dp[4][200000];
int main(){
	string s;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 0; i < s.length(); ++i) {
		for (int q = 0; q <= 3; ++q) {
			if (dp[q][i] == 0) continue;
			dp[q][i + 1] = 1;
			if (i + 1 < s.length()) {
				if (s[i] == 'A' && s[i+1] == 'B') {
					dp[(q | 1)][i + 2] = 1;
				}
				if (s[i] == 'B' && s[i + 1] == 'A') {
					dp[(q | 2)][i + 2] = 1;
				}
			}
		}
	}
	if (dp[3][s.length()] == 1) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}
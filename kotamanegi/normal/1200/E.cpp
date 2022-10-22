
/*

This Submission is to determine how many 120/240 min const. delivery point there are.

*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000009
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int main() {
#define int long long
	int n;
	cin >> n;
	vector<int> go;
	REP(i, n) {
		string s;
		cin >> s;
		vector<int> pre_merge;
		REP(q, s.length()) {
			if (s[q] >= '0' && s[q] <= '9') {
				pre_merge.push_back(s[q] - '0');
			}
			else if (s[q] >= 'a' && s[q] <= 'z') {
				pre_merge.push_back(s[q] - 'a' + 10);
			}
			else {
				pre_merge.push_back(s[q] - 'A' + 36);
			}
		}
		//total 62
		long long now_max = 0;
		long long dp1 = 0;//MAX_MOD
		long long dp2 = 0;//MOD
		long long tmp1 = 1;
		long long tmp2 = 1;
		long long go_dp1 = 0;
		long long go_dp2 = 0;
		for (int q = 0; q < min(go.size(), pre_merge.size()); ++q) {
			dp1 *= 62LL;
			dp2 *= 62LL;
			dp1 += go[go.size() - q - 1];
			dp2 += go[go.size() - q - 1];
			dp1 %= MAX_MOD;
			dp2 %= MOD;
			go_dp1 += pre_merge[q] * tmp1;
			go_dp2 += pre_merge[q] * tmp2;
			go_dp1 %= MAX_MOD;
			go_dp2 %= MOD;
			tmp1 *= 62LL;
			tmp2 *= 62LL;
			tmp1 %= MAX_MOD;
			tmp2 %= MOD;
			if (dp1 == go_dp1 && dp2 == go_dp2) {
				now_max = q + 1;
			}
		}
		for (int i = now_max; i < pre_merge.size();++i) {
			go.push_back(pre_merge[i]);
		}
	}
	REP(i, go.size()) {
		if (go[i] <= 9) {
			cout << go[i];
		}
		else if (go[i] <= 35) {
			cout << (char)(go[i] - 10 + 'a');
		}
		else {
			cout << (char)(go[i] - 36 + 'A');
		}
	}
	cout << endl;
	return 0;
}
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
int cnt[27];
string ans[2000];
int main() {
	int n, l, k;
	cin >> n >> l >> k;
	string s;
	cin >> s;
	REP(i, s.length()) {
		cnt[s[i] - 'a']++;
	}
	cnt[26] = 1;
	int left = 1;
	for (int q = 1; q <= l; ++q) {
		int now_itr = 0;
		for (int j = left; j <= k; ++j) {
			while (cnt[now_itr] == 0) {
				now_itr++;
			}
			ans[j].push_back('a' + now_itr);
			cnt[now_itr]--;
		}
		while (left != k && ans[k].back() != ans[left].back()) {
			left++;
		}
	}
	int now_itr = 0;
	for (int j = 1; j <= n; ++j) {
		while (ans[j].length() != l) {
			while (cnt[now_itr] == 0) {
				now_itr++;
			}
			ans[j].push_back('a' + now_itr);
			cnt[now_itr]--;
		}
	}
	for (int q = 1; q <= n; ++q) {
		cout << ans[q] << endl;
	}
}
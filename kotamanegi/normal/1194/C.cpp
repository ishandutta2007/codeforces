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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int query;
	cin >> query;
	REP(i, query) {
		string s, t, p;
		cin >> s >> t >> p;
		int te[26] = {};
		REP(i, p.length()) {
			te[p[i] - 'a']++;
		}
		int winning[102][26] = {};
		for (int i = 1; i <= t.length(); ++i) {
			REP(q, 26) {
				winning[i][q] = winning[i - 1][q];
			}
			winning[i][t[i-1] - 'a']++;
		}
		int lose[102][26] = {};
		for (int i = 1; i <= s.length(); ++i) {
			REP(q, 26) {
				lose[i][q] = lose[i - 1][q];
			}
			lose[i][s[i - 1] - 'a']++;
		}
		int dp[102][102] = {};
		dp[0][0] = 1;
		for (int i = 0; i <= s.length(); ++i) {
			for (int q = i; q < t.length(); ++q) {
				if (dp[i][q] == 0) continue;
				if (i != s.length() && s[i] == t[q]) {
					//use s
					dp[i + 1][q + 1] = 1;
				}
				int tyakumoku = t[q] - 'a';
				if (winning[q][tyakumoku] - lose[i][tyakumoku] + 1 <= te[tyakumoku]) {
					dp[i][q + 1] = 1;
				}
			}
		}
		if (dp[s.length()][t.length()] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
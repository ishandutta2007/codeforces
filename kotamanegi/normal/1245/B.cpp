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
int main() {
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		int win = 0;
		string ans;
		for (int q = 0; q < s.length(); ++q) {
			if (s[q] == 'R') {
				if (b == 0) {
					ans.push_back('?');
				}
				else {
					ans.push_back('P');
					win++;
					b--;
				}
			}
			else if (s[q] == 'P') {
				if (c == 0) {
					ans.push_back('?');
				}
				else {
					ans.push_back('S');
					win++;
					c--;
				}
			}
			else {
				if (a == 0) {
					ans.push_back('?');
				}
				else {
					ans.push_back('R');
					win++;
					a--;
				}
			}
		}
		REP(i, ans.size()) {
			if (ans[i] == '?') {
				if (a != 0) {
					a--;
					ans[i] = 'R';
				}
				else if (b != 0) {
					b--;
					ans[i] = 'P';
				}
				else {
					c--;
					ans[i] = 'S';
				}
			}
		}
		if (win >= (n+1)/2) {
			cout << "YES" << endl;
			cout << ans << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
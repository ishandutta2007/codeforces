//J^!w

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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
set<int> finding[30];
int main() {
	string s;
	cin >> s;
	REP(i, s.length()) {
		finding[s[i] - 'a'].insert(i);
	}
	int query;
	cin >> query;
	REP(i, query) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			char c;
			cin >> b >> c;
			b--;
			finding[s[b] - 'a'].erase(b);
			s[b] = c;
			finding[s[b] - 'a'].insert(b);
		}
		else {
			int b, c;
			cin >> b >> c;
			b--; c--;
			int ans = 0;
			for (int i = 0; i < 26; ++i) {
				auto q = finding[i].lower_bound(b);
				if (q != finding[i].end()) {
					if (*q <= c) {
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
}
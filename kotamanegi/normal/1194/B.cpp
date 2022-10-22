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
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(tea, query) {
		int n, m;
		cin >> n >> m;
		vector<int> neko;
		vector<int> x;
		REP(q, m) {
			neko.push_back(0);
		}
		vector<string> geko;
		REP(i, n) {
			string a;
			cin >> a;
			geko.push_back(a);
			int tmp = 0;
			REP(q, a.length()) {
				if (a[q] == '.') {
					tmp++;
					neko[q]++;
				}
			}
			x.push_back(tmp);
		}
		int ans = n + m + 1;
		REP(i, n) {
			REP(q, m) {
				if (geko[i][q] == '.') {
					ans = min(ans, x[i] + neko[q] - 1);
				}
				else {
					ans = min(ans, x[i] + neko[q]);
				}
			}
		}
		cout << ans << endl;
	}
}
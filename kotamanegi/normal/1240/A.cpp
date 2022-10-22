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
#define int long long
vector<long long> pricing;
long long a, b, x, y;
long long value(long long border) {
	long long now_itr = 0;
	long long cnt_x = 0, cnt_y = 0;
	long long cnt_xy = 0;
	for (int q = 1; q <= border+1; ++q) {
		if (q % a == 0 && q % b == 0) {
			cnt_xy++;
		}
		else if (q % a == 0) {
			cnt_x++;
		}
		else if(q % b == 0) {
			cnt_y++;
		}
	}
	long long ans = 0;
	REP(q, cnt_xy) {
		ans += pricing[now_itr] * (x + y) / 100LL;
		now_itr++;
	}
	REP(q, cnt_x) {
		ans += pricing[now_itr] * x / 100LL;
		now_itr++;
	}
	REP(q, cnt_y) {
		ans += pricing[now_itr] * y / 100LL;
		now_itr++;
	}
	return ans;
}
#undef int
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int query;
	cin >> query;
	REP(hoge, query) {
		long long n;
		cin >> n;
		pricing.clear();
		REP(i, n) {
			long long a;
			cin >> a;
			pricing.push_back(a);
		}
		sort(pricing.begin(), pricing.end());
		reverse(pricing.begin(), pricing.end());
		cin >> x >> a >> y >> b;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		long long k;
		cin >> k;
		long long bot = n;
		long long top = -1;
		while (abs(top - bot) > 1) {
			long long mid = (top + bot) / 2;
			if (value(mid) >= k) {
				bot = mid;
			}
			else {
				top = mid;
			}
		}
		if (bot == n) {
			bot = -2;
		}
		cout << bot+1 << endl;
	}
}
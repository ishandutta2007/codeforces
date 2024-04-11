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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
long long dp[5001][2] = {};
int main() {
#define int long long
	int n;
	cin >> n;
	vector<long long> s;
	REP(i, n) {
		string a;
		cin >> a;
		if (a == "s") {
			s.push_back(0);
		}
		else s.push_back(1);
	}
	dp[0][1] = 1;
	for (int i = 0;i < n;++i) {
		long long mewmew = 0;
		for (int q = 4999;q >= 0;--q) {
			if (s[i] == 0) {
				long long aa = dp[q][1];
				dp[q][1] += dp[q][0] + mewmew;
				dp[q][0] = 0;
				mewmew += aa;
				dp[q][1] %= MAX_MOD;
			}
			else {
				dp[q + 1][0] += dp[q][0] + dp[q][1];
				dp[q][0] = 0;
				if (q != 0) {
					mewmew += dp[q][1];
					dp[q][0] = mewmew;
				}
				dp[q][1] = 0;
				dp[q + 1][0] %= MAX_MOD;
			}
		}
	}
	long long ans = 0;
	for (int q = 0;q <= 5000;++q) {
		ans += dp[q][1];
		ans %= MAX_MOD;
	}
	cout << ans << endl;
	return 0;
}
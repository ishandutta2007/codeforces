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
long long cnt[300000];
long long gyaku_cnt[300000];
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> gogo;
	REP(i, n) {
		int a;
		cin >> a;
		gogo.push_back(a);
	}
	cnt[gogo.size() - 1] = 1;
	for (int i = gogo.size() - 2; i >= 0; --i) {
		cnt[i] = cnt[i + 1] + 1;
		if (gogo[i] >= gogo[i + 1]) {
			cnt[i] = 1;
		}
	}
	gyaku_cnt[0] = 1;
	for (int i = 1; i < gogo.size(); ++i) {
		gyaku_cnt[i] = gyaku_cnt[i - 1] + 1;
		if (gogo[i - 1] >= gogo[i]) {
			gyaku_cnt[i] = 1;
		}
	}
	long long ans = 0;
	REP(i, gogo.size()) {
		ans = max(ans, cnt[i]);
	}
	for (int i = 1; i < gogo.size() - 1; ++i) {
		if (gogo[i - 1] < gogo[i + 1]) {
			ans = max(ans, cnt[i + 1] + gyaku_cnt[i - 1]);
		}
	}
	cout << ans << endl;
}
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
long long go[2000000];
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> inputs;
	int ans = 0;
	REP(i, n) {
		int a;
		cin >> a;
		go[i] = a;
		ans += a;
	}
	if (ans == 1) {
		cout << -1 << endl;
		return 0;
	}
	inputs.insert(ans);
	for (long long i = 2; i <= sqrt(ans); ++i) {
		if (ans % i == 0) {
			inputs.insert(i);
			inputs.insert(ans / i);
		}
	}
	int final_ans = LONG_INF;
	for (auto i = inputs.begin(); i != inputs.end(); ++i) {
		int b = *i;
		long long now_cost = 0;
		long long back = 0;
		long long fronting = 0;
		REP(q, n) {
			long long now_think = go[q] % b;
			if (fronting > 0) {
				fronting -= now_think;
				now_think = 0;
				if (fronting < 0) {
					now_think = -fronting;
					fronting = 0;
				}
			}
			back += now_think;
			if (back > b / 2) {
				if (back >= b) {
					back -= b;
				}
				if(back > b/2){
					fronting = b - back;
					back = 0;
				}
			}
			now_cost += back;
			now_cost += fronting;
		}
		final_ans = min(final_ans, now_cost);
	}
	cout << final_ans << endl;
}
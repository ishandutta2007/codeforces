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
int cnt[3000000];
int summing[6000000];
int main() {
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		int n;
		cin >> n;
		REP(i, n) {
			cnt[i] = 0;
		}
		REP(i, n) {
			int a;
			cin >> a;
			a--;
			cnt[a]++;
		}
		REP(i, 2 * n + 1) {
			summing[i] = 0;
		}
		REP(i, n) {
			if (cnt[i] != 0) {
				summing[cnt[i]]++;
			}
		}
		REP(i, n*2+1) {
			summing[i + 1] += summing[i];
		}
		int ans = n;
		for (int i = 2; i <= n; ++i) {
			int go_ans = 0;
			for (int q = 1; (q - 1) * i <= n; ++q) {
				int next_back = i * q - min(i, q+1);
				int hoge = summing[i * q] - summing[next_back];
				go_ans += hoge * q;
				if (summing[next_back] - summing[i * (q - 1)] != 0) {
					go_ans = 1e9;
					break;
				}
			}
			ans = min(ans, go_ans);
		}
		cout << ans << endl;
	}
}
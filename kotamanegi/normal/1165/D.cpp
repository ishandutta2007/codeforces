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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
map<pair<long long, long long>, long long> memo;
long long power(long long a,long long now) {
	if (memo[make_pair(a, now)]) return memo[make_pair(a, now)];
	long long ans = 1;
	pair<int, int> base = make_pair(a, now);
	while (now != 0) {
		if (now % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		now /= 2;
		a *= a;
		a %= MOD;
	}
	return memo[base] = ans;
}
long long inv(long long a) {
	return power(a, MOD - 2);
}
long long permutation(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
	}
	return ans;
}
long long combination(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
		ans *= inv(i + 1);
		ans %= MOD;
	}
	return ans;
}
int main() {
#define int long long
	int test_case;
	cin >> test_case;
	REP(te, test_case) {
		int n;
		cin >> n;
		vector<int> input;
		map<long long, long long> gogo;
		REP(i, n) {
			int a;
			cin >> a;
			input.push_back(a);
			for (int i = 2; i <= sqrt(a); ++i) {
				if (a % i == 0) {
					int cnt = 0;
					while (a % i == 0) {
						cnt++;
						a /= i;
					}
					gogo[i] = max(gogo[i], cnt);
				}
			}
			if (a != 1) {
				gogo[a] = max(gogo[a], 1LL);
			}
		}
		sort(input.begin(), input.end());
		if (gogo.size() == 1) {
			input.push_back(input[0] * input[input.size() - 1]);
			int bad = 0;
			for (int q = 2; q <= sqrt(input[0]); ++q) {
				if (input[0] % q == 0) {
					bad = 1;
					break;
				}
			}
			if (bad == 1) {
				cout << -1 << endl;
				continue;
			}
			for (int q = 1; q < input.size(); ++q) {
				if (input[q] / input[q - 1] != input[0]) {
					bad = 1;
					break;
				}
			}
			if (bad == 1) cout << -1 << endl;
			else cout << input[input.size() - 1] << endl;
			continue;
		}
		long long ans = 1;
		int bad = 0;
		for (auto i = gogo.begin(); i != gogo.end(); ++i) {
			for (int q = 0; q < i->second; ++q) {
				if (1000000000000000000LL / i->first <= ans) {
					bad = 1;
					break;
				}
				ans *= i->first;
			}
			if (bad == 1) break;
		}
		if (bad == 1) {
			cout << -1 << endl;
			continue;
		}
		vector<int> geko;
		for (int q = 2; q <= sqrt(ans); ++q) {
			if (ans % q == 0) {
				if(ans / q != q)
				geko.push_back(ans / q);
				geko.push_back(q);
			}
		}
		sort(geko.begin(), geko.end());
		if (input == geko) {
			cout << ans << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
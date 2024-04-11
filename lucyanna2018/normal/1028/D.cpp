#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int

struct modular_arithmetic {
	int mod;

	modular_arithmetic() {
		mod = 1000000007;
	}
	//No specific settings.
	int add(int x, int y) { return (x += y)<mod ? x : x - mod; }
	int sub(int x, int y) { return (x -= y) >= 0 ? x : x + mod; }
	int mul(int x, int y) { return (int)((long long int)x*y%mod); }
	int pw(int base, int p) {
		int res = 1, mu = base % mod;
		for (;p>0;p /= 2) {
			if (p & 1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
	int rev(int x) { return pw(x, mod - 2); }
};
modular_arithmetic ma;

set<int> small, large, middle;
int main() {
	int q, res = 1;
	for (scanf("%d", &q); q--;) {
		char s[9];int x;
		scanf("%s%d", s, &x);
		if (s[1] == 'D') {
			if (!small.empty() && x < *small.rbegin())
				small.insert(x);
			else
				if (!large.empty() && x > *large.begin())
					large.insert(x);
				else
					middle.insert(x);
		}
		else {
			if (!small.empty() && x < *small.rbegin()) {
				puts("0");
				return 0;
			}
			if (!large.empty() && x > *large.begin()) {
				puts("0");
				return 0;
			}
			for (auto y : middle) {
				if (y < x)small.insert(y);else
					if (y > x)large.insert(y);else
						res = ma.mul(res, 2);
			}
			small.erase(x);
			large.erase(x);
			middle.clear();
		}
	}
	printf("%d\n", ma.mul(res, (int)middle.size() + 1));
	return 0;
}
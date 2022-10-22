#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

const int mod =	1000 * 1000 + 3;

int sum(int a, int b) {
	return (a + b) % mod;
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

int magic(int x) {
	return (x % mod + mod) % mod;
}

int binpow(int n, int p) {
	if(p == 0) return 1;
	int q = binpow(n, p / 2);
	q = mul(q, q);
	if(p % 2) q = mul(q, n);
	return q;
}

const int N = 1000100;

int fact[N], rev[mod];

int C(int n, int k) {
	return (n < k?0 : mul(fact[n], mul(rev[fact[n - k]], rev[fact[k]])));
}

bool solve() {
	
	fact[0] = 1;
	rev[0] = 0;

	for(int i = 1;i < N;i++) {
		fact[i] = mul(fact[i - 1], i);
		if(i == 1) rev[i] = 1;
		else if(i < mod) rev[i] = mul(magic(-rev[mod % i]), mod / i);
	}

	int n, c;

	cin >> n >> c;

	int res = 0;

	for(int i = 1;i <= n;i++) {
		res = sum(res, C(c + i - 1, i));
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}
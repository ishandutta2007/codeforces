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

const int mod = inf + 7;

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

int sum(int a, int b) {
	return (a + b) % mod;
}

int raz(int a, int b) {
	return ((a - b) % mod + mod) % mod;
}

int binpow(int n, ll p) {
	if(p == 0) return 1;
	int q = binpow(n, p / 2);
	q = mul(q, q);
	if(p % 2) q = mul(q, n);
	return q;
}

int del(int a, int b) {
	return mul(a, binpow(b, mod - 2));
}

typedef vec< vec< int > > matrix;

matrix mul(const matrix & a, const matrix & b) {
	int n, m, k;
	n = (int)a.size();
	m = (int)a[0].size();
	k = (int)b[0].size();
	matrix res(n, vec< int >(k));
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < k;j++) {
			for(int t = 0;t < m;t++) {
				res[i][j] = sum(res[i][j], mul(a[i][t], b[t][j]));
			}
		}
	}
	return res;
}

matrix binpow(const matrix & n, ll p) {
	if(p == 0) {
		int sz = (int)n.size();
		matrix res(sz, vec< int >(sz));
		for(int i = 0;i < sz;i++) res[i][i] = 1;
		return res;
	}else {
		matrix q = binpow(n, p / 2);
		q = mul(q, q);
		if(p % 2) q = mul(q, n);
		return q;
	}
}

bool solve() {

	int k;

	cin >> k;

	vec< ll > a(k);

	for(int i = 0;i < k;i++) scanf("%I64d", &a[i]);

	ll val = 1;
	int ok = 1;

	for(int i = 0;i < k;i++) {
		if(val * a[i] > 2) {
			ok = 0;
			break;
		}else {
			val *= a[i];
		}
	}

	if(ok) {
		if(val == 1) cout << "0/1\n";
		else if(val == 2) cout << "1/2\n";
		return true;
	}

	// dp

	int num, denum;

	// 2 ^ (n - 1)

	int pw = 1, ch = 1;

	for(int i = 0;i < k;i++) {
		pw = (1ll * pw * (a[i] % (mod - 1))) % (mod - 1);
		if(a[i] % 2 == 0) ch = 0;
	}

	pw = ((pw - 1) % (mod - 1) + mod - 1) % (mod - 1);
	denum = binpow(2, pw);

	if(ch) {
		num = del(raz(binpow(2, pw), 1), 3);
	}else {
		num = del(sum(binpow(2, pw), 1), 3);
	}

	cout << num << '/' << denum << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}
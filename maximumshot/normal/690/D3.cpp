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

int binpow(int n, int p) {
	if(p == 0) return 1;
	int q = binpow(n, p / 2);
	q = mul(q, q);
	if(p % 2) q = mul(q, n);
	return q;
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

matrix binpow(const matrix & a, int p) {
	if(p == 0) {
		int sz = (int)a.size();
		matrix res(sz, vec< int >(sz));
		for(int i = 0;i < sz;i++) res[i][i] = 1;
		return res;
	}else {
		matrix q = binpow(a, p / 2);
		q = mul(q, q);
		if(p % 2) q = mul(q, a);
		return q;
	}
}

bool solve() {
	
	int c, w, h;

	cin >> c >> w >> h;

	matrix st(w + 1, vec< int >(1)); 
	
	st[0][0] = 1;
	st[1][0] = h;

	matrix sq(w + 1, vec< int >(w + 1));

	for(int i = 0;i <= w;i++) sq[0][i] = 1;

	for(int cnt = 1;cnt <= w;cnt++) {
		sq[cnt][cnt - 1] = h;
	}

	st = mul(binpow(sq, c - 1), st);

	int res = 0;

	for(int cnt = 0;cnt <= w;cnt++) res = sum(res, st[cnt][0]);

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}
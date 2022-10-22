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

int bit_count(ll val) {
	int res = 0;
	for(int bit = 0;(1ll << bit) <= val;bit++) {
		if((1ll << bit) & val) res++;
	}
	return res;
}

bool solve() {

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll k;

	cin >> n >> k;

	vec< ll > a(n);
	for(int i = 0;i < n;i++) cin >> a[i];

	//sort(ALL(a));
	//a.resize(unique(ALL(a)) - a.begin());

	n = (int)a.size();

	matrix res(n, vec< int >(1));

	for(int i = 0;i < n;i++) {
		res[i][0] = 1;
	}

	matrix sq(n, vec< int >(n));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(bit_count(a[i] ^ a[j]) % 3 == 0) sq[i][j] = 1;
		}
	}

	res = mul(binpow(sq, k - 1), res);

	int answer = 0;

	for(int i = 0;i < n;i++) answer = sum(answer, res[i][0]);

	cout << answer << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}
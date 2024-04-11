#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

ll gcd(ll x, ll y) {
	return (x == 0?y : gcd(y % x, x));
}

void mormalize(ll & n, ll & m) {
	if(m < 0) n = -n, m = -m;
	ll g = gcd(n >= 0?n : -n, m >= 0?m : -m);
	n /= g;
	m /= g;
}

struct Q { // rational
	ll n, m;

	// n / m

	Q() {
		n = m = 0;
	}

	Q(ll nn, ll mm = 1) {
		n = nn;
		m = mm;
		mormalize(n, m);
	}

	Q & operator = (const Q & b) {
		n = b.n;
		m = b.m;
		return *this;
	}

	bool operator < (const Q & b) const {
		return (n * b.m < b.n * m);
	}

	bool operator > (const Q & b) const {
		return (n * b.m > b.n * m);
	}

	bool operator == (const Q & b) const {
		return (n * b.m == b.n * m);
	}

	bool operator <= (const Q & b) const {
		return (n * b.m <= b.n * m);
	}

	bool operator >= (const Q & b) const {
		return (n * b.m >= b.n * m);
	}
};

vec< pair< int, ll > > line; 
int cur = 0;
// {k, b}

Q intersect(int i) {
	return Q(line[i + 1].second - line[i].second, line[i].first - line[i + 1].first);
}

ll val(int i, ll x) {
	return line[i].first * x + line[i].second;
}

Q intersect(const pair< int, ll > & l1, const pair< int, ll > & l2) {
	return Q(l2.second - l1.second, l1.first - l2.first);
}

ll get_y(ll x) {
	if(cur == 1) return 1ll * line[0].first * x + line[0].second;
	Q X(x);
	if(X <= intersect(0)) return val(0, x);
	if(X >= intersect(cur - 2)) return val(cur - 1, x);
	int bl, br, bm;
	bl = 1;
	br = cur - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(X >= intersect(bm - 1)) bl = bm;
		else br = bm - 1;
	}
	ll res = -inf64;
	for(int j = max(0, bl - 3);j <= min(cur - 1, br + 3);j++) {
		res = max(res, val(j, x));
	}
	return res;
}

void add_line(int k, ll b) { // y = k * x + b
	if(cur == 0) {
		line[cur++] = mp(k, b);
		return;
	}
	pair< int, ll > add = mp(k, b);
	while(cur > 1 && intersect(cur - 2) >= intersect(add, line[cur - 1])) cur--;
	line[cur++] = add;
}

bool solve() {
	
	int n;
	scanf("%d", &n);

	vec< int > a(n + 1);

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

	vec< ll > sum(n + 1);
	for(int i = 1;i <= n;i++) {
		sum[i] = sum[i - 1] + a[i];
	}

	ll start_value = 0;
	for(int i = 1;i <= n;i++) {
		start_value += 1ll * a[i] * i;
	}

	ll ans = 0;

	line.resize(2 * n + 1);

	for(int i = 1;i <= n;i++) {
		if(i > 1) ans = max(ans, get_y(a[i]) + sum[i - 1] - 1ll * a[i] * i);
		add_line(i, -sum[i - 1]);
	}

	cur = 0;

	for(int i = n;i >= 1;i--) {
		if(i < n) ans = max(ans, get_y(-a[i]) - (1ll * a[i] * i - sum[i]));
		add_line(-i, -sum[i]);
	}

	cout << start_value + ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}
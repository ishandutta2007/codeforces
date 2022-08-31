#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


ll m;

ll gcd(ll a, ll b) {
	while (b) {
		ll q = b;
		b = a % b;
		a = q;
	}
	return a;
}

int go(ll a, ll b, ll x1, ll x2) {
	for (int i = 1; i <= m + 2; ++i) {
		a = (x1 * a + x2) % m;
		if (a == b)
			return i;
	}
	return -1;
}



int main() {
ll h1, a1, x1, x2, y1, y2, h2, a2;
	cin >> m;
	cin >> h1 >> a1;
	cin >> x1 >> y1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
	ll go1 = go(h1, a1, x1, y1);
	ll go2 = go(h2, a2, x2, y2);
	ll cc1 = go(a1, a1, x1, y1);
	ll cc2 = go(a2, a2, x2, y2);
	if (go1 == -1 || go2 == -1) {
		cout << -1;
		return 0;
	}
	if (go1 == go2) {
		cout << go1 << "\n";
		return 0;
	}
	if (cc2 == -1) {
		swap(cc1, cc2);
		swap(go1, go2);
	}
	if (cc1 == -1) {
		if (cc2 == -1) {
			cout << -1;
			return 0;
		}
		if (go2 > go1) {
			cout << -1;
			return 0;
		}
		go1 -= go2;
		if (go1 % cc2 == 0)
			cout << go1 + go2;
		else
			cout << -1;
		return 0;
	}


	if (go1 % gcd(cc1, cc2) != go2 % gcd(cc1, cc2)) {
		cout << -1;
		return 0;
	}


	if (go1 < go2)
		swap(go1, go2), swap(cc1, cc2);
	
	ll st = go1;

	ll rr = go1 % cc2;
	go2 %= cc2;
	ll cc1r = cc1 % cc2;

	while (rr != go2) {
		st += cc1;
		rr += cc1r;
		if (rr >= cc2)
			rr -= cc2;
	}


	cout << st;
	return 0;
}
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


ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

int main() {
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	ll ans = p * (n / a) + q * (n / b) - min(p, q) * (n / (a * b /  gcd(a, b)));
	cout << ans << "\n";
	return 0;
}
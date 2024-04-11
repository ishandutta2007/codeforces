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

int n, k;
int c[1200000];

ll gcd(ll a, ll b) {
	while (b) {
		ll q = b;
		b = a % b;
		a = q;
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	ll now = 1;
	for (int i = 0; i < n; ++i) {
		c[i] = gcd(c[i], k);
		now = lcm(now, c[i]);
	}
	if (now != k)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll j = 1, ac = 9, tot = 0;
	while (1) {
		if (j * ac >= n) break;
		n -= j * ac;
		tot += ac;
		j++; ac *= 10;
	}
	n--;
	ll val = tot + n / j + 1;
	n %= j;
	for (int i = 0; i < j - 1 - n; i++) {
		val /= 10;
	}
	cout << val % 10 << '\n';
}
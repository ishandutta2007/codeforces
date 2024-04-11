#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

LL n;

int main() {
	cin >> n;
	LL f = n;
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			f = __gcd(f, i);
			f = __gcd(f, n / i);
		}
	}
	cout << f << endl;
}
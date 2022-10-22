#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(a, b % a);
}

int a, b, c, d;
int num, denom;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int gcdab = gcd(a, b);
	a /= gcdab;
	b /= gcdab;
	int gcdcd = gcd(c, d);
	c /= gcdcd;
	d /= gcdcd;
	if ( (double) a / c > (double) b / d) {
		swap(a, b); swap(c, d);
	}
	num = a * d;
	denom = b * c;
	num = denom - num;
	int gcdans = gcd(num, denom);
	num /= gcdans;
	denom /= gcdans;
	printf("%d/%d\n", num, denom);
	return 0;
}
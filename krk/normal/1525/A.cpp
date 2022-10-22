#include <bits/stdc++.h>
using namespace std;

int T;
int k;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &k);
		int g = gcd(k, 100);
		printf("%d\n", 100 / g);
	}
    return 0;
}
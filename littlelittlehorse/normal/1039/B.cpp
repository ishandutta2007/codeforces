#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
int m;
string res;

int main() {
	srand(time(0));
	scanf("%lld%d", &n, &m);
	long long L = 1, R = n;
	for (;;) {
		bool ok = false;
		long long M = (L + R) >> 1;
		if (R - L < 50) {
			long long x = rand() % (R - L + 1) + L;
			printf("%lld %lld\n", x, x);
			ok = true;
		} else
			printf("%lld %lld\n", L, M); 
		fflush(stdout);
		cin >> res;
		if (ok)
			if (res == "Yes")
				return 0;
		else {
			L = max(1LL, L - m);
			R = min(n, R + m);
		} 
		else
		if (res == "Yes") {
			L = max(1LL, L - m);
			R = min(n, M + m);
		} else {
			L = max(1LL, M - m);
			R = min(n, R + m);
		}
	}
}
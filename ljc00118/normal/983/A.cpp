#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	while(b) {
		ll tmp = b;
		b = a % b, a = tmp;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		b /= gcd(a, b);
		ll tmp = gcd(b, c);
		while(tmp != 1) {
			b /= tmp;
			tmp = gcd(b, tmp);
		}
		if(b == 1) printf("Finite\n");
		else printf("Infinite\n");

	}
	return 0;
}
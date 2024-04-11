#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;
int s;

int Sum(ll x)
{
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d %d", &n, &s);
		if (Sum(n) <= s) { printf("0\n"); continue; }
		ll cur = 10;
		bool don = false;
		for (int i = 0; i < 18 && !don; i++) {
			ll nw = cur - n % cur;
			if (Sum(n + nw) <= s) { printf("%I64d\n", nw); don = true; }
			cur *= 10;
		}
	}
    return 0;
}
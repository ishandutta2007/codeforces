#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll p, a, b, c;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d %I64d %I64d %I64d", &p, &a, &b, &c);
		ll tima = (p - 1) / a * a + a;
		ll timb = (p - 1) / b * b + b;
		ll timc = (p - 1) / c * c + c;
		cout << min(min(tima, timb), timc) - p << endl;
	}
    return 0;
}
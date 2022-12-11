// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll a, b, x, y, ans1, ans2, tmp1;

ll Min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}

int main() {
//	freopen("B.in", "r", stdin);
//	freopen("B.out", "w", stdout);
	
	a = read(), b = read(), x = read(), y = read();
	tmp1 = __gcd(x, y);
	x /= tmp1, y /= tmp1;
	ans1 = a / x;
	ans2 = b / y;
	printf("%I64d\n", Min(ans1, ans2));

	return 0;
}
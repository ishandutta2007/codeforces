#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll n,x,y;
void work() {
    scanf("%lld%lld%lld", &n, &x, &y);
    ll flag = (x & 1);
    for (ll i = 1; i <= n; ++i) {
        ll a;
        scanf("%lld", &a);
        flag ^= (a & 1);
    }
    if (flag == (y & 1)) printf("Alice\n");
    else printf("Bob\n");
}

int main() {
    ll t;
    scanf("%lld", &t);
    while (t--) work();
	return 0;
}
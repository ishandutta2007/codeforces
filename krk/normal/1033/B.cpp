#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool Prime(const ll x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int t; scanf("%d", &t);
    while (t--) {
        ll a, b; scanf("%I64d %I64d", &a, &b);
        if (a - 1 == b && Prime(a + b))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
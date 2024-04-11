#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set <ll> S;

ll Ask(ll a, ll b)
{
    printf("? %I64d %I64d\n", a, b); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}

int main()
{
    ll n = 3;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++) {
            ll a = Ask(i, j), b = Ask(j, i);
            if (a != b) {
                printf("! %I64d\n", a + b); fflush(stdout);
                return 0;
            }
            n = max(n, 2 + a);
        }
    printf("! %I64d\n", n); fflush(stdout);
    return 0;
}
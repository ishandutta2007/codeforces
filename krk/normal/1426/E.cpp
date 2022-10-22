#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll a1, a2, a3;
ll b1, b2, b3;

int main()
{
    scanf("%I64d", &n);
    scanf("%I64d %I64d %I64d", &a1, &a2, &a3);
    scanf("%I64d %I64d %I64d", &b1, &b2, &b3);
    ll res = 0;
    res = max(res, a1 + b2 - n);
    res = max(res, a2 + b3 - n);
    res = max(res, a3 + b1 - n);
    printf("%I64d ", res);
    res = 0;
    res += min(a1, b2);
    res += min(a2, b3);
    res += min(a3, b1);
    printf("%I64d\n", res);
    return 0;
}
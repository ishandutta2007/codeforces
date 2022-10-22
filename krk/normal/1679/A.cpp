#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

ll getMax(ll n)
{
    ll res = n / 4;
    return res;
}

ll getMin(ll n)
{
    ll res = n / 6;
    n %= 6;
    if (n) res++;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        if (n < 4 || n % 2) printf("-1\n");
        else printf("%I64d %I64d\n", getMin(n), getMax(n));
    }
    return 0;
}
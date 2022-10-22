#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int a, b, k;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &k);
        ll x = ll(a) * ((k + 1) / 2) - ll(b) * (k / 2);
        printf("%I64d\n", x);
    }
    return 0;
}
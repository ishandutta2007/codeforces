#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &x);
        ll i = 1;
        while ((1ll << ll(i - 1)) * ((1ll << ll(i)) - 1ll) <= x) {
            x -= (1ll << ll(i - 1)) * ((1ll << ll(i)) - 1ll);
            i++;
        }
        i--;
        printf("%I64d\n", i);
    }
    return 0;
}
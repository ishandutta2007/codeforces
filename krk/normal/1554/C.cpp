#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &n, &m);
        ll res = 0;
        int to = 32ll;
        while (n <= m) {
            for (int i = 1; i <= to; i++)
                if ((n >> ll(i) << ll(i)) + (1ll << ll(i)) - 1ll > m) {
                    res |= 1ll << ll(i - 1);
                    n ^= 1ll << ll(i - 1);
                    to = i - 1;
                    break;
                }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int o = n - m;
        int a = o / (m + 1);
        int mor = o % (m + 1);
        int les = m + 1 - mor;
        ll all = ll(a) * (a + 1) / 2 * les + ll(a + 1) * (a + 2) / 2 * mor;
        ll res = ll(n) * (n + 1) / 2 - all;
        printf("%I64d\n", res);
    }
    return 0;
}
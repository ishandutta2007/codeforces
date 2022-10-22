#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int x, y, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &x, &y, &k);
        ll nd = ll(k) * y + ll(k);
        ll res = (nd - 2) / (x - 1) + 1;
        res += k;
        printf("%I64d\n", res);
    }
    return 0;
}
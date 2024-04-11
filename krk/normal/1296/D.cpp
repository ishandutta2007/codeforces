#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, a, b, k;
int h[Maxn];
int res;

int main()
{
    scanf("%d %d %d %d", &n, &a, &b, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        h[i] %= (a + b);
        if (h[i] == 0) h[i] = a + b;
    }
    sort(h, h + n);
    for (int i = 0; i < n; i++) {
        int hits = (h[i] - 1) / a + 1;
        if (hits - 1 <= k) { res++; k -= (hits - 1); }
    }
    printf("%d\n", res);
    return 0;
}
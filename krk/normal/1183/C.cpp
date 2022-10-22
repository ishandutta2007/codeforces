#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;

int main()
{
    scanf("%d", &q);
    while (q--) {
        int k, n, a, b; scanf("%d %d %d %d", &k, &n, &a, &b);
        k--;
        if (ll(n) * b > k) printf("-1\n");
        else {
            int res = min((k - n * b) / (a - b), n);
            printf("%d\n", res);
        }
    }
    return 0;
}
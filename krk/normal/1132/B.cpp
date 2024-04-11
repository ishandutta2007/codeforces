#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int a[Maxn];
ll sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    int q; scanf("%d", &q);
    while (q--) {
        int b; scanf("%d", &b);
        printf("%I64d\n", sum - ll(a[n - b]));
    }
    return 0;
}
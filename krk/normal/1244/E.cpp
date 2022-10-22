#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll k;
int a[Maxn];
ll L[Maxn], R[Maxn];
int res = 2000000007;

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (a[l] != a[r])
        if (l + 1 <= n - r) {
            ll tk = min(k / (l + 1), ll(a[l + 1] - a[l]));
            if (a[l] + tk < a[l + 1]) { printf("%I64d\n", ll(a[r] - a[l] - tk)); return 0; }
            k -= tk * (l + 1);
            l++;
        } else {
            ll tk = min(k / (n - r), ll(a[r] - a[r - 1]));
            if (a[r] - tk > a[r - 1]) { printf("%I64d\n", ll(a[r] - a[l] - tk)); return 0; }
            k -= tk * (n - r);
            r--;
        }
    printf("0\n");
    return 0;
}
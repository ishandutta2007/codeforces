#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn], b[Maxn];
int A[Maxn], B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(A + 1, A + n + 1, 0);
        fill(B + 1, B + n + 1, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i], &b[i]);
            A[a[i]]++;
            B[b[i]]++;
        }
        ll res = ll(n) * (n - 1) * (n - 2) / 6ll;
        for (int i = 0; i < n; i++)
            res -= ll(A[a[i]] - 1) * ll(B[b[i]] - 1);
        printf("%I64d\n", res);
    }
    return 0;
}
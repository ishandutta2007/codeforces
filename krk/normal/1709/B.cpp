#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn];
ll A[Maxn], B[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        A[i] = A[i - 1];
        B[i] = B[i - 1];
        if (i > 1)
            if (a[i - 1] > a[i]) A[i] += a[i - 1] - a[i];
            else B[i] += a[i] - a[i - 1];
    }
    while (m--) {
        int s, t; scanf("%d %d", &s, &t);
        ll res = s < t? A[t] - A[s]: B[s] - B[t];
        printf("%I64d\n", res);
    }
    return 0;
}
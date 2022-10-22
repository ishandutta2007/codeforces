#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int n;
int a[Maxn];
ll L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (n == 1) { printf("%d\n", a[1]); return 0; }
    for (int i = 1; i <= n; i++)
        L[i] = L[i - 1] + ll(abs(a[i]));
    for (int i = n; i > 0; i--)
        R[i] = R[i + 1] + ll(abs(a[i]));
    ll res = 0;
    for (int i = 1; i + 1 <= n; i++)
        res = max(res, ll(max(a[i] - a[i + 1], a[i + 1] - a[i])) + L[i - 1] + R[i + 2]);
    cout << res << endl;
    return 0;
}
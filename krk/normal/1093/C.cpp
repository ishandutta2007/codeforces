#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll b[Maxn];
ll a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n / 2; i++) {
        scanf("%I64d", &b[i]);
        if (i == 0) a[0] = 0, a[n - 1] = b[i];
        else {
            ll mna = max(a[i - 1], b[i] - a[n - i]);
            a[i] = mna; a[n - 1 - i] = b[i] - a[i];
        }
    }
    for (int i = 0; i < n; i++)
        printf("%I64d%c", a[i], i + 1 < n? ' ': '\n');
    return 0;
}
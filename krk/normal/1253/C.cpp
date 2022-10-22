#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
ll add[Maxn];
int a[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        add[i % m] += a[i];
        res += add[i % m];
        printf("%I64d%c", res, i + 1 < n? ' ': '\n');
    }
    return 0;
}
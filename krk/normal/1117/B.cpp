#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m, k;
int a[Maxn];
ll res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int tims = m / (k + 1);
    res += ll(tims) * (ll(k) * a[n - 1] + ll(a[n - 2]));
    m %= (k + 1);
    res += ll(m) * a[n - 1];
    cout << res << endl;
    return 0;
}
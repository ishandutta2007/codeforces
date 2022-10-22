#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];
int t[Maxn];
ll sum[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        sum[i] = sum[i - 1];
        if (t[i] == 0) sum[i] += a[i];
        else res += a[i];
    }
    ll mx = 0;
    for (int i = 1; i + k <= n + 1; i++)
        mx = max(mx, sum[i + k - 1] - sum[i - 1]);
    res += mx;
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n;
int a[Maxn];
ll res = 9000000000000000000ll;

ll Solve(int from, int to, int delt)
{
    ll cur = 0, res = 0;
    for (int i = from; min(from, to) <= i && i <= max(from, to); i += delt) {
        ll tims = cur / a[i] + 1;
        res += tims;
        cur = tims * a[i];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        ll cand = 0;
        if (i > 1) cand += Solve(i - 1, 1, -1);
        if (i < n) cand += Solve(i + 1, n, 1);
        res = min(res, cand);
    }
    cout << res << endl;
    return 0;
}
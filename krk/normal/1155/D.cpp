#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 300005;

int n, x;
int a[Maxn];
ll S[Maxn];
ll L[Maxn], R[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &x);
    ll mn = 0;
    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        S[i] = S[i - 1] + ll(a[i]);
        res = max(res, S[i] - mn);
        if (S[i] < mn) mn = S[i];
        L[i] = min(L[i - 1], ll(x - 1) * S[i] + ll(mn));
    }
    ll mx = S[n];
    R[n] = ll(x) * S[n];
    for (int i = n - 1; i > 0; i--) {
        if (S[i] > mx) mx = S[i];
        R[i] = max(R[i + 1], ll(x - 1) * S[i] + ll(mx));
    }
    for (int i = 0; i < n; i++)
        res = max(res, R[i + 1] - L[i]);
    cout << res << endl;
    return 0;
}
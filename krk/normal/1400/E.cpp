#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n;
int a[Maxn];

ll Solve(int l, int r, int nd)
{
    if (l > r) return 0;
    ll res = r - l + 1;
    int mn = a[l];
    for (int i = l + 1; i <= r; i++)
        mn = min(mn, a[i]);
    ll cand = mn - nd;
    int lst = l - 1;
    for (int i = l; i <= r; i++)
        if (a[i] == mn) {
            cand += Solve(lst + 1, i - 1, mn);
            lst = i;
        }
    cand += Solve(lst + 1, r, mn);
    res = min(res, cand);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout << Solve(0, n - 1, 0) << endl;
    return 0;
}
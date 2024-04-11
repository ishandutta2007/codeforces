#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, a[N], k;

bool check(int q) {
    if (a[1] > q) {
        int sz = 1;
        int cur = 0;
        for (int i = 2; i <= n; i++)
            if (cur == 0) {
                if (a[i] <= q)
                    cur = 1, sz++;
            } else
                cur = 0, sz++;
        return (k > 1 && sz >= k);
    }
    ///a1 a[1] == q
    int sz = 1;
    int cur = 1;
    for (int i = 2; i <= n; i++)
        if (cur == 0) {
            if (a[i] <= q)
                cur = 1, sz++;
        } else
            cur = 0, sz++;
    if (sz >= k)
        return 1;
    sz = 1;
    cur = 0;
    for (int i = 2; i <= n; i++)
        if (cur == 0) {
            if (a[i] <= q)
                cur = 1, sz++;
        } else
            cur = 0, sz++;
    return (sz >= k);

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = 1e9;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}
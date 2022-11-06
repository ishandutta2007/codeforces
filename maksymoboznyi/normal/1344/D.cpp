#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define all(q) (q).begin(), (q).end()
using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N], k;

bool check(int m, int x) {
    return 3 * m * m + 3 * m + 1 <= x;
}

int f(int i, int x) {
    if (x < 1)
        return 0;
    int l = 0, r = 1e9 + 500000;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m, x))
            l = m;
        else
            r = m;
    }
    return min(l, a[i] - 1) + 1;
}

int kol(int x) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int val = a[i] - x;
        res += f(i, val);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = -4e18, r = 4e18;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (kol(m) >= k)
            l = m;
        else
            r = m;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        b[i] = f(i, a[i] - r), sum += b[i];
    vector<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
        if (b[i] < a[i])
            q.pb({a[i] - 3 * b[i] * b[i] - 3 * b[i] - 1, i});
    sort(q.rbegin(), q.rend());
    for (int i = 0; i < k - sum; i++)
        b[q[i].second]++;
/*
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += b[i] * (a[i] - b[i] * b[i]);
*/

    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], le[N], ri[N];
long long k, ans = 0, cur = 0;
vector<int> ve;

void update(int bit[], int u, int v)
{
    for (; u <= n; u += u & -u)
        bit[u] += v;
}

int query(int bit[], int u)
{
    int ret = 0;
    for (; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

int get(int u)
{
    return distance(ve.begin(), upper_bound(ve.begin(), ve.end(), u));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (int i = 1; i <= n; i++)
    {
        cur += query(ri, n) - query(ri, get(a[i]));
        update(ri, get(a[i]), 1);
    }
    for (int i = 1, pt = 1; i < n; i++)
    {
        cur -= query(ri, get(a[i]) - 1);
        cur -= query(le, n) - query(le, get(a[i]));
        update(ri, get(a[i]), -1);
        while (pt <= i && cur <= k)
        {
            cur += query(ri, get(a[pt]) - 1);
            cur += query(le, n) - query(le, get(a[pt]));
            update(le, get(a[pt++]), 1);
        }
        ans += max(0, pt - 2 + (cur <= k));
    }
    cout << ans << '\n';
}
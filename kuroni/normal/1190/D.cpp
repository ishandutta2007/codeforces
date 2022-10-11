#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, bit[N], cnt[N];
long long ans = 0;
pair<int, int> a[N];
vector<int> ve;

void upd(int u, int v)
{
    for (; u <= n; u += u & -u)
        bit[u] += v;
}

int que(int u)
{
    int ret = 0;
    for (; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].se >> a[i].fi;
        ve.push_back(a[i].se);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (int i = 1; i <= n; i++)
    {
        a[i].se = distance(ve.begin(), upper_bound(ve.begin(), ve.end(), a[i].se));
        cnt[a[i].se]++;
    }
    for (int i = 1; i <= ve.size(); i++)
        upd(i, 1);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = a[i].se, pre = (a[i].fi == a[i - 1].fi ? a[i - 1].se : 0);
        ans += 1LL * (que(n) - que(cur - 1)) * (que(cur) - que(pre));
        if (--cnt[cur] == 0)
            upd(cur, -1);
    }
    cout << ans;
}
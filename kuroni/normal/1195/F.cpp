#include <bits/stdc++.h>
using namespace std;

const int N = 100005, Q = 100005, MX = 300005;

int n, k, u, v, q, cur = 0, r[N], x[MX], y[MX], bit[MX];
int val[MX], lst[MX], prv[MX], ind[MX], ans[Q];

struct SVector
{
    int x, y, ind;

    SVector(int _x = 0, int _y = 0, int _ind = 0)
    {
        x = _x; y = _y; ind = _ind;
    }

    bool upper() const
    {
        return y > 0 || (y == 0 && x > y);
    }

    bool operator<(const SVector &oth) const
    {
        if (upper() != oth.upper())
            return upper();
        else
            return 1LL * x * oth.y - 1LL * y * oth.x < 0;
    }
};
vector<SVector> ve;

struct SQuery
{
    int l, r, ind;

    SQuery(int _l = 0, int _r = 0, int _ind = 0)
    {
        l = _l; r = _r; ind = _ind;
    }
};
vector<SQuery> que;

void update(int u)
{
    for (; u <= n; u += u & -u)
        bit[u]++;
}

int query(int u)
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
        cin >> k;
        for (int j = 0; j < k; j++)
            cin >> x[j] >> y[j];
        for (int j = 0; j < k; j++)
            ve.push_back(SVector(x[j] - x[(j + 1) % k], y[j] - y[(j + 1) % k], ++cur));
        r[i] = cur;
    }
    sort(ve.begin(), ve.end());
    n = cur;
    val[ve[0].ind] = cur = 1;
    for (int i = 1; i < ve.size(); i++)
        val[ve[i].ind] = (cur += (ve[i - 1] < ve[i]));
    for (int i = 1; i <= n; i++)
    {
        prv[i] = lst[val[i]];
        lst[val[i]] = i;
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, [](const int &u, const int &v) {
        return prv[u] < prv[v];
    });
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        que.push_back(SQuery(r[u - 1] + 1, r[v], i));
    }
    sort(que.begin(), que.end(), [](const SQuery &u, const SQuery &v) {
        return u.l < v.l;
    });
    int pt = 1;
    for (SQuery &u : que)
    {
        for (; pt <= n && prv[ind[pt]] < u.l; pt++)
            update(ind[pt]);
        ans[u.ind] = query(u.r) - query(u.l - 1);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}
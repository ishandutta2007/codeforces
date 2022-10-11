#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int m, n, u, dep = 0, tr[N];
long long cur = 0;
bool vis[2 * N];
pair<long long, int> f[4 * N];
pair<long long, int> ans = {1E18, 0};
map<int, pair<long long, int>> ma;

struct SPoint
{
    int typ, pos, ind;

    SPoint(int _typ, int _pos, int _ind) : typ(_typ), pos(_pos), ind(_ind) {}
};
vector<SPoint> ve, st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        ve.push_back(SPoint(1, u, i));
        ve.push_back(SPoint(1, u + m, i));
        cur += 2LL * u + m;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        ve.push_back(SPoint(-1, u, i));
        ve.push_back(SPoint(-1, u + m, i));
        cur -= 2LL * u + m;
    }
    sort(ve.begin(), ve.end(), [](const SPoint &u, const SPoint &v) {
        return make_tuple(u.pos, u.typ, u.ind) < make_tuple(v.pos, v.typ, v.ind);
    });
    for (int i = 4 * n - 1; i >= 0; i--)
    {
        SPoint &v = ve[i];
        cur -= v.pos * v.typ;
        dep -= v.typ;
        if (ma.count(dep) > 0)
            f[i] = {abs(ma[dep].fi - cur), ma[dep].se};
        ma[dep + v.typ] = {cur + v.pos * v.typ, i + 1};
    }
    for (int i = 0; i < 2 * n; i++)
        if (!vis[i])
        {
            long long tmp = 0;
            for (int u = i; u < 2 * n; u = f[u].se)
            {
                vis[u] = true;
                tmp += f[u].fi;
            }
            ans = min(ans, {tmp, i});
        }
    for (int i = 0; i < 2 * n; i++)
    {
        SPoint &v = ve[i + ans.se];
        if (st.empty() || st.back().typ == v.typ)
            st.push_back(v);
        else
        {
            if (v.typ == 1)
                tr[v.ind] = st.back().ind;
            else
                tr[st.back().ind] = v.ind;
            st.pop_back();
        }
    }
    cout << ans.fi << '\n';
    for (int i = 1; i <= n; i++)
        cout << tr[i] << " ";
}
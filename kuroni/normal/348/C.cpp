#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int N = 100005, M = 100005, MX = 100005, D = 505;

int n, m, q, k, u, sz = 0, ind[M], coe[D][M], tmp[N];
long long a[N], sum[M], add[M], tot[M];
char c;
vector<int> big, ve[M];

void init(int u, int pos)
{
    for (int &v : ve[u])
    {
        sum[u] += a[v];
        tmp[v]++;
    }
    for (int i = 1; i <= m; i++)
        for (int &v : ve[i])
            coe[pos][i] += tmp[v];
    for (int &v : ve[u])
        tmp[v]--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        sz += k;
        while (k--)
        {
            cin >> u;
            ve[i].push_back(u);
        }
    }
    int d = sqrt(sz);
    for (int i = 1; i <= m; i++)
        if (ve[i].size() >= d)
        {
            big.push_back(i);
            ind[i] = big.size();
        }
    for (int &v : big)
        init(v, ind[v]);
    while (q--)
    {
        cin >> c >> u;
        if (c == '?')
        {
            if (ind[u] == 0)
            {
                long long ans = 0;
                for (int &v : ve[u])
                    ans += a[v];
                for (int &v : big)
                    ans += add[v] * coe[ind[v]][u];
                cout << ans << '\n';
            }
            else
                cout << sum[u] + tot[u] << '\n';
        }
        else
        {
            cin >> k;
            if (ind[u] == 0)
            {
                for (int &v : ve[u])
                    a[v] += k;
            }
            else
                add[u] += k;
            for (int &v : big)
                tot[v] += 1LL * k * coe[ind[v]][u];
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;

int n, m, a[N];
long long ans = 0, ret = INF, dis[N];
vector<int> ve[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i < m; i++)
        if (a[i] != a[i + 1])
        {
            int cur = abs(a[i] - a[i + 1]);
            ans += cur;
            dis[a[i]] += cur; ve[a[i]].push_back(a[i + 1]);
            dis[a[i + 1]] += cur; ve[a[i + 1]].push_back(a[i]);
        }
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end());
        long long tmp = ans - dis[i];
        int sz = ve[i].size();
        for (int j = 0; j < sz / 2; j++)
            tmp += ve[i][sz - 1 - j] - ve[i][j];
        ret = min(ret, tmp);
    }
    cout << ret;
}
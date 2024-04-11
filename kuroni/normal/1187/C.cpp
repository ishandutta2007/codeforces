#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, t, l, r, cur = 0, a[N];
vector<int> inc, que[2][N];
bool chk[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t >> l >> r;
        que[t][l].push_back(i);
        que[t][r + 1].push_back(-i);
    }
    a[0] = N;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int &v : que[0][i])
            if (v < 0 && !chk[-v])
                return cout << "NO\n", 0;
        for (int &v : que[1][i])
            if (v < 0)
                cur--;
        if (cur == 0)
        {
            a[i] = a[i - 1] - 1;
            for (int &v : inc)
                chk[v] = true;
            inc.clear();
        }
        else
            a[i] = a[i - 1];
        for (int &v : que[0][i])
            if (v > 0)
                inc.push_back(v);
        for (int &v : que[1][i])
            if (v > 0)
                cur++;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
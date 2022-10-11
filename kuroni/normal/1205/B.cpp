#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LG = 61, MX = 125;

int n, ans = MX + 1, dst[N];
long long a[N];
vector<int> ve[LG];

int BFS(int st, int en, int bl)
{
    queue<int> q;
    fill(dst, dst + n, MX);
    dst[st] = 0;
    for (q.push(st); !q.empty(); q.pop())
    {
        int u = q.front();
        for (int i = 0; i < LG; i++)
            if ((a[u] >> i & 1) && i != bl && ve[i].size() == 2)
            {
                int v = ve[i][0] ^ ve[i][1] ^ u;
                if (u == st && v == en)
                    continue;
                if (dst[v] == MX)
                {
                    dst[v] = dst[u] + 1;
                    q.push(v);
                }
            }
    }
    return dst[en] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < LG; j++)
            if (a[i] >> j & 1)
            {
                ve[j].push_back(i);
                if (ve[j].size() == 3)
                    return cout << 3, 0;
            }
    }
    for (int i = 0; i < LG; i++)
        if (ve[i].size() == 2)
            ans = min(ans, BFS(ve[i][0], ve[i][1], i));
    cout << (ans > MX ? -1 : ans);
}
#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, p[502][502] = {{0}}, r = 0;
        queue<pair<int, int>> l;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if (c == '*')
                {
                    l.push({i, j});
                    p[i][j] = 1;
                    r++;
                }
            }
        while (!l.empty())
        {
            int x = l.front().first, y = l.front().second;
            l.pop();
            if (p[x - 1][y] >= p[x][y] && p[x][y + 1] >= p[x][y] && p[x][y - 1] >= p[x][y]){
                p[x][y]++;
                r++;
                l.push({x, y});
            }
        }
        cout << r << '\n';
    }
}
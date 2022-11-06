#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e3 + 3;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};


int n, m, ans = 0;
char a[N][N], is[N][N][4], can[N][N], used[N][N];

bool check(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= m && a[x][y] == '#' && !used[x][y]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        bool was = 0;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#')
                was = 1;
            else
                is[i][j][0] = was;
        was = 0;
        for (int j = m; j > 0; j--)
            if (a[i][j] == '#')
                was = 1;
            else
                is[i][j][1] = was;
    }
    for (int j = 1; j <= m; j++) {
        bool was = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][j] == '#')
                was = 1;
            else
                is[i][j][2] = was;
        was = 0;
        for (int i = n; i > 0; i--)
            if (a[i][j] == '#')
                was = 1;
            else
                is[i][j][3] = was;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((is[i][j][1] && is[i][j][0]) || (is[i][j][2] && is[i][j][3])) {
                cout << "-1\n";
                return 0;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            can[i][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (is[i][j][0]) {
                for (int j1 = j; j1 <= m; j1++)
                    can[i][j1] = 0;
                break;
            }
        for (int j = m; j > 0; j--)
            if (is[i][j][1]) {
                for (int j1 = j; j1 > 0; j1--)
                    can[i][j1] = 0;
                break;
            }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            if (is[i][j][2]) {
                for (int i1 = i; i1 <= n; i1++)
                    can[i1][j] = 0;
                break;
            }
        for (int i = n; i > 0; i--)
            if (is[i][j][3]) {
                for (int i1 = i; i1 > 0; i1--)
                    can[i1][j] = 0;
                break;
            }
    }
    for (int i = 1; i <= n; i++) {
        bool is = 0;
        for (int j = 1; j <= m; j++)
            if (can[i][j])
                is = 1;
        if (!is) {
            cout << "-1";
            return 0;
        }
    }
    for (int j = 1; j <= m; j++) {
        bool is = 0;
        for (int i = 1; i <= n; i++)
            if (can[i][j])
                is = 1;
        if (!is) {
            cout << "-1\n";
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#' && !used[i][j]) {
                queue<pair<int, int> > q;
                q.push({i, j});
                used[i][j] = 1;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++)
                        if (check(x + dx[d], y + dy[d]))
                            used[x + dx[d]][y + dy[d]] = 1, q.push({x + dx[d], y + dy[d]});
                }
                ans++;
            }
    cout << ans;
    return 0;
}
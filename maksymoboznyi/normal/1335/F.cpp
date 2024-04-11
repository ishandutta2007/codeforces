#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;

const int N = 2e6 + 5;
const int M = 201;
const int INF = 1e18;

int n, m, px, py, fx, fy;
vector<vector<char> > a, c, on;
int kol[N];
vector<vector<int> > used;

void dfs(int x, int y) {
    used[x][y] = 1;
    int ax = x, ay = y;
    if (a[x][y] == 'R')
        ay++;
    if (a[x][y] == 'L')
        ay--;
    if (a[x][y] == 'U')
        ax--;
    if (a[x][y] == 'D')
        ax++;
    if (used[ax][ay]) {
        px = x;
        py = y;
        fx = ax;
        fy = ay;
        return;
    }
    dfs(ax, ay);
}

void go(int x, int y, int d, int len) {
    used[x][y] = 1;
    if (!on[x][y] && c[x][y] == '0')
        kol[d % len]++;
    if (a[x - 1][y] == 'D' && !on[x - 1][y])
        go(x - 1, y, d + 1, len);

    if (a[x + 1][y] == 'U' && !on[x + 1][y])
        go(x + 1, y, d + 1, len);

    if (a[x][y - 1] == 'R' && !on[x][y - 1])
        go(x, y - 1, d + 1, len);

    if (a[x][y + 1] == 'L' && !on[x][y + 1])
        go(x, y + 1, d + 1, len);

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear();
        c.clear();
        on.clear();
        used.clear();
        a.resize(n + 2, vector<char>(m + 2));
        c.resize(n + 2, vector<char>(m + 2));
        used.resize(n + 2, vector<int>(m + 2));
        on.resize(n + 2, vector<char>(m + 2));

        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                used[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!used[i][j]) {
                    px = -1, py = -1, fx = -1, fy = -1;
                    dfs(i, j);
                    vector<pair<int, int> > q;

                    while (fx != px || fy != py) {
                        q.pb({fx, fy});
                        on[fx][fy] = 1;
                        if (a[fx][fy] == 'R')
                            fy++;
                        else if (a[fx][fy] == 'L')
                            fy--;
                        else if (a[fx][fy] == 'U')
                            fx--;
                        else
                            fx++;
                    }
                    on[px][py] = 1;
                    q.pb({px, py});
                    for (int i = 0; i < q.size(); i++)
                        kol[i] = 0;
                    reverse(q.begin(), q.end());
                    for (int i = 0; i < q.size(); i++)
                        go(q[i].x, q[i].y, i, q.size());
                    ans1 += q.size();
                    for (int i = 0; i < q.size(); i++)
                        if (c[q[i].x][q[i].y] == '0')
                            ans2++;
                        else
                            if (kol[i] != 0)
                                ans2++, kol[i]--;
                }
        cout << ans1 << ' ' << ans2 << "\n";
    }
    return 0;
}
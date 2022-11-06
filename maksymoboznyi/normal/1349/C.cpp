#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std;

const int N = 1e3 + 3;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, t;
int start[N][N];
char a[N][N];

bool check(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j] -= '0', start[i][j] = -1;
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int d = 0; d < 4; d++)
                if (check(i + dx[d], j + dy[d]) && a[i][j] == a[i + dx[d]][j + dy[d]]) {
                    q.push({i, j});
                    start[i][j] = 1;
                    break;
                }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int d = 0; d < 4; d++)
            if (check(x + dx[d], y + dy[d]) && a[x + dx[d]][y + dy[d]] == (a[x][y] ^ 1) && start[x + dx[d]][y + dy[d]] == -1) {
                q.push({x + dx[d], y + dy[d]});
                start[x + dx[d]][y + dy[d]] = start[x][y] + 1;
            }
    }
    while (t--) {
        long long x, y, p;
        cin >> x >> y >> p;
        if (start[x][y] == -1 || p < 1ll * start[x][y]) {
            cout << int(a[x][y]) << "\n";
            continue;
        }
        if ((p - 1ll * start[x][y]) % 2) {
            cout << int(a[x][y]) << "\n";
        } else {
            cout << int(a[x][y] ^ 1) << "\n";
        }

    }
    return 0;
}
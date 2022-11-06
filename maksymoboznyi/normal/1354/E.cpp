#include <bits/stdc++.h>
#define pb push_back
#define all(q) (q).begin(), (q).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 5005;

struct cell {
    vector<int> c1;
    vector<int> c2;
};

int n, m, used[N];
vector<int> g[N], c1, c2;
vector<cell> c;

void dfs(int v, int kol = 1) {
    used[v] = kol;
    if (kol == 1)
        c1.pb(v);
    else
        c2.pb(v);
    for (auto u: g[v])
        if (used[u] == 0)
            dfs(u, (kol == 1 ? 2 : 1));
        else
            if (used[u] == used[v]) {
                cout << "NO";
                exit(0);
            }

}

int dp[2][N], n1, n2, n3, q1, q2, col[N];
bool take[N][N];

void go(int i, int kol) {
    if (i != 0) {
        if (take[i][kol] == 0)
            go(i - 1, kol - c[i].c1.size());
        else
            go(i - 1, kol - c[i].c2.size());
    }
    if (take[i][kol] == 1)
        swap(c[i].c1, c[i].c2);
    for (auto u: c[i].c1)
        col[u] = 1;
    for (auto u: c[i].c2)
        col[u] = 2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i]) {
            c1.clear();
            c2.clear();
            dfs(i);
            c.pb({c1, c2});
        }
    q2 = 1;
    q1 = 0;
    dp[q1][c[0].c1.size()] = 1;
    take[q1][c[0].c1.size()] = 0;
    dp[q1][c[0].c2.size()] = 1;
    take[q1][c[0].c2.size()] = 1;

    for (int i = 1; i < c.size(); i++) {
        for (int kol = 0; kol <= n; kol++) {
            dp[q2][kol] = 0;
            if (kol >= c[i].c1.size() && dp[q1][kol - c[i].c1.size()])
                dp[q2][kol] = 1, take[i][kol] = 0;
            if (kol >= c[i].c2.size() && dp[q1][kol - c[i].c2.size()])
                dp[q2][kol] = 1, take[i][kol] = 1;

        }
        swap(q1, q2);
    }
    if (!dp[q1][n1 + n3]) {
        cout << "NO";
        return 0;
    }
    go(c.size() - 1, n1 + n3);
    int x = n3;
    if (x != 0)
    for (int i = 1; i <= n; i++)
        if (col[i] == 1) {
            col[i] = 3;
            x--;
            if (x == 0)
                break;
        }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << col[i];
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;

const int N = 2e3 + 5;
const long long inf = 2e18;

int n, k;
string a[N];
int g[N][N];
bool used[N][N];
bool check(int x, int y) {
return x > 0 && y > 0 &&  x <= n && y <= n;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    getline(cin, a[0]);
    for (int i = 1; i <= n; i++)
            getline(cin, a[i]), a[i] = '#' + a[i];
    if (a[1][1] == 'a')
        g[1][1] = 0;
    else
        g[1][1] = 1;
    for (int i = 0; i <= n; i++)
        g[0][i] = g[i][0] = 100000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i + j != 2) {
                g[i][j] = min(g[i - 1][j], g[i][j - 1]);
                if (a[i][j] != 'a')
                    g[i][j] ++;
            }
    if (g[n][n] <= k) {
        for (int i = 0; i < 2*n - 1; i++)
            cout << 'a';
        return 0;
    }
    int dist = 0;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] <= k)
                dist = max(dist, i - 1 + j - 1);
    string ans = "";
    vector<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] <= k && dist == (i - 1 + j - 1))
            {
                q.pb({i, j});
                a[i][j] = 'a';
                //cout << i << ' '<<j << endl;
            }
    if (q.size() == 0)
        q.pb({1, 1});
    while (1) {
        char minv = 'z';
        for (int i = 0; i < q.size(); i++)
            minv = min(minv, a[q[i].x][q[i].y]);
        ans += minv;
        //cout << ans << endl;
        vector<pair<int, int> > p;
        for (int i = 0; i < q.size(); i++)
            if (a[q[i].x][q[i].y] == minv)
                p.pb(q[i]);
        q.clear();
        for (int i = 0; i < p.size(); i++) {
            if (check(p[i].x, p[i].y + 1) && !used[p[i].x][p[i].y + 1])
                q.pb({p[i].x, p[i].y + 1}), used[p[i].x][p[i].y + 1] = 1;
            if (check(p[i].x + 1, p[i].y) && !used[p[i].x + 1][p[i].y])
                q.pb({p[i].x + 1, p[i].y}), used[p[i].x + 1][p[i].y] = 1;
        }
        if (q.size() == 0)
            break;
    }
    for (int i = 0; i < dist; i++)
        cout << 'a';
    cout << ans;
    return 0;
}
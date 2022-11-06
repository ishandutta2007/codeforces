#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 76;

struct cell {
    int a, b, id;
};

bool operator < (cell & a, cell & b) {
    return a.b < b.b;
}

int n, k, dp[N][N], from[N][N];
cell a[N];
vector<int> v;
int take[N];

void go(int i, int j) {
    if (i != 1)
        go(i - 1, j - from[i][j]);
    if (from[i][j])
        v.pb(i);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int o;
    cin >> o;
    while (o--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i].a >> a[i].b, a[i].id = i;
        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= i; j++) {
                dp[i][j] = 0;
                if (i != j)
                    dp[i][j] = dp[i - 1][j] + a[i].b * (k - 1);
                from[i][j] = 0;
                if (j != 0 && dp[i - 1][j - 1] + (j - 1) * a[i].b + a[i].a > dp[i][j])
                    dp[i][j] = dp[i - 1][j - 1] + (j - 1) * a[i].b + a[i].a, from[i][j] = 1;
            }

        v.clear();
        go(n, k);
        for (int i = 1; i <= n; i++)
            take[i] = 0;
        for (auto x: v)
            take[x] = 1;
        cout << n + (n - k) << "\n";
        for (int i = 1; i <= n; i++)
            if (take[i] && i != v.back())
                cout << a[i].id << ' ';
        for (int i = 1; i <= n; i++)
            if (!take[i])
                cout << a[i].id << ' ' << -a[i].id << ' ';
        cout << a[v.back()].id << "\n";
    }
    return 0;
}
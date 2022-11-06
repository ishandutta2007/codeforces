#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 6001;

struct cell {
    int l, r;
};

int n;
vector<int> ls[N];
cell a[N];
int dp[N][N];

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        v.pb(a[i].l);
        v.pb(a[i].r);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < v.size(); i++)
        ls[i].clear();
    for (int i = 0; i < v.size(); i++)
        for (int j = i; j < v.size(); j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        a[i].l = lower_bound(all(v), a[i].l) - v.begin();
        a[i].r = lower_bound(all(v), a[i].r) - v.begin();
        ls[a[i].r].pb(a[i].l);
        dp[a[i].l][a[i].r] = 1;
    }
    for (int len = 2; len <= v.size(); len++)
        for (int l = 0; l + len - 1 < v.size(); l++) {
            int r = l + len - 1;
            int x = dp[l][r];
            dp[l][r] = 0;
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            for (auto l1 : ls[r])
                if (l1 >= l)
                    dp[l][r] = max(dp[l][r], dp[l][l1 - 1] + dp[l1][r]);
            dp[l][r] += x;
        }
    cout << dp[0][v.size() - 1] << "\n";
    }
    return 0;
}
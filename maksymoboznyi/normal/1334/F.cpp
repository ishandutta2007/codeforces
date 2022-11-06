#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
const int N = 5e5 + 5;

int n, m, a[N], b[N], p[N], pref[N], pref_p[N], pref_d[N], dp[N], id[N], cur[N];
vector<int> pos[N], val[N];

int t[N];

void add(int r, int val) {
    for (; r <= n; r = r | (r + 1))
        t[r] += val;
}

int get(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i], id[b[i]] = i;



    for (int i = 1; i <= n; i++)
        if (id[a[i]] != 0)
            pos[id[a[i]]].pb(i), val[id[a[i]]].pb(inf);

    for (int i = 1; i <= m; i++)
        if (pos[i].size() == 0) {
            cout << "NO\n";
            return 0;
        }
    for (int i = 1; i <= n; i++) {
        if (id[a[i]] != 0)
            pref_p[i] = get(n) - get(b[id[a[i]] - 1]);
        if (p[i] > 0)
            add(a[i], p[i]);

        if (id[a[i]] != 0)
            pref[i] = get(n) - get(a[i]);
        pref_d[i] = pref_d[i - 1];
        if (p[i] < 0)
            pref_d[i] -= p[i];
    }



    val[1][0] = 0;

    for (int i = 1; i <= m; i++) {
        int mn = inf;
        for (int j = 0; j < pos[i].size(); j++) {
            mn = min(mn, val[i][j]);
            if (mn != inf)
                dp[pos[i][j]] = mn + pref_p[pos[i][j]] - pref_d[pos[i][j] - 1];
            else
                dp[pos[i][j]] = inf;
        }
        if (i != m)
            for (auto p: pos[i])
                if (dp[p] != inf) {
                    while (cur[i + 1] != pos[i + 1].size() && pos[i + 1][cur[i + 1]] < p)
                        cur[i + 1]++;
                    if (cur[i + 1] == pos[i + 1].size())
                        break;
                    val[i + 1][cur[i + 1]] = min(val[i + 1][cur[i + 1]], dp[p] - pref[p] + pref_d[p]);
                }
    }
    int ans = inf;
    int sum = 0;
    //cout << dp[3] << endl;
    for (int i = n; i > 0; i--) {
        if (a[i] == b[m] && dp[i] != inf)
            ans = min(ans, dp[i] + sum);
        if (p[i] < 0 || a[i] > b[m])
            sum += p[i];
    }
    if (ans == inf)
        cout << "NO\n";
    else
        cout << "YES\n" << ans;
    return 0;
}
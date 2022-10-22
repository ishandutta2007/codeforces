#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> poses(n + 1);
    for (int i = 1; i <= n; i++)
        poses[i].push_back(0);
    for (int i = 1; i <= n; i++)
        poses[a[i]].push_back(i);
    for (int i = 1; i <= n; i++)
        poses[a[i]].push_back(n + 1);

    int x = 1;
    for (int y = 1; y <= n; y++) {
        if (poses[x].size() < poses[y].size())
            x = y;
    }

    int sq = sqrt(n) + 3, res = 0;

    for (int y = 1; y <= n; y++) {
        if (x == y || (int) poses[y].size() < sq)
            continue;
        vector<int> mn(2 * n + 1, inf), mx(2 * n + 1, -inf);
        int fx = 0, fy = 0;
        for (int i = 0; i <= n; i++) {
            if (i > 0 && a[i] == x)
                fx++;
            if (i > 0 && a[i] == y)
                fy++;
            int cur = fx - fy + n;
            mn[cur] = min(mn[cur], i);
            mx[cur] = max(mx[cur], i);
        }
        for (int d = 0; d <= 2 * n; d++)
            res = max(res, mx[d] - mn[d]);
    }

    vector<int> F(n + 2);
    for (int i = 1; i <= n; i++)
        F[i] = F[i - 1] + (a[i] == x);

    int mx = 0;
    for (int y = 1; y <= n; y++) {
        int sy = (int) poses[y].size();
        if (x == y || sy >= sq) {
            continue;
        }
        mx = max(mx, sy);
        for (int i = 0; i < sy; i++) {
            for (int j = 0; j < i; j++) {
                int cur = i - j - 1;
                int l = poses[y][j];
                int r = poses[y][i];
                int hlp = F[r] - F[l];
                if (hlp > 0 && hlp == cur) {
                    res = max(res, r - l - 1);
                }
            }
        }
    }

    vector<int> fr(n + 1), cn(n + 1);

    auto upd = [&](int& val, int delta) {
        cn[val]--;
        val += delta;
        cn[val]++;
    };

    for (int freq = 1; freq <= mx; freq++) {
        fr.assign(n + 1, 0);
        cn.assign(n + 1, 0);
        for (int l = 1, r = 1; r <= n; r++) {
            upd(fr[a[r]], +1);
            while (cn[freq + 1] > 0) {
                upd(fr[a[l]], -1);
                l++;
            }
            if (fr[x] == freq && cn[freq] >= 2)
                res = max(res, r - l + 1);
        }
    }

    cout << res << "\n";

    return 0;
}
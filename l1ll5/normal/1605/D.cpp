#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;
vector<int> v[N];
int col[N], bel[N];
void dfs(int x, int fa, int c) {
    //cout << "C" << x << ' ' << c << endl;
    col[x] = c;
    for (auto to : v[x]) {
        if (to == fa) continue;
        dfs(to, x, c ^ 1);
    }
}
void work() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n == 2) {
        int x, y;
        cin >> x >> y;
        cout << "2 1\n";
        return;
    }
    for (int i = 0; i <= n; i += 1) v[i].clear(), col[i] = 0, bel[i] = 1;
    for (int i = 1; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, 0);
    int cnt0 = 0;
    for (int i = 1; i <= n; i += 1) {
        if (col[i] == 0) cnt0++;
    }
    if (n - cnt0 > cnt0) {
        for (int i = 1; i <= n; i += 1) {
            col[i] ^= 1;
        }
        cnt0 = n - cnt0;
    }

    int cur = 1;
    int h = 0;
    while (cur <= n) {
        cur <<= 1;
        h++;
    }
    for (int now = (cur >> 1); now <= n; now += 1) {
        cnt0--;
        //cout << "bl" << now << endl;
        bel[now] = 0;
    }
    int bl = 0;
    for (int i = 0; i < 20; i += 1) {
        if ((cnt0 >> i) & 1) {
            for (int j = (1 << i); j < (1 << (i + 1)); j += 1) {
                if (j <= n) {
                    //cout << "bl" << j << endl;
                    bel[j] = 0, bl++;
                }
            }
        }
    }
    assert(bl == cnt0);
    vector<int> ans(n + 1);
    vector<int> col0, col1;
    for (int i = 1; i <= n; i += 1) {
        if (col[i] == 0) col0.push_back(i);
        if (col[i] == 1) col1.push_back(i);
    }
    for (int i = 1; i <= n; i += 1) {
        if (bel[i] == 0) {
            assert(col0.size() > 0);
            ans[col0.back()] = i;
            col0.pop_back();
        }
        else {
            assert(col1.size() > 0);
            ans[col1.back()] = i;
            col1.pop_back();
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (auto to : v[i]) {
            //cout << i << ' ' << to << endl;
            //cout << ans[to] << ' ' << ans[i] << endl;
            assert((ans[to] ^ ans[i]) > min(ans[to], ans[i]));
        }
    }

    for (int i = 1; i <= n; i += 1) cout << ans[i] << ' ';
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        work();
    }
}
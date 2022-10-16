#include <bits/stdc++.h>

using namespace std;

int n, k, bad;
int a[5][55];
int s[105], t[105];
vector <pair <int, pair <int, int> > > ans;

pair <int, int> get_s(int x) {
    if (x <= n) return make_pair(2, x);
    return make_pair(3, n + 1 - x + n);
}
pair <int, int> get_t(int x) {
    if (x <= n) return make_pair(1, x);
    return make_pair(4, n + 1 - x + n);
}
void go(int x) {
    pair <int, int> f = get_s(s[x]);
    a[f.first][f.second] = 0;
    ++s[x];
    if (s[x] > 2 * n) s[x] = 1;
    pair <int, int> g = get_s(s[x]);
    a[g.first][g.second] = x;
    ans.push_back(make_pair(x, g));
}
void fin(int x) {
    --bad;
    pair <int, int> f = get_s(s[x]);
    a[f.first][f.second] = 0;
    s[x] = -1;
    pair <int, int> g = get_t(t[x]);
    a[g.first][g.second] = x;
    ans.push_back(make_pair(x, g));
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 4; ++i) for (int j = 1; j <= n; ++j) {
        int x; cin >> x; a[i][j] = x;
        if (x == 0) continue;
        if (i == 1) t[x] = j;
        if (i == 2) s[x] = j;
        if (i == 3) s[x] = n + 1 - j + n;
        if (i == 4) t[x] = n + 1 - j + n;
    }
    bad = k;
    if (k == 2 * n) {
        int flag = 0;
        for (int i = 1; i <= k; ++i) if (s[i] == t[i]) {
            flag = 1;
        }
        if (!flag) return cout << -1 << endl, 0;
    }
    while (bad) {
        for (int i = 1; i <= k; ++i) if (s[i] == t[i]) fin(i);
        for (int i = 1; i <= k; ++i) if (s[i] != -1) {
            pair <int, int> g = get_s(s[i] % (2 * n) + 1);
            if (a[g.first][g.second] == 0) {
                go(i);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    return 0;
}
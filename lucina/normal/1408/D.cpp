#include<bits/stdc++.h>
using namespace std;
int const nax = 2e6 + 10;
int n, m;
int a[nax];
int b[nax];
int c[nax];
int d[nax];
int low[nax + nax];
int bar[nax + nax];
int nxt[nax + nax];
const int C = 1e6;
int keep[nax];
vector <pair <int, int>> changes[nax];
///bar


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i] >> b[i];
    }
    memset(low, -1, sizeof(low));
    memset(bar, -1, sizeof(bar));

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> c[i] >> d[i];
        low[c[i]] = max(low[c[i]], d[i]);
        bar[d[i]] = max(bar[d[i]], c[i]);
    }

    for (int j = C ; j >= 0 ; -- j) {
        low[j] = max(low[j], low[j + 1]);
        bar[j] = max(bar[j], bar[j + 1]);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            if (c[j] >= a[i]) {
                changes[(c[j] - a[i] + 1)].emplace_back(i, c[j] + 1);
            //    cout << a[i] - c[j] + 1 << ' ' << i << ' ' << c[j] + 1 << '\n';
            }
        }
    }
    int ans = 1e9;

    multiset <int> ms;

    for (int i = 1 ; i <= n ; ++ i) {
        ms.insert(max(0, low[a[i]] - b[i] + 1));
    }
    ans = min(ans, *ms.rbegin());

    for (int i = 1 ; i <= C ; ++ i) {
        if (changes[i].empty()) continue;
        for (auto [u, v] : changes[i]) {
            int old = max(0, low[a[u]] - b[u] + 1);
            ms.erase(ms.find(old));
            a[u] = v;
            int nw = max(low[a[u]] - b[u] + 1, 0);
            ms.insert(nw);
        }
        ans = min(ans, *ms.rbegin() + i);
    }


    cout << ans << '\n';
}
/*
    Good Luck
        -Lucina
*/
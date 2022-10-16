#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int ans[20005];
int tot, found;
set<pair <int, int> > q;

int cv(char a, char b) { return 10 * (a - '0') + (b - '0'); }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int l = 3600 * cv(s[0], s[1]) + 60 * cv(s[3], s[4]) + cv(s[6], s[7]);
        int r = l + t - 1;
        while (!q.empty() && q.begin()->first < l) q.erase(q.begin());
        if (q.size() < m) ans[i] = ++tot;
        else {
            int id = (--q.end())->second; q.erase(--q.end());
            ans[i] = id;
        }
        q.insert(make_pair(r, ans[i]));
        if (q.size() == m) found = 1;
    }
    if (!found) return cout << "No solution\n", 0;
    cout << tot << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}
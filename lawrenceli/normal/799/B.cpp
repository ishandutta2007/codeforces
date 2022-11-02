#include <bits/stdc++.h>

using namespace std;

const int maxn = 200100;
const int inf = (1e9) + 5;

int n, m;
int p[maxn], a[maxn], b[maxn];
set<int> st[3][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) st[a[i] - 1][b[i] - 1].insert(p[i]);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int c; cin >> c; c--;
        int best = inf;
        for (int j = 0; j < 3; j++) {
            if (!st[c][j].empty()) best = min(best, *st[c][j].begin());
            if (!st[j][c].empty()) best = min(best, *st[j][c].begin());
        }

        if (best == inf) cout << "-1 ";
        else {
            cout << best << ' ';
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (st[j][k].count(best)) st[j][k].erase(best);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '.';
        }

    vector<int> count_ver(m);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            count_ver[j] += a[i - 1][j] == 0 && a[i][j - 1] == 0;

    vector<int> pref(m + 1);
    for (int j = 0; j < m; j++)
        pref[j + 1] = pref[j] + count_ver[j];

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (pref[r] - pref[l + 1] != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
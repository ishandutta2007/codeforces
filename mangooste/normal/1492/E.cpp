#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &xs : a)
        for (auto &x : xs)
            cin >> x;

    vector<int> bad_rows[5];
    vector<vector<int>> where(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[0][j] != a[i][j])
                where[i].push_back(j);
        if (int(where[i].size()) >= 5) {
            cout << "No\n";
            return 0;
        }
        bad_rows[where[i].size()].push_back(i);
    }

    if (bad_rows[4].empty() && bad_rows[3].empty()) {
        cout << "Yes\n";
        for (auto x : a[0])
            cout << x << ' ';
        cout << '\n';
        return 0;
    }

    auto check = [&](map<int, int> changes) {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            int cnt = int(where[i].size());
            for (auto j : where[i])
                if (changes.find(j) != changes.end() && changes[j] == a[i][j])
                    cnt--;
            for (auto [j, val] : changes)
                if (find(where[i].begin(), where[i].end(), j) == where[i].end())
                    cnt++;
            ok &= (cnt <= 2);
        }
        if (ok) {
            auto ans = a[0];
            for (auto [j, val] : changes)
                ans[j] = val;
            cout << "Yes\n";
            for (auto x : ans)
                cout << x << ' ';
            cout << '\n';
            exit(0);
        }
    };

    if (!bad_rows[4].empty()) {
        int r = bad_rows[4][0];
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                check({{where[r][i], a[r][where[r][i]]}, {where[r][j], a[r][where[r][j]]}});
        cout << "No\n";
        return 0;
    }

    int r = bad_rows[3][0];
    for (int i = 0; i < 3; i++) {
        check({{where[r][i], a[r][where[r][i]]}});
        for (int j = 0; j < 3; j++)
            if (i != j)
                for (int k = 0; k < n; k++) {
                    int diff = 0;
                    for (int j = 0; j < m; j++) {
                        int cur = (j == where[r][i] ? a[r][where[r][i]] : a[0][j]);
                        diff += (cur != a[k][j]);
                    }
                    if (diff > 2) {
                        check({{where[r][i], a[r][where[r][i]]}, {where[r][j], a[k][where[r][j]]}});
                        break;
                    }
                }
    }
    cout << "No\n";
}
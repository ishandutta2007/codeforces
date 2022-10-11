#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, x--;

    vector<vector<int>> poses(n);
    for (int i = 0; i < n; i++)
        poses[a[i]].push_back(i);
    for (int i = 0; i < n; i++)
        poses[i].push_back(n);

    auto get_next = [&](int val, int i) {
        if (val == -1)
            return n;
        int id = int(lower_bound(poses[val].begin(), poses[val].end(), i) - poses[val].begin());
        return poses[val][id];
    };

    int cur[2]{-1, -1}, ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && a[i] == a[i + 1]) {
            for (int j = 0; j < 2; j++)
                ans += (cur[j] != a[i]), cur[j] = a[i];
            continue;
        }
        if (i && a[i] == a[i - 1])
            continue;

        bool any = false;
        for (int j = 0; j < 2; j++)
            if (cur[j] != a[i] && cur[j ^ 1] == a[i])
                any = true, ans++, cur[j] = a[i];
        if (any)
            continue;

        int mn = get_next(cur[0], i) > get_next(cur[1], i);
        ans += (cur[mn] != a[i]), cur[mn] = a[i];
    }
    cout << ans << '\n';
}
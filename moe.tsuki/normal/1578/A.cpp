#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x[3], y[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    int x_[3], y_[3];
    for (int i = 0; i < 3; ++i) {
        x_[i] = x[i];
        y_[i] = y[i];
    }
    sort(x_, x_ + 3);
    sort(y_, y_ + 3);
    int mx = x_[1], my = y_[1];
    vector<pair<pair<int,int>, pair<int,int>>> ans;
    auto ins = [&](int ox, int oy) {
        if (ox == mx and oy == my) return;
        if (ox == mx or oy == my) ans.emplace_back(pair{ox, oy}, pair{mx, my});
        else {
            ans.emplace_back(pair{ox, oy}, pair{ox, my});
            ans.emplace_back(pair{ox, my}, pair{mx, my});
        }
    };
    ins(x[0], y[0]);
    ins(x[1], y[1]);
    ins(x[2], y[2]);
    cout << ans.size() << '\n';
    for (auto [a, b]: ans) {
        cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';
    }
    return 0;
}
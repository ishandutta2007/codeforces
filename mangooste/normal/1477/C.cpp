#include <bits/stdc++.h>

using namespace std;

inline int64_t sqr(int x) {
    return 1ll * x * x;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &[x, y] : points)
        cin >> x >> y;

    auto dist = [&](int i, int j) {
        return sqr(points[i].first - points[j].first) + sqr(points[i].second - points[j].second);
    };

    cout << 1;
    vector<bool> used(n);
    int previous = 0;
    for (int i = 1; i < n; i++) {
        used[previous] = true;
        int best = -1;
        for (int j = 1; j < n; j++)
            if (!used[j] && (best == -1 || dist(previous, best) < dist(previous, j)))
                best = j;
        cout << ' ' << (previous = best) + 1;
    }
    cout << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int l, r;
    cin >> l >> r;
    cout << "YES\n";
    if (l == r)
        return cout << "2 1\n1 2 " << l << '\n', 0;

    vector<array<int, 3>> edges;
    edges.push_back({0, 1, l});
    int cur = 1, last = 2;
    for (;; last++)
        if (2 * cur <= r - l + 1) {
            edges.push_back({0, last, l});
            int st = l + 1;
            for (int j = 1; j < last; j++) {
                edges.push_back({j, last, st - l});
                st += (1 << (j - 1));
            }
            cur *= 2;
        } else
            break;

    if (cur != r - l + 1) {
        int val = r - l, st = 1;
        edges.push_back({0, last, l});
        if ((r - l) % 2) {
            st = 2, val--;
            edges.push_back({1, last, 1});
        }
        for (int bit = 1; bit < last - 1; bit++)
            if ((val >> bit) % 2) {
                edges.push_back({bit + 1, last, st});
                st += (1 << bit);
            }
    } else
        last--;

    cout << last + 1 << ' ' << edges.size() << '\n';
    for (auto [a, b, c] : edges)
        cout << a + 1 << ' ' << b + 1 << ' ' << c << '\n';
}
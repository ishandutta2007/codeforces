#include <bits/stdc++.h>
using namespace std;

const int LG = 30;

int n, q, u, cnt[LG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n;
        fill(cnt, cnt + LG, 0);
        for (int i = 1; i <= n; i++) {
            cin >> u;
            cnt[__lg(u)]++;
        }
        for (int i = 0; i < 11; i++) {
            cnt[i + 1] += cnt[i] / 2;
        }
        cout << (cnt[11] ? "YES\n" : "NO\n");
    }
}
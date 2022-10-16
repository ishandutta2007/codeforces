#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    if (n % 2 == 1 && k % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    for (int d = 1; ; ++d) {
        if (d * k < n || (d * k - n) % 2 == 1) continue;
        int lim = (d - 1) / 2;
        if (2 * lim * n + n >= k * d) {
            vector<pair<int, int>> v(n);
            for (int i = 0; i < n; ++i) v[i] = {1, i + 1};
            int cur = 0, s = n;
            while (s < k * d) {
                v[cur].first += 2;
                if (v[cur].first + 2 > d) ++cur;
                s += 2;
            }
            int ans = 0;
            for (int i = 1; i <= d; ++i) {
                sort(v.begin(), v.end(), greater<pair<int, int>>());
                vector<int> f;
                for (int j = 0; j < k; ++j) {
                    f.push_back(v[j].second);
                    --v[j].first;
                }
                cout << "?";
                for (auto x: f) cout << ' ' << x;
                cout << endl;
                int y = 0;
                cin >> y;
                ans ^= y;
            }
            cout << "! " << ans << endl;

            return;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}
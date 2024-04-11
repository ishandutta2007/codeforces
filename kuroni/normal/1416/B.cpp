#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, t, sum, a[N];
vector<array<int, 3>> ans;
vector<pair<int, int>> ve;

bool operate(int i, int j, int x) {
    if (x == 0 || i == j) {
        return true;
    }
    a[i] -= i * x;
    a[j] += i * x;
    ans.push_back({i, j, x});
    return a[i] >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        ans.clear(); ve.clear(); sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            ve.push_back({(i - a[i] % i) % i, i});
        }
        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }
        sum /= n;
        sort(ve.begin(), ve.end());
        for (auto [u, v] : ve) {
            operate(1, v, u);
            operate(v, 1, a[v] / v);
        }
        for (int i = 2; i <= n; i++) {
            operate(1, i, sum);
        }
        cout << ans.size() << '\n';
        for (auto [i, j, x] : ans) {
            cout << i << " " << j << " " << x << '\n';
        }
    }
}
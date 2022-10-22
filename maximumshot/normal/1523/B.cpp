#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<tuple<int, int, int>> res;
        for (int i = 0; i < n / 2; i++) {
            int u = i + 1;
            int v = i + n / 2  + 1;
            res.emplace_back(1, u, v);
            res.emplace_back(2, u, v);
            res.emplace_back(1, u, v);
            res.emplace_back(2, u, v);
            res.emplace_back(1, u, v);
            res.emplace_back(2, u, v);
        }
        cout << (int) res.size() << "\n";
        for (auto [ty, i, j] : res) {
            cout << ty << " " << i << " " << j << "\n";
            if (ty == 1) a[i] += a[j];
            else a[j] -= a[i];
        }
//        for (int i = 1; i <= n; i++)
//            cout << a[i] << " ";
//        cout << "\n";
    }

    return 0;
}
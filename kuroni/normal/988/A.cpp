#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, u;
    map<int, int> ma;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        ma[u] = i;
    }
    if (ma.size() < k) {
        return cout << "NO\n", 0;
    } else {
        cout << "YES\n";
        int cnt = 0;
        for (pair<int, int> v : ma) {
            cout << v.second << " ";
            if (++cnt == k) {
                return 0;
            }
        }
    }
}
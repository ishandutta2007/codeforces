#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 5000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        int ok = 0;
        for (int i = 1; i <= n; i += 1) {
            int x;
            cin >> x;
            if (mp[x - k] == 1 or mp[x + k] == 1) {
                ok = 1;
            }
            mp[x] = 1;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
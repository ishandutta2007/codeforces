#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cnt(101);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int ans = 0;
        int ok = 1;
        for (int i = 0; i < 101; i++) {
            if (cnt[i] >= 2 && ok) {
                ans += 2;
            } else if (cnt[i]) {
                ok = 0;
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
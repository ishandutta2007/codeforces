#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 5000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    LL cur = 2;
    map<LL, int> mp;
    while (cur <= 2e18) {
        mp[cur] = 1;
        cur *= 2;
    }
    while (T--) {
        LL n;
        cin >> n;
        if (mp[n]) {
            cout << "-1\n";
        }
        else {
            int t = 1;
            while (n % 2 == 0) {
                n /= 2;
                t += 1;
            }
            cout << min((1LL << t), n) << '\n';
        }
    }
    return 0;
}
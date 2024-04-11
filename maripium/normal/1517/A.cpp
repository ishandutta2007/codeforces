#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int64_t N; cin >> N;
        if (N % 2050) {
            cout << "-1\n";
            continue;
        }
        N /= 2050;
        int ans = 0;
        while (N) {
            ans += N%10;
            N /= 10;
        }
        cout << ans << '\n';
    }
}
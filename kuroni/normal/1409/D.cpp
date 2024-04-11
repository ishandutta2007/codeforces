#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, s;
long long n;

int ds(long long u) {
    int ans = 0;
    while (u > 0) {
        ans += u % 10;
        u /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        long long ans = 0;
        for (long long cur = 1; ds(n) > s; cur *= 10, n /= 10) {
            int l = n % 10;
            if (l > 0) {
                ans += (10 - l) * cur;
                n += 10 - l;
            }
        }
        cout << ans << '\n';
    }
}
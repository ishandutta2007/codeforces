#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;
int n, q;
int64_t a[nax];
void solve() {
    cin >> n >> q;
    int64_t ans = 0;
    int cnt[2]{};
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        ans += a[i];
        cnt[a[i] % 2] += 1;
    }

    while (q --) {
        int t; int64_t x;
        cin >> t >> x;
        if (t == 0) {
            ans += cnt[0] * x;
            if (x % 2) cnt[1] += cnt[0], cnt[0] = 0;
        } else {
            ans += cnt[1] * x;
            if (x % 2) cnt[0] += cnt[1], cnt[1] = 0;
        }
        cout << ans << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
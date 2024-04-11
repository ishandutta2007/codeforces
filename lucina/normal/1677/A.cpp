#include<bits/stdc++.h>
using namespace std;
const int nax = 5012 + 10;
int n;
int p[nax];
int cnt[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> p[i];
    }

    int64_t ans = 0;

    for (int c = 1 ; c <= n ; ++ c) {
        fill(cnt, cnt + 1 + n, 0);
        for (int d = c + 1 ; d <= n ; ++ d)
            cnt[p[d]] += 1;
        for (int i = 1 ; i <= n ; ++ i) cnt[i] += cnt[i - 1];
        int64_t cnt_ls = 0;
        for (int b = 1 ; b < c ; ++ b) {
            ans += cnt_ls * cnt[p[b]];
            cnt_ls += p[b] < p[c];
        }
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Long time, div.1 round :)
*/
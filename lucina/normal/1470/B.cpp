#include<bits/stdc++.h>
using namespace std;
const int L = 1e6;
const int nax = 3e5 + 10;
int n, nq;
int c[L + 10];
int nc[L + 10];

void solve() {
    cin >> n;
    map <int, int> cnt;
    int ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        x = nc[x];
        ans = max(ans, ++cnt[x]);
    }
    int cnt1 = 0;
    for (auto &[x, y] : cnt) {
        if (y % 2 == 0 || x == 1) cnt1 += y;
    }

    int ans2 = max(ans, cnt1);
    cin >> nq;
    while (nq --) {
        int64_t foo;
        cin >> foo;
        cout << (foo == 0 ? ans : ans2) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    iota(c + 1, c + L + 1, 1);
    fill(nc + 1, nc + L + 1, 1);
    for (int i = 2 ; i <= L ; ++ i) {
        if (c[i] == 1) continue;
        for (int j = i ; j <= L ; j += i) {
            int cnt = 0;
            do {
                c[j] /= i;
                cnt ^= 1;
            } while (c[j] % i == 0);
            if (cnt) nc[j] *= i;
        }
    }

    for (cin >> T ; T -- ;) {
        solve();
    }
}
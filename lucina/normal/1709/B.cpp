#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int64_t a[nax];
int64_t b[nax];
int64_t sum_a[nax];
int64_t sum_b[nax];

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        sum_a[i] = sum_a[i - 1] + max(int64_t(0), a[i - 1] - a[i]);
        sum_b[i] = sum_b[i - 1] + max(int64_t(0), b[i - 1] - b[i]);
    }

    while (m --) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << sum_a[t] - sum_a[s] << '\n';
        } else {
            s = n - s + 1;
            t = n - t + 1;
            cout << sum_b[t] - sum_b[s] << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }
}
/*
    Eduroundd
*/
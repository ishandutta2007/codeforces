#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t n, m;
int k;
int64_t a[nax];

bool solve() {
    cin >> n >> m >> k;
    int64_t s = n * m;
    for (int i = 1 ; i <= k ; ++ i)
        cin >> a[i];

    int64_t ok_row = 0, ok_col = 0;
    int cnt_row = 0, cnt_col = 0;
    static int b[nax], c[nax];
    for (int i = 1 ; i <= k ; ++ i) {
        b[i] = a[i] / n, c[i] = a[i] / m;
    }
    sort(b + 1, b + 1 + k, greater<>());
    sort(c + 1, c + 1 + k, greater<>());
    for (int i = 1 ; i <= k ; ++ i) {
        if (b[i] >= 2) ok_row += b[i], cnt_row += 1;
        if (c[i] >= 2) ok_col += c[i], cnt_col += 1;
        if ((ok_row >= m && 2 * cnt_row <= m) || (ok_col >= n && 2 * cnt_col <= n))
            return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/*
    div.1 yay
*/
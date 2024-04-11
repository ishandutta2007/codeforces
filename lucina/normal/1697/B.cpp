#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n, q;
int64_t a[nax];

void solve() {
    cin >> n >> q;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1 ; i <= n ; ++ i)
        a[i] += a[i - 1];
    while (q --) {
        int x, y;
        cin >> x >> y;
        int s = n - x + 1;
        cout << a[s + (y - 1)] - a[s -1] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (T = 1 ;T-- ; ) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t d;
int64_t a[nax];

void solve() {
    cin >> n >> d;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }    sort(a + 1, a + 1 + n);

    int ans = 0;
    int head = 1;
    for (int tail = n ; tail >= 1 ; -- tail) {
        int64_t x = a[tail];
        while (head < tail && x <= d) x += a[tail], head += 1;
        if (x <= d) break;
        ans += 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }
}
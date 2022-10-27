#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;

int n;
int a[nax];
int bit[nax];

int get(int x) {
    int res = 0;
    for (; x > 0 ; x -= x & -x)
        res += bit[x];
    return res;
}

void add(int i, int val) {
    for (; i < nax ; i += i & -i)
        bit[i] += val;
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    fill(bit, bit + 1 + n, 0);
    int64_t ans = 0;

    for (int i = n ; i >= 1 ; -- i) {
        ans += get(a[i]);
        add(a[i], 1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}
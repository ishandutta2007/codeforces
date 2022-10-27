#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
array <int, 3> a[nax];
int n;
int used[nax];
void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        int l, r;
        cin >> l >> r;
        a[i] = {r - l, l, r};
    }
    fill(used + 1, used + 1 + n, false);
    sort(a + 1, a + 1 + n);
    for (int i = 1 ; i <= n ; ++ i) {
        int d;
        auto [_, l, r] = a[i];
        for (int x = l ; x <= r ; ++ x) {
            if (!used[x]) {
                used[x] = true;
                d = x;
                break;
            }
        }
        cout << l << ' ' << r << ' ' << d << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T-- ;) {
        solve();
    }
}
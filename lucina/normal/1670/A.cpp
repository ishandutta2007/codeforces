#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i] < 0) a[i] *= -1, cnt += 1;
    }
    for (int i = 1 ; i <= cnt ; ++ i) {
        a[i] *= -1;
    }
    if (is_sorted(a + 1, a + 1 + n)) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}
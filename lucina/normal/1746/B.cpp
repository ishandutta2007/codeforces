#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int n, k;

void solve() {
    cin >> n;

    int cnt = 0;
    int z = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        z += (a[i] == 0);
    }

    if (is_sorted(a + 1, a + 1 + n)) {
        cout << "0\n";
        return;
    }

    int ans = n;
    cnt = 0;

    for (int i = 1 ; i <= n ;) {
        if (a[i] != 1) {
            while (i <= n && a[i] == 0) {
                i += 1;
                z -= 1;
            }
        } else {
            cnt += 1;
            i += 1;
        }
        ans = min(ans, cnt + max(0, z - cnt));
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
/**
    Global round, GL

*/
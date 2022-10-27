#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, l;
int a[nax];

void solve() {
    cin >> n >> l;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int k = 0 ; k < l ; ++ k) {
        int s1 = 0, s2 = 0;
        for (int i = 1 ; i <= n ; ++ i)
            if (a[i] >> k & 1) s1 += 1;
            else s2 += 1;
        if (s1 >= s2) ans ^= 1 << k;
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
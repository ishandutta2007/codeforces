#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T -- ) {
        int n, m;
        cin >> n >> m;
        if (n < m) swap(n, m);
        if (n == m && n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int ans = n + m + m - 2;
        cout << ans << '\n';
    }

}
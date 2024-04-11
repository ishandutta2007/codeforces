#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n >> a[0];
        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 2 ; i < n ; ++ i) {
            if (a[i] > a[i - 1] + a[i + 1]) ++ ans;
        }

        if (a[0] == 1) {
            cout << (n - 1) / 2 << '\n';
        } else cout << ans << '\n';
    }
}
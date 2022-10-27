#include<bits/stdc++.h>
using namespace std;
const int nax = 50;
int a[nax];
int b[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        int64_t ans = 0;
        int n, x, y;
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i) cin >> ::a[i];
        for (int i = 1 ; i <= n ; ++ i) cin >> ::b[i];
        for (int i = 2 ; i <= n ; ++ i) {
            int x = a[i - 1], y = b[i - 1], a = ::a[i], b = ::b[i];
            ans += min(abs(x - a) + abs(y - b), abs(y - a) + abs(x - b));
        }
        cout << ans << '\n';
    }
}
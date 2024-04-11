#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];

void solve() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    sort(a, a + n);

    if (n % 2) {
        b[0] = a[0];
        for (int i = 0, x = 1, g = n / 2 ; i < n / 2 ; ++ i) {
            b[x++] = a[1 + i];
            b[x++] = a[1 + i + g];
        }
    } else {
        int g = n / 2;
        for (int i = 0, x = 0 ; i < n / 2 ; ++ i) {
            b[x++] = a[i];
            b[x++] = a[i + g];
        }
    }

    for (int i = 0 ; i < n ; ++ i) {
        int pre = b[(n + i - 1) % n];
        int nxt = b[(i + 1) % n];
        int cur = b[i];
        if ((cur < pre && cur < nxt) || (cur > pre && cur > nxt)) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0 ; i < n ; ++ i)
        cout << b[i] << ' ';
    cout << '\n';

    /**
        if some number has frequency >= half, it's impossible to do

    */
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
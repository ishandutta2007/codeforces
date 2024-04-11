#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n;
int a[nax];
int b[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int at_least = 0;
    int exact = -1;

    bool ok = true;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        if (b[i] == 0) {
            at_least = max(at_least, a[i]);
        } else {
            if (exact != -1 && a[i] - b[i] != exact)
                ok = false;
            if (a[i] < b[i]) ok = false;
            exact = a[i] - b[i];
        }
    }
    if (exact != -1 && exact < at_least) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int x;

void solve() {
    cin >> n >> x;
    for (int i = 1 ; i <= n * 2; ++ i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n * 2);
    for (int i = n ; i >= 1 ; -- i) {
        if (a[i + n] < a[i] + x) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
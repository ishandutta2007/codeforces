#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
bool shift[nax];
int rb[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) cin >> a[i], shift[i] = false;
    for (int i = 1 ; i <= n ; ++ i) cin >> b[i];

    for (int i = 1 ; i <= n ; ++ i) {
        cout << *lower_bound(b + 1, b + 1 + n, a[i]) - a[i] << ' ';
        if (i > 1 && a[i] <= b[i - 1]) shift[i] = true;
    }
    cout << '\n';


    for (int i = 1 ; i <= n ;) {
        int j = i;
        while (j <= n && shift[j] == shift[i]) j += 1;
        for (int k = i ; k < j ; ++ k) rb[k] = j - 1;
        i = j;
    }
    shift[n + 1] = false;
    for (int i = 1 ; i <= n ; ++ i) {
        if (shift[i + 1]) {
            cout << b[rb[i + 1]] - a[i] << ' ';
        } else cout << b[i] - a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;


    for (cin >> T ; T -- ;) {
        solve();
    }
}
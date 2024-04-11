#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
bool used[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    fill(used + 1, used + 1 + n, false);

    for (int i = 1 ; i <= n ; ++ i) {
        b[i] = a[i];
        for (int j = 1 ; j <= n ; ++ j) {
            if (used[j] || j == a[i]) continue;
            b[i] = j;
            used[j] = true;
            break;
        }
    }
    if (b[n] == a[n]) {
        swap(b[n], b[n - 1]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cout << b[i] << ' ';
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
/*
    +_+ So bored lately.
*/
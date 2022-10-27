#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n;
int s[nax];
int f[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> s[i];

    for (int i = 1 ; i <= n ; ++ i)
        cin >> f[i];
    for (int i = 1 ; i <= n ; ++ i) {
        s[i] = max(s[i], f[i - 1]);
        cout << f[i] - s[i] << ' ';
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
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    cin >> n;
    int p[2]{};
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        p[a[i] % 2] += 1;
    }
    cout << min(p[0], p[1]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
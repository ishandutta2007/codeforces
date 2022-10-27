#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int n, k;

void solve() {
    cin >> n >> k;
    bool has = false;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i] == 1) has = true;
    }

    cout << (has ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    Global round, GL

*/
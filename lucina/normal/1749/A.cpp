#include<bits/stdc++.h>
using namespace std;
int n, m;



void solve() {
    cin >> n >> m;

    for (int i = 0 ; i < m ; ++ i) {
        int x, y;
        cin >> x >> y;
    }

    cout << (n == m ? "NO" : "YES") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
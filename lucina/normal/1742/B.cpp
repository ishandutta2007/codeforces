#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set <int> s;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << (s.size() == n ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
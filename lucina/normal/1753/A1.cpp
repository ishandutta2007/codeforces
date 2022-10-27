#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    vector <pair <int, int>> p;

    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    if (n % 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 1 ; i <= n ; i += 2) {
        if (a[i] == a[i + 1]) {
            p.emplace_back(i, i + 1);
        } else {
            p.emplace_back(i, i);
            p.emplace_back(i + 1, i + 1);
        }
    }

    cout << p.size() << '\n';

    for (auto [u, v] : p) {
        cout << u << ' ' << v << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    div1
*/
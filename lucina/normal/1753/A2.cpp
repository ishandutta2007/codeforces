#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    vector <pair <int, int>> p;

    cin >> n;
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i] != 0) cnt += 1;
    }

    if (cnt % 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 1 ; i <= n ;) {
        int c = 0;
        int j = i;
        vector <int> where;
        while (j <= n && c != 2) {
            if (a[j] != 0) where.emplace_back(j), c += 1;
            j += 1;
        }
        if (c != 2) break;
        if (i < where[0]) {
            p.emplace_back(i, where[0] - 1);
        }
        i = where[0];
        if ((where[0] - where[1]) % 2 == 0) {
            if (a[where[0]] != a[where[1]]) {
                p.emplace_back(i, j - 1);
            } else {
                p.emplace_back(i, j - 3);
                p.emplace_back(j - 2, j - 1);
            }
        } else {
            if (a[where[0]] == a[where[1]]) {
                p.emplace_back(i, j - 1);
            } else {
                p.emplace_back(i, j - 2);
                p.emplace_back(j - 1, j - 1);
            }
        }
        i = j;
    }

    if (p.empty()) {
        p.emplace_back(1, n);
    }

    if (p.back().second != n) {
        p.emplace_back(p.back().second + 1, n);
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
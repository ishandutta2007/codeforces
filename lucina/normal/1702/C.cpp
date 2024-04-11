#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, q;
int a[nax];
int ans[nax];


void solve() {
    cin >> n >> q;
    map <int, vector <int>> occ;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        occ[a[i]].push_back(i);
    }
    for (int i = 1 ; i <= q ; ++ i) {
        int x, y;
        cin >> x >> y;
        if (!occ.count(x) || !occ.count(y)) {
            cout << "NO\n";
        } else {
            if (occ[x][0] < occ[y].back()) {
                cout << "YES\n";
            } else cout << "NO\n";
        }
    }




}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}
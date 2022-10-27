#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int dist(int a, int b, int x, int y) {
    return abs(x - a) + abs(y - b);
}

void solve() {
    cin >> n >> m;
    vector <int> q;
    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j < m ; ++ j) {
        q.push_back(max({
            dist(i, j, 0, 0),
            dist(i, j, 0, m - 1),
            dist(i, j, n - 1, 0),
            dist(i, j, n - 1, m - 1)
        }));
    }
    sort(q.begin(), q.end());
    for (int i : q)
        cout << i << ' ';
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
    Hm, don't know what to write?
    Well, just have fun I suppose.
*/
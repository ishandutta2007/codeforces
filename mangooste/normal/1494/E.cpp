#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int all = 0, same = 0;
    map<pair<int, int>, char> col;
    while (m--) {
        char t;
        cin >> t;
        if (t == '+') {
            int v, u;
            char c;
            cin >> v >> u >> c;
            if (col.find({u, v}) != col.end()) {
                all++;
                same += col[{u, v}] == c;
            }
            col[{v, u}] = c;
        } else if (t == '-') {
            int v, u;
            cin >> v >> u;
            if (col.find({v, u}) != col.end() && col.find({u, v}) != col.end()) {
                all--;
                same -= col[{v, u}] == col[{u, v}];
            }
            col.erase({v, u});
        } else {
            int k;
            cin >> k;
            k--;
            bool yes = false;
            if (k % 2 == 0)
                yes |= all;
            else
                yes |= same;
            cout << (yes ? "YES" : "NO") << '\n';
        }
    }
}
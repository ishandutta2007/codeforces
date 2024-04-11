
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, u, v;
int deg[N];
vector<pair<int, int>> edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        edge.emplace_back(u, v);
    }
    if(n == 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ve;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) ve.push_back(i);
    }
    u = ve[0], v = ve[1];
    int w = (ve.size() == 2 ? -1 : ve[2]);
    int cnt = n - 2;
    for(auto p : edge) {
        auto [x, y] = p;
        if(x == u || y == u) {
            cout << 0 << "\n";
        }else if(x == v || y == v) {
            cout << 1 << "\n";
        }else if(x == w || y == w) {
            cout << 2 << "\n";
        }else {
            cout << cnt-- << "\n";
        }
    }
}
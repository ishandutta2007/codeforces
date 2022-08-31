#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2005;
int a[maxN][maxN];
const int maxK = 505 * 505;
int c[maxK];
vector<pair<int,int>> edges;
int sz;
int go(vector<int>& f) {
    if (f.size() == 1) {
        c[f[0]] = a[f[0]][f[0]];
        return f[0];
    }
    int mx = 0;
    for (int x : f) {
        for (int y : f) {
            mx = max(mx, a[x][y]);
        }
    }
    vector<vector<int>> cur;
    for (int u : f) {
        bool pl = false;
        for (auto& it : cur) {
            if (a[u][it[0]] < mx) {
                pl = true;
                it.emplace_back(u);
                break;
            }
        }
        if (!pl) {
            cur.emplace_back();
            cur.back().emplace_back(u);
        }
    }
    int he = sz++;
    c[he] = mx;
    for (auto& it : cur) {
        int c = go(it);
        edges.emplace_back(c, he);
    }
    return he;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    sz = n + 1;
    vector<int> f(n);
    iota(f.begin(), f.end(), 1);
    int root = go(f);
    sz--;
    cout << sz << '\n';
    for (int i = 1; i <= sz; i++) cout << c[i] << " ";
    cout << '\n';
    cout << root << '\n';
    for (auto& it :edges) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}
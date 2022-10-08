
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int n, m, sx, sy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> sx >> sy;
    vi row, col;
    row.push_back(sx);
    col.push_back(sy);
    rep(i, 2, n + 1) {
        row.push_back(i == sx ? 1 : i);
    }
    rep(i, 2, m + 1) {
        col.push_back(i == sy ? 1 : i);
    }
    rep(i, 0, n) rep(j, 0, m) {
        cout << row[i] << ' ' << col[i % 2 == 0 ? j : m - j - 1] << '\n';
    }
}
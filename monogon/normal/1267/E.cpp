#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 105;

int n, m, a[M][N];
vector<int> ve = {-1};

vector<int> solve(int u) {
    vector<pair<int, int>> pos;
    for (int i = 1; i <= m; i++) {
        pos.push_back({a[i][u] - a[i][n], i});
    }
    sort(pos.begin(), pos.end(), greater<pair<int, int>>());
    vector<int> ve;
    int sum = 0;
    for (pair<int, int> &v : pos) {
        if ((sum += v.first) < 0) {
            ve.push_back(v.second);
        }
    }
    return ve;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        vector<int> cur = solve(i);
        if (ve.back() == -1 || cur.size() < ve.size()) {
            ve = cur;
        }
    }
    cout << ve.size() << '\n';
    for (int &v : ve) {
        cout << v << " ";
    }
}
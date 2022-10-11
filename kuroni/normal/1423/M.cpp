#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, INF = 1E9 + 7;

int m, n, ans = INF;
mt19937 mt(133769420);

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ret; cin >> ret; return ret;
}

int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

void solve(int u, int d, int l, int r) {
    if (u > d) {
        return;
    }
    int m = rand(u, d);
    pair<int, int> mi = {INF, 0};
    for (int i = l; i <= r; i++) {
        mi = min(mi, {ask(m, i), i});
    }
    ans = min(ans, mi.first);
    solve(u, m - 1, l, mi.second);
    solve(m + 1, d, mi.second, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    solve(1, m, 1, n);
    cout << "! " << ans << endl;
}
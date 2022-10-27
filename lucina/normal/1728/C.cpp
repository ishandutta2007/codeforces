#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int l(int x) {
    return to_string(x).size();
}
int a[nax];
int b[nax];
int n;

void solve() {
    cin >> n;
    map <int, int> f;
    for (int i = 1 ; i <= n ; ++ i) cin >> a[i], f[a[i]] += 1;
    vector <int> res_a, res_b;
    for (int i = 1 ; i <= n ; ++ i) {
            cin >> b[i];
            if (f[b[i]] > 0) {
                f[b[i]] -= 1;
            } else res_b.push_back(b[i]);
    }
    for (auto &[u, v] : f) for (int j = 0 ; j < v ; ++ j) res_a.push_back(u);
    int ans = 0;
    for (int &x : res_a) {
        if (x >= 10) ans += 1, x = l(x);
    //    cout << x << ' ';
    }
    for (int &x : res_b) {
        if (x >= 10) ans += 1, x = l(x);
    }
    f.clear();

    for (int i : res_a) f[i] += 1;
    for (int i : res_b) {
        if (f[i] > 0) {
                f[i] -= 1;
        } else if (i > 1) ans += 1;
    }
    for (auto &[u, v] : f) if (u > 1) ans += v;
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

inline ll _sqr(ll x) {
    return x * x;
}

void solve() {
    vector<int> a[3];
    int perm[3], sz[3];
    for (int i = 0; i < 3; i++) {
        cin >> sz[i];
        perm[i] = i;
        a[i].resize(sz[i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sz[i]; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    ll res = 4 * inf64;
    do {
        for (int x : a[perm[0]]) {
            if (a[perm[1]].front() > x || a[perm[2]].back() < x)
                continue;
            ll y = *(--upper_bound(a[perm[1]].begin(), a[perm[1]].end(), x));
            ll z = *lower_bound(a[perm[2]].begin(), a[perm[2]].end(), x);
            res = min(res, _sqr(x - y) + _sqr(x - z) + _sqr(y - z));
        }
    } while (next_permutation(perm, perm + 3));
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
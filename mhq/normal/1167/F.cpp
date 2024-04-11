#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 5 * (int)1e5 + 100;
int a[maxN];
int n;
vector < pair < int, int > > all;
int f[2][maxN];
void upd(int ind, int where, int by) {
    while (where <= n) {
        f[ind][where] = sum(f[ind][where], by);
        where = (where | (where - 1)) + 1;
    }
}
int get(int ind, int r) {
    int ans = 0;
    while (r > 0) {
        ans = sum(ans, f[ind][r]);
        r &= (r - 1);
    }
    return ans;
}
int get(int ind, int l, int r) {
    return sub(get(ind, r), get(ind, l - 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.emplace_back(a[i], i);
    }
    sort(all.begin(), all.end());
    int ans = 0;
    for (auto it : all) {
        int where = it.second;
        int cnt = mult(where, n + 1 - where);
        cnt = sum(cnt, mult(n + 1 - where, get(0, 1, where)));
        cnt = sum(cnt, mult(where, get(1, where, n)));
        ans = sum(ans, mult(cnt, a[where]));
        upd(0, where, where);
        upd(1, where, n + 1 - where);
    }
    cout << ans;
    return 0;
}
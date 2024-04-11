#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
int a[maxN];
int n;
vector<pair<int,int>> gg;
ll f[2][31];
struct Fenwick {
    vector<ll> f;
    int n;

    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1);
    }

    void upd(int pos, int v) {
        while (pos <= n) {
            f[pos] += v;
            pos = (pos | (pos - 1)) + 1;
        }
    }

    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
Fenwick fw(0);
void solve(int bit, int l, int r) {
    if (l > r || bit == -1) return;
    int mid = l - 1;
    while (mid + 1 <= r && (!(gg[mid + 1].first & (1 << bit)))) mid++;
    solve(bit - 1, l, mid);
    solve(bit - 1, mid + 1, r);
    for (int i = l; i <= mid; i++) {
        fw.upd(gg[i].second, +1);
    }
    for (int i = mid + 1; i <= r; i++) {
        int c = fw.get(gg[i].second);
        f[1][bit] += c;
        f[0][bit] += (mid - l + 1) - c;
    }
    for (int i = l; i <= mid; i++) {
        fw.upd(gg[i].second, -1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        gg.emplace_back(a[i], i);
    }
    sort(gg.begin(), gg.end());
    fw = Fenwick(n);
    solve(30, 0, n - 1);
    ll tot = 0;
    int x = 0;
    for (int i = 0; i <= 30; i++) {
        if (f[0][i] <= f[1][i]) {
            tot += f[0][i];
        }
        else {
            tot += f[1][i];
            x |= (1 << i);
        }
    }
    cout << tot << " " << x;
    return 0;
}
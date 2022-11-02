#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, a[maxn], b[maxn];
vector<int> pos[maxn];

int bit[maxn];

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

void upd(int i, int v) {
    for (i++; i < maxn; i += i & -i) bit[i] += v;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        pos[a[i]].push_back(i);
    }

    sort(b, b + n);

    ll ans = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int v = b[i];
        auto it = lower_bound(pos[v].begin(), pos[v].end(), p);
        if (it == pos[v].end()) {
            ans += n - p - (qry(n) - qry(p));
            p = pos[v][0] + 1;
            ans += p - qry(p);
        } else {
            int np = (*it) + 1;
            ans += np - p - (qry(np) - qry(p));
            p = np;
        }

        upd(p, 1);
    }

    cout << ans << '\n';
}
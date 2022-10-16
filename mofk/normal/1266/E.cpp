#include <bits/stdc++.h>

using namespace std;

int n;
long long a[200005];
map <pair <int, int>, int> mp;
long long ans;

void del(int u, int x) {
    int v = mp[{u, x}];
    ++a[v];
    if (a[v] > 0) ++ans;
    mp.erase({u, x});
}

void add(int u, int x, int v) {
    --a[v];
    if (a[v] >= 0) --ans;
    mp[{u, x}] = v;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], ans += a[i];
    int q;
    cin >> q;
    while (q--) {
        int u, x, v;
        cin >> u >> x >> v;
        if (mp.find({u, x}) != mp.end()) del(u, x);
        if (v) add(u, x, v);
        cout << ans << '\n';
    }
    return 0;
}
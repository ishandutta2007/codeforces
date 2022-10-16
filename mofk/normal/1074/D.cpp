#include <bits/stdc++.h>

using namespace std;

int q;
map <int, int> dad;
map <int, int> f;

int anc(int u) {
    if (dad.find(u) == dad.end()) return u;
    int p = dad[u];
    dad[u] = anc(p);
    f[u] ^= f[p];
    return dad[u];
}
void join(int u, int v, int val) {
    int pu = anc(u), pv = anc(v);
    if (pu == pv) return;
    dad[pv] = pu;
    f[pv] = val ^ f[u] ^ f[v];
}
int cal(int u, int v) {
    int pu = anc(u), pv = anc(v);
    if (pu != pv) return -1;
    return f[u] ^ f[v];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    int last = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l ^= last, r ^= last, v ^= last;
            if (l > r) swap(l, r);
            ++r;
            join(l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            l ^= last, r ^= last;
            if (l > r) swap(l, r);
            ++r;
            int ans = cal(l, r);
            last = abs(ans);
            cout << ans << '\n';
        }
    }
    return 0;
}
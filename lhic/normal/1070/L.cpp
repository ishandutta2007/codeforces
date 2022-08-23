#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

int n, m;
bitset<2010> ed[2010];

int go[2010];
int cl[2010];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        ed[i].reset();
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ed[a][b] = 1;
        ed[b][a] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (ed[i].count() % 2 == 1) {
            ed[i][i] = 1;
            ed[i][n] = 1;
        }
    }
    int now = 0;
    for (int i = 0; i < n; ++i) {
        int fl = 0;
        for (int j = now; j < n; ++j) {
            if (ed[j][i]) {
                fl = 1;
                swap(ed[j], ed[now]);
                break;
            }
        }
        if (!fl)
            continue;
        go[now] = i;
        for (int j = 0; j < n; ++j) {
            if (j == now || !ed[j][i])
                continue;
            ed[j] ^= ed[now];
        }
        ++now;
    }
    for (int j = now; j < n; ++j)
        if (ed[j][n]) {
            assert(false);
        }
    fill(cl, cl + n, 0);
    for (int j = 0; j < now; ++j) {
        if (ed[j][n])
            cl[go[j]] = 1;
    }
    int fl = 0;
    for (int j = 0; j < n; ++j)
        if (cl[j])
            fl = 1;
    cout << 1 + fl << "\n";
    for (int i = 0; i < n; ++i)
        cout << cl[i] + 1 << " ";
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        solve();
    }
	return 0;
}
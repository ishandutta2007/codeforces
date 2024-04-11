#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 210000;

int h[N];

int n, m;

vector<int> eds[N];

int was[N];

vector<int> vv;

void dfs1(int v) {
    was[v] = 1;
    for (int u: eds[v]) {
        if (!was[u]) {
            dfs1(u);
        }
    }
    vv.push_back(v);
}

int go[N];

int cl[N];

int fl[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        eds[a].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        if (!was[i]) {
            dfs1(i);
        }
    }
    for (int v: vv) {
        memset(fl, 0, sizeof(fl[0]) * (eds[v].size() + 1));
        for (int u: eds[v]) {
            fl[cl[u]] = 1;
        }
        cl[v] = 0;
        while (fl[cl[v]]) {
            ++cl[v];
        }
        go[cl[v]] ^= h[v];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (go[i]) {
            for (int j = 0; j < n; ++j) {
                if (cl[j] == i) {
                    int nv = h[j] ^ go[i];
                    if (nv >= h[j]) {
                        continue;
                    }
                    h[j] = nv;
                    for (int u: eds[j]) {
                        if (go[cl[u]]) {
                            h[u] ^= go[cl[u]];
                            go[cl[u]] = 0;
                        }
                    }
                    cout << "WIN\n";
                    for (int i = 0; i < n; ++i) {
                        cout << h[i] << " ";
                    }
                    cout << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "LOSE\n";
	return 0;
}
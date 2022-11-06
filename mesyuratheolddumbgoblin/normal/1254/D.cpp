#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 998244353
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
ll a[1000005], b[1000050];

ll t[666666], w[666666], tin[666666], tout[666666], pr[666666];

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

void modify(int l, int r, ll value) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            t[l] += value;
            while (t[l] >= MOD) {
                t[l] -= MOD;
            }
            l++;
        }
        if (r&1) {
            r--;
            t[r] += value;
            while (t[r] >= MOD) {
                t[r] -= MOD;
            }
        }
    }
}

ll query(int p) {
    ll res = 0;
    for (p += n; p > 0; p >>= 1) res += t[p];
    res %= MOD;
    return res;
}

vector<ll> g[228228];
vector<pii> cg[228228];

bool cmp(ll x, ll y) {
    return w[x] < w[y];
}

void init_dfs(ll v, ll p = -1) {
    w[v] = 1;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        init_dfs(to, v);
        w[v] += w[to];
        pr[to] = v;
    }
    sort(g[v].begin(), g[v].end(), cmp);
}

ll timer;
void dfs(ll v, ll p = -1) {
    tin[v] = timer++;
    ll init_w = -1;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        if (init_w == -1) {
            init_w = w[to];
        } else if (init_w != w[to]) {
            cg[v].push_back(mp(init_w, tin[to]));
            init_w = w[to];
        }
    }
    tout[v] = timer;
    cg[v].push_back(mp(init_w, tout[v]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll invn = inv(n);
    init_dfs(1);
    dfs(1);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll v, d;
            cin >> v >> d;
            for (int j = 0; j < cg[v].size(); j++) {
                ll l = tin[v] + 1;
                if (j > 0) {
                    l = cg[v][j-1].Y;
                }
                ll r = cg[v][j].Y;
                ll ww = n - cg[v][j].X;
                ll addsubtree = invn * d % MOD * ww % MOD;
                //cout << l << " " << r << " " << addsubtree << endl;
                modify(l, r, addsubtree);
            }
            //cout << "___" << endl;
            ll addnotsubtree = invn * d % MOD * (w[v]) % MOD;
            /*cout << addsubtree << " " << addnotsubtree << " " << tin[v] << " " << tout[v] << endl;
            for (int j = 0; j < n; j++) {
                cout << query(j) << " ";
            }
            cout << endl;*/
            modify(tin[v], tout[v], MOD - addnotsubtree);
            modify(tin[1], tout[1], addnotsubtree);
            modify(tin[v], tin[v] + 1, d);

            /*for (int j = 0; j < n; j++) {
                cout << query(j) << " ";
            }
            cout << endl;*/
        } else {
            ll v;
            cin >> v;
            cout << query(tin[v]) << "\n";
        }
    }

    return 0;
}
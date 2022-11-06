#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

ll Abs(ll x) {
    return x>0?x:-x;
}

void add(ll& x, ll y) {
    x += y;
    x %= MOD;
}

ll used[1005][1005], n, i, j, k, l, r, p, m,speed[15], ans[15];
vector<pii> g[50];
char c[1005][1005];

ll dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool good(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m && !used[x][y]);
}

void try_move(ll v) {
    vector<pii> to_move;
    for (int i = 0; i < g[v].size(); i++) {
        ll x = g[v][i].X;
        ll y = g[v][i].Y;
        for (int j = 0; j < 4; j++) {
            ll dx = x + dirs[j][0];
            ll dy = y + dirs[j][1];
            if (good(dx, dy)) {
                used[dx][dy] = 1;
                to_move.push_back(mp(dx, dy));
            }
        }
    }
    g[v].clear();
    for (int i = 0; i < to_move.size(); i++) {
        g[v].push_back(to_move[i]);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++) {
        cin >> speed[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '#') {
                used[i][j] = 1;
            }
            if (c[i][j] >= '1' && c[i][j] <= '9') {
                g[c[i][j]-'1'].push_back(mp(i,j));
                used[i][j] = 1;
            }
        }
    }


    while (1) {
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < speed[i]; j++) {
                if (g[i].empty()) {
                    break;
                }
                ans[i] += g[i].size();
                try_move(i);
            }
        }
        ll sum = 0;
        for (int i = 0; i < p; i++) {
            sum += g[i].size();
        }
        if (sum == 0) {
            break;
        }
    }
    for (int i = 0; i <p; i++)
        cout << ans[i] << " ";
  return 0;
}
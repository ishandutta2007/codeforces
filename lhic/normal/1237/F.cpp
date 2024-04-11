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


const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int N = 4000;

ll tmp[2][N];

ll fc[N];
ll bfc[N];

void add(ll &a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void solve(int a[N], int n, ll dp[N]) {
    memset(tmp, 0, sizeof(tmp));
    tmp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            for (int j = n - 1; j >= 0; --j) {
                tmp[1][j] = 0;
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                add(tmp[0][j + 1], tmp[1][j]);
                tmp[1][j] = tmp[0][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i] = tmp[0][i];
    }
}



int a[N];
int b[N];
ll dpa[N];
ll dpb[N];

int h, w, n;

ll get(ll n, ll k) {
    return fc[n] * bfc[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    fc[0] = 1;
    for (int i = 1; i < N; ++i) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    for (int i = 0; i < N; ++i) {
        bfc[i] = pw(fc[i], MOD - 2);
    }

    cin >> h >> w >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        a[x1] = a[x2] = 1;
        b[y1] = b[y2] = 1;
    }

    solve(a, h, dpa);
    solve(b, w, dpb);
    int ca = h;
    int cb = w;
    for (int i = 0; i < h; ++i) {
        ca -= a[i];
    }

    for (int i = 0; i < w; ++i) {
        cb -= b[i];
    }

    ll ans = 0;
    for (int k = 0; 2 * k <= ca; ++k) {
        for (int l = 0; 2 * l <= cb; ++l) {
            if (l + 2 * k > ca || k + 2 * l > cb) {
                continue;
            }
            ans = (ans + dpa[k] * dpb[l] % MOD * get(ca - 2 * k, l) % MOD * get(cb - 2 * l, k)) % MOD;
        }
    }

    cout << ans << "\n";
	return 0;
}
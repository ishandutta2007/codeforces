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
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll a[15][15], b[25][25], c[150], d[150], invs[150], prec[1500000], prt[1500000], dr[50], pshe;

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

ll precalc_invs() {
    for (int j = 1; j <= 100; j++) {
        invs[j] = inv(j);
    }
}

void gener(ll pos, ll lst, ll mask) {
    if (pos == lst) {
        c[mask] = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!((mask >> i) & 1) && b[pos][i]) {
            gener(pos+1, lst, (mask | (1<<i)));
        }
    }
}

ll fnd(ll x) {
    if (prt[x] != -1) {
        return prt[x];
    }
    ll y = 0;
    for (int i = 0; i < pshe; i++) {
        if ((x >> i) & 1) {
            dr[y++] = i;
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1<<y); i++) {
        ll s = 0;
        for (int j = 0; j < y; j++) {
            if ((i >> j) & 1) {
                s |= (1<<dr[j]);
            }
        }
        ans += prec[s];
    }
    return prt[x] = ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc_invs();
    cin >> n;
    for (int i = 0 ;i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    ll m1 = (n / 2) * n;
    ll m2 = (n - n/2) * n;
    pshe = 0;
    for (int i = 0; i < (1<<n); i++) {
        ll bits = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                bits++;
            }
        }
        if (bits == n / 2) {
            d[i] = pshe++;
        }
    }
    for (int i = 0; i < (1<<pshe); i++) {
        prt[i] = -1;
    }

    for (int i = 0; i < (1<< m1); i++) {
        ll p = 1;
        for (int j = 0; j < 64; j++) {
            c[j] = 0;
        }

        for (int j = 0; j < n/2; j++) {
            for (int k = 0; k < n; k++) {
                b[j][k] = 0;
            }
        }
        for (int j = 0; j < m1; j++) {
            ll curx = j / n;
            ll cury = j % n;
            ll bit = ((i>>j) & 1);
            if (bit) {
                p = p * a[curx][cury] % MOD * invs[100] % MOD;

                b[curx][cury] = 1;
            } else {
                p = p * (100 - a[curx][cury]) % MOD * invs[100] % MOD;
            }
        }
        gener(0, n/2, 0);
        ll sum = 0;
        for (int j = 0; j < 64; j++) {
            if (c[j]) {
                sum |= (1<<d[j]);
            }
        }
        prec[sum] = (prec[sum] + p) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < (1<< m2); i++) {
        ll p = 1;

        for (int j = 0; j < 64; j++) {
            c[j] = 0;
        }

        for (int j = 0; j < n - n/2; j++) {
            for (int k = 0; k < n; k++) {
                b[j][k] = 0;
            }
        }

        for (int j = 0; j < m2; j++) {
            ll curx = j / n + n / 2;
            ll cury = j % n;
            ll bit = ((i>>j) & 1);
            if (bit) {
                p = p * a[curx][cury] % MOD * invs[100] % MOD;
                b[curx - n / 2][cury] = 1;
            } else {
                p = p * (100 - a[curx][cury]) % MOD * invs[100] % MOD;
            }
        }

        ll sum = 0;
        gener(0, n-n/2, 0);
        for (int j = 0; j < 64; j++) {
            if (c[j]) {
                sum |= (1 << d[(1<<n) - 1 - j]);
            }
        }
        sum = (1<<pshe) - 1 - sum;

        ans += (1 - fnd(sum) + MOD) * p % MOD;

    }
    cout << ans % MOD << endl;



    return 0;
}
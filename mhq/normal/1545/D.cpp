#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int m, k;
const int maxN = 1005;
ll x[maxN][maxN];
ll s[maxN];
ll square_sum[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> m >> k;
    for (int i = 0; i < k; i++) {
        s[i] = 0;
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
            s[i] += x[i][j];
        }
    }
    assert((s[k - 1] - s[0]) % (k - 1) == 0);
    ll D = (s[k - 1] - s[0]) / (k - 1);
    int where = -1;
    for (int i = 1; i < k; i++) {
        if (s[i] != s[0] + D * i) {
            assert(where == -1);
            where = i;

        }
    }
    assert(where != -1);
    for (int z = 0; z < k; z++) {
        for (int j = 0; j < m; j++) {
            square_sum[z] += x[z][j] * x[z][j];
        }
    }
    ll a[2][3];
    int sz = 0;
    for (int z = 1; z < k; z++) {
        if (z == where) continue;
        if (sz == 2) break;
        a[sz][0] = z * z;
        a[sz][1] = 2 * z;
        a[sz][2] = square_sum[z] - square_sum[0];
        sz++;
    }
    assert(sz == 2);
    auto det = [&](ll a00, ll a01, ll a10, ll a11) {
        return a00 * a11 - a01 * a10;
    };
    ll S = det(a[0][0], a[0][1], a[1][0], a[1][1]);
    assert(D != 0);
    ll A = det(a[0][2], a[0][1], a[1][2], a[1][1]);
    assert(A % S == 0);
    A /= S;
    ll B = det(a[0][0], a[0][2], a[1][0], a[1][2]);
    assert(B % S == 0);
    B /= S;
    assert(a[0][0] * A + a[0][1] * B == a[0][2]);
    assert(a[1][0] * A + a[1][1] * B == a[1][2]);
    ll delta = s[0] + where * D - s[where];
    ll delta_square = 1LL * where * where * A + 2LL * where * B + square_sum[0] - square_sum[where];
    assert(delta_square != 0 && delta != 0);
    for (int z = 0; z < m; z++) {
        ll to = x[where][z] + delta;
        if (to * to - x[where][z] * x[where][z] == delta_square) {
            cout << where << " " << to << endl;
            return 0;
        }
    }
    return 0;
}
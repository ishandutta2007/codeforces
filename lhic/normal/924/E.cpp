#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

#ifndef BZ
const int MAXN = 10003;
#else
const int MAXN = 1003;
#endif

int a[MAXN];
int b[MAXN];

using Arr = array<int, MAXN>;
const int C = MAXN;

vector<int> gd;
vector<int> bd;

using BitSet = bitset<MAXN>;

BitSet f[MAXN];
int sf[MAXN];

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    int h = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        h += a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i]) {
            gd.push_back(a[i]);
        } else {
            bd.push_back(a[i]);
        }
    }

    sort(gd.begin(), gd.end(), greater<>{});
    sort(bd.begin(), bd.end());
    int gc = gd.size(), bc = bd.size();

    BitSet cur{};
    cur[0] = true;
    for (int x : bd) {
        cur = cur | (cur << x);
    }

    f[0] = cur;
    for (int i = 0; i < gc; ++i) {
        f[i + 1] = f[i] | (f[i] << gd[i]);
    }

    int ans = 0;
    Arr ca{};
    ca.fill(-MAXN);
    ca[0] = 0;
    for (int i = gc - 1; i >= 0; --i) {
        sf[0] = 0;
        int x = gd[i];

        for (int j = 0; j <= h; ++j) {
            sf[j + 1] = sf[j] + f[i][j];
        }

        for (int j = 0; j <= h; ++j) {
            if (ca[j] >= 0) {
                int lv = l + j;
                int rv = r;
                if (lv > rv) {
                    continue;
                }

                lv += x;
                rv += x;
                rv = min(rv, h);
                if (lv > rv) {
                    continue;
                }

                if (sf[h - rv] != sf[h - lv + 1]) {
                    ans = max(ans, ca[j] + 1);
                }
            }
        }

        for (int j = h; j >= x; --j) {
            ca[j] = max(ca[j], ca[j - x] + 1);
        }
    }


    cout << ans << "\n";
}
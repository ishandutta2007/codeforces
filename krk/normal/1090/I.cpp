#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int Maxn = 10000005;

int t;
int n, l, r;
uint x, y, z, b1, b2;
int a[Maxn];
int seq[Maxn], slen;
ll res;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        ll mod = ll(r) - l + 1;
        a[1] = ll(b1) % mod + l;
        a[2] = ll(b2) % mod + l;
        for (int j = 3; j <= n; j++) {
            uint b3 = b1 * x + b2 * y + z;
            a[j] = ll(b3) % mod + l;
            b1 = b2; b2 = b3;
        }
        slen = 0;
        int mn = a[1];
        if (a[1] < 0) seq[slen++] = a[1];
        bool was = false;
        for (int i = 2; i <= n; i++) {
            if (a[i] >= 0) {
                if (mn < a[i])
                    if (!was) { was = true; res = ll(a[i]) * mn; }
                    else res = min(res, ll(a[i]) * mn);
            } else {
                while (slen > 0 && seq[slen - 1] < a[i]) {
                    if (!was) { was = true; res = ll(a[i]) * seq[slen - 1]; }
                    else res = min(res, ll(a[i]) * seq[slen - 1]);
                    slen--;
                }
                seq[slen++] = a[i];
            }
            mn = min(mn, a[i]);
        }
        if (!was) cout << "IMPOSSIBLE\n";
        else cout << res << "\n";
    }
    return 0;
}
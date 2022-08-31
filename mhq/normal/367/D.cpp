#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, d;
const int maxN = 1e5 + 10;
int id[maxN];
const int maxK = 20;
int cnt[maxK];
bool bad[(1 << maxK) + 10];
int bits[(1 << maxK) + 10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int x;
            cin >> x;
            id[x] = i;
        }
    }
    int msk = 0;
    for (int i = 1; i <= d; i++) {
        if (!cnt[id[i]]) msk |= (1 << id[i]);
        cnt[id[i]]++;
    }
    //cout << msk << " ??? " << endl;
    bad[((1 << m) - 1) ^ msk] = true;
    for (int i = d + 1; i <= n; i++) {
        cnt[id[i - d]]--;
        if (!cnt[id[i - d]]) msk ^= (1 << id[i - d]);
        if (!cnt[id[i]]) msk |= (1 << id[i]);
        cnt[id[i]]++;
        bad[((1 << m) - 1) ^ msk] = true;
    }
    for (int z = 0; z < m; z++) {
        for (int x = 0; x < (1 << m); x++) {
            if (x & (1 << z)) {
                bad[x ^ (1 << z)] |= bad[x];
            }
        }
    }
    //cout << bad[0] << endl;
    for (int i = 1; i < (1 << m); i++) bits[i] = bits[i >> 1] + (i & 1);
    int best = m;
    for (int z = 0; z < (1 << m); z++) {
        if (!bad[z]) best = min(best, bits[z]);
    }
    cout << best;
    return 0;
}
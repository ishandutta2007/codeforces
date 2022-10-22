#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    vector<int> f(n), last(n);
    int K = 1;
    while (K * K < m) K++; K++;
    vector<vector<int>> good(K, vector<int>(K));

    vector<int> ar(m);

    int cur_sum = 0;
    int cur_ptr = -1;

    for (int it = 0; it < m; it++) {
        int op, k;
        cin >> op >> k;
        k--;
        f[k] ^= 1;
        if (f[k])
            last[k] = it;
        auto [x, y] = a[k];
        int coef = f[k] ? +1 : -1;
        if (x + y < K) {
            int md = x + y;
            for (int r = 0; r < md; r++) {
                int hlp = ((r - last[k]) % md + md) % md;
                if (hlp >= x)
                    good[md][r] += coef;
            }
        } else {
            for (int i = last[k] + x; i < m; i += x + y) {
                // [i, i + y)
                ar[i] += coef;
                if (i <= cur_ptr)
                    cur_sum += coef;
                if (i + y < m) {
                    if (i + y <= cur_ptr)
                        cur_sum -= coef;
                    ar[i + y] -= coef;
                }
            }
        }

        int res = 0;
        for (int md = 1; md < K; md++)
            res += good[md][it % md];

        while (cur_ptr < it)
            cur_sum += ar[++cur_ptr];

        res += cur_sum;

        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}
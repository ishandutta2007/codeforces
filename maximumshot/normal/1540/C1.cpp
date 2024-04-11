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

const int mod = inf + 7;

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void _add(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

inline void _dec(int& x, int y) {
    if ((x -= y) < 0)
        x += mod;
}

const int MAXX = 105;
const int MAXS = 4e6;

vector<int> fast(int n, vector<int> c, vector<int> b, int q, vector<int> xs) {
    vector<int> prB(n);
    for (int i = 1; i < n; i++)
        prB[i] = prB[i - 1] + b[i];
    vector<int> B(n + 1);
    for (int i = 2; i <= n; i++)
        B[i] = B[i - 1] + prB[i - 1];
    vector<int> cur(MAXS);
    cur[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> pu(MAXS);
        for (int value = 0; value < MAXS; value++) {
            // value + a[i] - x - prB[i] >= 0
            // a[i] >= x + prB[i] - value
            // 0 <= a[i] <= c[i + 1]
            int le = max(0, xs[0] + prB[i] - value);
            int ri = c[i + 1];
            int base_value = value - xs[0] - prB[i];
            le += base_value;
            ri += base_value;
//            for (int next_value = le; next_value <= ri; next_value++)
//                _add(dp[i + 1][next_value], dp[i][value]);
            if (le <= ri) {
                if (le < MAXS)
                    _add(pu[le], cur[value]);
                if (ri + 1 < MAXS)
                _dec(pu[ri + 1], cur[value]);
            }
//            for (int ai = le; ai <= ri; ai++) {
//                int next_value = base_value + ai;
//                _add(dp[i + 1][next_value], dp[i][value]);
//            }
        }
        for (int x = 0; x < MAXS; x++)
            _add(pu[x + 1], pu[x]);
        cur = pu;
    }
    int res = 0;
    for (int value = 0; value < MAXS; value++)
        _add(res, cur[value]);
    return {res};
}

void work() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<int> b(n);
    for (int i = 1; i < n; i++)
        cin >> b[i];
    int q;
    cin >> q;
    vector<int> xs(q);
    for (auto& x : xs)
        cin >> x;
    vector<int> res = fast(n, c, b, q, xs);
    for (auto x : res)
        cout << x << "\n";
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
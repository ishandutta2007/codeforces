#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> res;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - '0';
    }

    auto process = [&](int i, int j) {
        int need = 0;
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                if (a[i + x][j + y])
                    need ^= (1 << (x * 2 + y));
        for (int take = 0; take < (1 << 4); take++) {
            int mask = 0;
            for (int it = 0; it < 4; it++) {
                if ((1 << it) & take)
                    mask ^= (15 ^ (1 << it));
            }
            if (mask == need) {
                for (int it = 0; it < 4; it++) {
                    if ((1 << it) & take) {
                        vector<pii> op;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                if (2 * x + y == it)
                                    continue;
                                op.emplace_back(i + x, j + y);
                                a[i + x][j + y] ^= 1;
                            }
                        }
                        res.push_back(op);
                    }
                }
                break;
            }
        }

    };

    for (int i = 0; i + 1 < n; i += 2)
        for (int j = 0; j + 1 < m; j += 2)
            process(i, j);

    if (n % 2)
        for (int j = 0; j + 1 < m; j += 2)
            process(n - 2, j);
    if (m % 2)
        for (int i = 0; i + 1 < n; i += 2)
            process(i, m - 2);
    if (n % 2 && m % 2)
        process(n - 2, m - 2);

    cout << (int) res.size() << "\n";
    for (auto op : res) {
        for (auto p : op)
            cout << p.first + 1 << " " << p.second + 1 << " ";
        cout << "\n";
    }

//    cout << "\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
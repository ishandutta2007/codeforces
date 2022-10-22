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

vector<vector<int>> fast(int n, int m, vector<vector<int>> b) {
    vector<vector<int>> res(n + 1, vector<int>(m));
    for (int j = 0; j < m; j++) {
        res[1][j] = b[1][j];
    }
    vector<int> cur = res[1];
    for (int i = 2; i <= n; i++) {
        vector<int> p1(m), p2(m);
        for (int j = 0; j < m; j++) {
            p1[j] = j;
            p2[j] = j;
        }
        sort(p1.begin(), p1.end(), [&](int x, int y) {
            return cur[x] < cur[y];
        });
        sort(p2.begin(), p2.end(), [&](int x, int y) {
            return b[i][x] > b[i][y];
        });
        for (int it = 0; it < m; it++) {
            res[i][p1[it]] = b[i][p2[it]];
        }
        for (int j = 0; j < m; j++) {
            cur[j] = min(cur[j], res[i][j]);
        }
    }
    return res;
}

ll calc_score(int n, int m, vector<vector<int>> res) {
    ll score = 0;
    for (int j = 0; j < m; j++) {
        int mn = inf + 10;
        for (int i = 1; i <= n; i++)
            mn = min(mn, res[i][j]);
        score += mn;
    }
    return score;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> b(n + 1, vector<int>(m));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }
        vector<vector<int>> fs = fast(n, m, b);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                cout << fs[i][j] << " ";
            }
            cout << "\n";
        }
//        if (1) cout << "score = " << calc_score(n, m, fs) << "\n";
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
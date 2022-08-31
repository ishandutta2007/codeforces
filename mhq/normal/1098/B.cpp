#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
char f[4] = {'A', 'G', 'C', 'T'};
int id(char x) {
    if (x == 'A') return 0;
    else if (x == 'G') return 1;
    else if (x == 'C') return 2;
    else if (x == 'T') return 3;
    return -1;
}
int n, m;
pair < int, vector < vector < int > > > solve(vector < vector < int > > a) {
    int n = a.size();
    int m = a.back().size();
    vector < int > cur = {0, 1, 2, 3};
    int best = n * m + 100;
    vector < vector < int > > opt;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            vector < int > all[2];
            all[0] = {i, j};
            for (int v : cur) {
                if (v == i || v == j) continue;
                all[1].push_back(v);
            }
            int val = 0;
            vector < vector < int > > ans(n, vector < int >(m, 0));
            for (int row = 0; row < n; row++) {
                int tp = row % 2;
                int val1 = 0;
                int val2 = 0;
                for (int col = 0; col < m; col++) {
                    val1 += (a[row][col] != all[tp][col % 2]);
                    val2 += (a[row][col] != all[tp][(col + 1) % 2]);
                }
                val += min(val1, val2);
                if (val1 < val2) {
                    for (int col = 0; col < m; col++) {
                        ans[row][col] = all[tp][col % 2];
                    }
                }
                else {
                    for (int col = 0; col < m; col++) {
                        ans[row][col] = all[tp][(col + 1) % 2];
                    }
                }
            }
            if (best > val) {
                opt = ans;
                best = val;
            }
        }
    }
    return make_pair(best, opt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < vector < int > > a(n, vector < int > (m, 0));
    vector < vector < int > > b(m, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            a[i][j] = id(x);
            b[j][i] = a[i][j];
        }
    }
    auto t1 = solve(a);
    auto t2 = solve(b);
    if (t1.first < t2.first) {
        for (int i = 0; i < t1.second.size(); i++) {
            for (int j = 0; j < t1.second[i].size(); j++) {
                cout << f[t1.second[i][j]];
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << f[t2.second[j][i]];
            }
            cout << '\n';
        }
    }
    return 0;
}
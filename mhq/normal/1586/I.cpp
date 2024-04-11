#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2005;
int a[maxN][maxN];
int b[maxN][maxN];
vector<pair<int,int>> by[maxN];
const int dx[3] = {-1, 0, 0};
const int dy[3] = {0, -1, 1};
int his_val[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n % 2 == 1) {
        cout << "NONE";
        return 0;
    }
    for (int j = 0; j < n; j++) {
        a[0][j] = j / 2;
        b[0][j] = 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < n; j++) {
            int xr = 0;
            int c = 0;
            vector<int> vals;
            vals.emplace_back(a[i][j]);
            for (int z = 0; z < 3; z++) {
                int ni = i + dx[z];
                int nj = j + dy[z];
                if (ni < 0 || ni >= n) continue;
                if (nj < 0 || nj >= n) continue;
                vals.emplace_back(a[ni][nj]);
            }
            int cnt = 0;
            int he = -1;
            sort(vals.begin(), vals.end());
            vals.erase(unique(vals.begin(), vals.end()), vals.end());
            for (int& t : vals) {
                int pp = 0;
                for (int z = 0; z < 3; z++) {
                    int ni = i + dx[z];
                    int nj = j + dy[z];
                    if (ni < 0 || ni >= n) continue;
                    if (nj < 0 || nj >= n) continue;
                    if (a[ni][nj] == t) pp ^= 1;
                    if (a[i][j] == t) pp ^= 1;
                }
                if (pp && t != a[i][j]) {
                    cnt++;
                    he = t;
                }
            }
            assert(cnt == 0 || cnt == 1);
            if (cnt == 0) a[i + 1][j] = a[i][j];
            else a[i + 1][j] = he;
            int pp = 0;
            for (int z = 0; z < 3; z++) {
                int ni = i + dx[z];
                int nj = j + dy[z];
                if (ni < 0 || ni >= n) continue;
                if (nj < 0 || nj >= n) continue;
                pp ^= b[ni][nj];
                pp ^= b[i][j];
                pp ^= 1;
            }
            b[i + 1][j] = (pp ^ 1) ^ b[i][j];
        }
    }
    memset(his_val, -1, sizeof his_val);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.') continue;
            int d = 0;
            if (c == 'S') d = 0;
            else d = 1;
            d ^= b[i][j];
            if (his_val[a[i][j]] == -1) his_val[a[i][j]] = d;
            if (his_val[a[i][j]] != d) ok = false;
        }
    }
    if (!ok) {
        cout << "NONE\n";
        return 0;
    }
    bool hs = false;
    for (int z = 0; z < n / 2; z++) {
        if (his_val[z] == -1) hs = true;
    }
    if (hs) {
        cout << "MULTIPLE\n";
        return 0;
    }
    cout << "UNIQUE\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = his_val[a[i][j]] ^ b[i][j];
            if (d == 0) cout << "S";
            else cout << "G";
        }
        cout << '\n';
    }
    return 0;
}
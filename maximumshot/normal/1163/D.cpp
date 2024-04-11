#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> get_pref(string s) {
    int n = (int)s.size();
    vector<int> p(n);
    for (int j, i = 1; i < n; i++) {
        j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

vector<vector<int>> get(string s) {
    int n = (int)s.size();
    vector<vector<int>> g(n + 1, vector<int>(26));
    vector<int> p = get_pref(s);
    for (int i = 0; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            int j = i;
            while (1) {
                if (j + 1 <= n && s[j] == c + 'a') {
                    g[i][c] = j + 1;
                    break;
                }
                if (j == 0) {
                    g[i][c] = j;
                    break;
                }
                j = p[j - 1];
            }
        }
    }
    return g;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string c, s, t;

    cin >> c >> s >> t;

    int nc = (int)c.size();
    int ns = (int)s.size();
    int nt = (int)t.size();

    vector<vector<int>> gs = get(s), gt = get(t);

    c = " " + c;
    s = " " + s;
    t = " " + t;

    vector<vector<vector<int>>> dp(nc + 1, vector<vector<int>>(ns + 1, vector<int>(nt + 1, -inf)));

//    for (int i = 0; i <= nt; i++) {
//        for (int cc = 0; cc < 26; cc++) {
//            cout << i << " -- " << cc << " --> " << gt[i][cc] << "\n";
//        }
//    }

    dp[0][0][0] = 0;

    for (int i = 1; i <= nc; i++) {
        if (c[i] != '*') {
            for (int x = 0; x <= ns; x++) {
                for (int y = 0; y <= nt; y++) {
                    int xx = gs[x][c[i] - 'a'];
                    int yy = gt[y][c[i] - 'a'];
                    dp[i][xx][yy] = max(dp[i][xx][yy], dp[i - 1][x][y] + (xx == ns) - (yy == nt));
                }
            }
            continue;
        }
        for (int x = 0; x <= ns; x++) {
            for (int y = 0; y <= nt; y++) {
                for (int cc = 0; cc < 26; cc++) {
                    int xx = gs[x][cc];
                    int yy = gt[y][cc];
                    dp[i][xx][yy] = max(dp[i][xx][yy], dp[i - 1][x][y] + (xx == ns) - (yy == nt));
                }
            }
        }
    }

    int res = -inf;

    for (int x = 0; x <= ns; x++) {
        for (int y = 0; y <= nt; y++) {

            res = max(res, dp[nc][x][y]);
        }
    }

    cout << res << "\n";

    return 0;
}
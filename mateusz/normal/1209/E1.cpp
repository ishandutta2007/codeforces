#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int t, n, m, tab[N][N];
int ans;

int setup[20];

int compWyn(const vector<int> &cols) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 0; j < cols.size(); j++) {
            int col = cols[j];
            mx = max(mx, tab[(i - 1 + setup[j]) % n + 1][col]);
        }
        ret += mx;
    }
    return ret;
}

void backtrack(const vector<int> &cols, int w) {
    if (w == cols.size()) {
        ans = max(ans, compWyn(cols));
        return;
    }
    
    for (int i = 0; i < n; i++) {
        setup[w] = i;
        backtrack(cols, w + 1);
    }
}

int main() {
    
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &tab[i][j]);
            }
        }
        vector<pair<int, int> > cols;
        for (int j = 1; j <= m; j++) {
            int mx = 0;
            for (int i = 1; i <= n; i++) {
                mx = max(mx, tab[i][j]);
            }
            cols.push_back({mx, j});
        }
        sort(cols.begin(), cols.end());
        reverse(cols.begin(), cols.end());
        vector<int> c;
        for (int i = 0; i < min(n, m); i++) {
            c.push_back(cols[i].second);
        }
        backtrack(c, 0);
        printf("%d\n", ans);
    }
    return 0;
}
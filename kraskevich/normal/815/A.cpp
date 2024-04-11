#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


const int INF = 1000 * 1000 * 1000;
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<int> ans_rows(n);
    vector<int> ans_cols(m);
    int ans = INF;
    for (int x = 0; x <= 555; x++) {
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        rows[0] = x;
        for (int i = 0; i < m; i++)
            cols[i] = a[0][i] - x;
        for (int i = 1; i < n; i++)
            rows[i] = a[i][0] - cols[0];
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (a[i][j] != rows[i] + cols[j])
                    ok = false;
        for (int i = 0; i < n; i++)
            if (rows[i] < 0)
                ok = false;
        for (int i = 0; i < m; i++)
            if (cols[i] < 0)
                ok = false;
        if (!ok)
            continue;
        int cur = accumulate(rows.begin(), rows.end(), 0) + accumulate(cols.begin(), cols.end(), 0);
        if (cur < ans) {
            ans = cur;
            ans_rows = rows;
            ans_cols = cols;
        }
    }
    if (ans == INF) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < ans_rows[i]; j++)
            cout << "row " << i + 1 << "\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < ans_cols[i]; j++)
            cout << "col " << i + 1 << "\n";
}
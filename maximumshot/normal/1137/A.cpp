#include <bits/stdc++.h>

using namespace std;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b = a, c = a;
    vector<int> row(n), col(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> crd;
        for (int j = 0; j < m; j++) {
            crd.push_back(a[i][j]);
        }
        sort(crd.begin(), crd.end());
        crd.resize(unique(crd.begin(), crd.end()) - crd.begin());
        for (int j = 0; j < m; j++) {
            b[i][j] = lower_bound(crd.begin(), crd.end(), a[i][j]) - crd.begin();
        }
        row[i] = (int)crd.size();
    }

    for (int j = 0; j < m; j++) {
        vector<int> crd;
        for (int i = 0; i < n; i++) {
            crd.push_back(a[i][j]);
        }
        sort(crd.begin(), crd.end());
        crd.resize(unique(crd.begin(), crd.end()) - crd.begin());
        for (int i = 0; i < n; i++) {
            c[i][j] = lower_bound(crd.begin(), crd.end(), a[i][j]) - crd.begin();
        }
        col[j] = (int)crd.size();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l1 = -b[i][j];
            int r1 = row[i] - 1 - b[i][j];
            int l2 = -c[i][j];
            int r2 = col[j] - 1 - c[i][j];
            l1 = min(l1, l2);
            r1 = max(r1, r2);
            cout << r1 - l1 + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
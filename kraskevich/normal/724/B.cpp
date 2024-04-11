#include <bits/stdc++.h>

using namespace std;

int diff(vector<int> a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != i + 1)
            res++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int x = 0; x < m; x++)
        for (int y = 0; y < m; y++) {
            for (int i = 0; i < n; i++)
                swap(a[i][x], a[i][y]);
            bool ok = true;
            for (int i = 0; i < n; i++)
                if (diff(a[i]) > 2) 
                    ok = false;
            if (ok) {
                cout << "YES" << endl;
                return 0;
            }
            for (int i = 0; i < n; i++)
                swap(a[i][x], a[i][y]);
        }
    cout << "NO" << endl;
    return 0;
}
 #include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int x = 1;
    vector<vector<int>> y(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> y[i][j];
            x *= y[i][j] / gcd(x, y[i][j]);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2)
                cout << x;
            else
                cout << x + y[i][j] * y[i][j] * y[i][j] * y[i][j];
            cout << " \n"[j == m - 1];
        }
}
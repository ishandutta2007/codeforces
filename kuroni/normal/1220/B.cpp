#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<long long> b(n);
    b[0] = round(sqrt(1LL * a[0][1] * a[0][2] / a[1][2]));
    for (int i = 1; i < n; i++) {
        b[i] = a[0][i] / b[0];
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
}
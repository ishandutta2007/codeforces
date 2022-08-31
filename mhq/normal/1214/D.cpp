#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < vector < char > > a(n, vector < char > (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector < vector < bool > > reachFrom(n, vector < bool >(m, false)), reachTo(n, vector < bool >(m, false));
    reachFrom[0][0] = true; reachTo[n - 1][m - 1] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') continue;
            if (i > 0 && reachFrom[i - 1][j]) reachFrom[i][j] = true;
            if (j > 0 && reachFrom[i][j - 1]) reachFrom[i][j] = true;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == '#') continue;
            if (i + 1 < n && reachTo[i + 1][j]) reachTo[i][j] = true;
            if (j + 1 < m && reachTo[i][j + 1]) reachTo[i][j] = true;
        }
    }
    if (!reachFrom[n - 1][m - 1]) {
        cout << 0;
        return 0;
    }
    int xA = 0, yA = 1;
    int xB = 1, yB = 0;
    while (xA + yA < n - 1 + m - 1) {
        if (xA >= n || xB >= n || yA >= m || yB >= m) {
            cout << 1;
            return 0;
        }
        if (xA == xB && yA == yB) {
            cout << 1;
            return 0;
        }
        if (!reachTo[xA][yA] || !reachFrom[xA][yA]) {
            cout << 1;
            return 0;
        }
        if (!reachFrom[xB][yB] || !reachTo[xB][yB]) {
            cout << 1;
            return 0;
        }
        if (yA + 1 < m && reachTo[xA][yA + 1]) yA++;
        else xA++;
        if (xB + 1 < n && reachTo[xB + 1][yB]) xB++;
        else yB++;
    }
    cout << 2;
    return 0;
}
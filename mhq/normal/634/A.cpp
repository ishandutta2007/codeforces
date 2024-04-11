#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN][2];
int pos[2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > f[2];
    for  (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                f[j].push_back(a[i][j]);
                if (a[i][j] == 1) pos[j] = f[j].size() - 1;
            }
        }
    }
    for (int i = 0; i < (n - 1); i++) {
        if (f[0][(pos[0] + i) % (n - 1)] != f[1][(pos[1] + i) % (n - 1)]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
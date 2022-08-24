#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 505;
bool g[maxN][maxN];
int val[maxN];
int n, m;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
        g[y][x] = true;
    }
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!g[i][j]) {
                ind1 = i;
                ind2 = j;
            }
        }
    }
    if (ind1 == -1) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) cout << "a";
        exit(0);
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i == ind1) {
                val[i] = 0;
            }
            else if (i == ind2){
                val[i] = 2;
            }
            else {
                if (g[i][ind1] && g[i][ind2]) {
                    val[i] = 1;
                }
                else if (!g[i][ind1] && !g[i][ind2]) {
                    cout << "No";
                    exit(0);
                }
                else if (!g[i][ind1]) {
                    val[i] = 2;
                }
                else {
                    val[i] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool edge = ((abs(val[i] - val[j])) < 2);
            if (edge != g[i][j]) {
                cout << "No";
                exit(0);
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << (char)('a' + val[i]);
    }
    return 0;
}
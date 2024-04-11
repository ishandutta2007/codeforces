#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
const int maxM = 5 * (int)1e5 + 100;
typedef bitset < maxN > bs;
bs ed[maxN];
bs mat[maxN];
int n, m;
int a[maxM], b[maxM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        mat[a[i]][b[i]] = true;
    }
    for (int i = 1; i <= n; i++) ed[i][i] = true;
    for (int i = 1; i <= n; i++) {
        int col = -1;
        for (int j = i; j <= n; j++) {
            if (mat[j][i] == true) {
                col = j;
                break;
            }
        }
        assert(col != -1);
        swap(mat[i], mat[col]);
        swap(ed[i], ed[col]);
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (mat[j][i]) {
                mat[j] ^= mat[i];
                ed[j] ^= ed[i];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ed[b[i]][a[i]]) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}
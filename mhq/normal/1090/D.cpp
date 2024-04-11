#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int n, m;
map < pair < int, int >, bool > ok;
int val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ok[minmax(x, y)] = true;
    }
    if (2 * m == 1LL * n * (n - 1)) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 1; i <= n; i++) {
        if (ind1 != -1) break;
        for (int j = i + 1; j <= n; j++) {
            if (ok.count(make_pair(i, j))) continue;
            ind1 = i;
            ind2 = j;
            break;
        }
    }
    val[ind1] = 1;
    val[ind2] = 2;
    int last = 3;
    for (int i = 1; i <= n; i++) {
        if (i == ind1 || i == ind2) continue;
        val[i] = last;
        last++;
    }
    for (int i = 1; i <= n; i++) cout << val[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        if (i == ind2) cout << 1 << " ";
        else cout << val[i] << " ";
    }
    return 0;
}
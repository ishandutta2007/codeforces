#include <bits/stdc++.h>

using namespace std;
int n;
int l[20000], r[20000];
bool dfs(int x, int y) {
    if (x == y) return true;
    if (r[x] == 0) return false;
    return dfs(r[x], y);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (r[j] == 0 && l[k] == 0 && !dfs(k, j)) {
                    r[j] = k;
                    l[k] = j;
                    break;
                }
    }
    for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";

    return 0;
}
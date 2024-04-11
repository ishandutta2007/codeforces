#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > g[1005];
int deg[1005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i + 1);
        deg[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) continue;
        int cnt = 0;
        for (int j = 0; j < g[i].size(); j++) {
            if (deg[g[i][j]] == 0) cnt++;
        }
        if (cnt < 3) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
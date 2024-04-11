#include <bits/stdc++.h>
using namespace std;
const int maxN = 305;
int n;
int d[maxN];
vector < int > g[1005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    int vert = d[n] + 1;
    for (int i = n; i >= 1; i--) {
        if (i < (n + 1 - i)) break;
        int mndeg = d[n + 1 - i];
        for (int j = vert; j >= vert - mndeg + 1; j--) {
            for (int k = 1; k < j; k++) g[j].push_back(k);
        }
        for (int j = n + 1 - i; j < i; j++) d[j] -= mndeg;
        vert = d[i - 1] + 1;
    }
    int sum = 0;
    for (int i = 1; i <= d[n] + 1; i++) sum += g[i].size();
    cout << sum << '\n';
    for (int i = 1; i <= (d[n] + 1); i++) {
        for (int j = 0; j < g[i].size(); j++) cout << i << " " << g[i][j] << '\n';
    }
    return 0;
}
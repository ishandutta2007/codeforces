#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
int lim[maxN];
int m[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    int best = 0;
    for (int i = n; i >= 1; i--) {
        best--;
        best = max(best, m[i] + 1);
        lim[i] = best;
    }
    for (int i = 1; i <= n; i++) {
        lim[i] = max(lim[i], lim[i - 1]);
    }
    //for (int i = 1; i <= n; i++) cout << lim[i] << " ";
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += lim[i]  - m[i] - 1;
    }
    cout << ans;
    return 0;
}
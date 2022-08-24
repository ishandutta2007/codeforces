#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[101][101];
int f[101];
int pref[101];
pair < int, int > ans (int x) {
    for (int i = 0; i <= n; i++) {
            f[i] = 0;
            pref[i] = 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i][x];
        pref[i] = pref[i  - 1];
        if (a[i][x] == 1) pref[i]++;
        f[i] = s;
    }
    int t = 0;
    int q = 0;
    for (int i = 1; i <= n; i++) {
        if (t < f[min(n, i + k - 1)] - f[i - 1]) {
            t = f[min(n, i + k  - 1)] - f[i - 1];
            q = pref[i - 1];
        }
    }
    return make_pair(t, q);
}
int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 1; i <= m; i++) {
        pair <int, int> r = ans(i);
        ans1 += r.first;
        ans2 += r.second;
    }
    cout << ans1 << " " << ans2;
return 0;
}
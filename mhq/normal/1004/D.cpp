#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
int t;
int cnt[maxN];
int cop[maxN];
void go(int n, int m, int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m) return;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int val = abs(i - x) + abs(j - y);
            cnt[val]--;
            if (cnt[val] < 0) return;
        }
    }
    for (int i = 0; i < t; i++) {
        if (cnt[i] != 0) return;
    }
    cout << n << " " << m << '\n' << x << " " << y;
    exit(0);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        cop[x]++;
    }
    if (cnt[0] != 1) {
        cout << -1;
        return 0;
    }
    int ind = 0;
    for (int i = 1; i <= t; i++) {
        if (cnt[i] != 4 * i) {
            ind = i - 1;
            break;
        }
    }
    int sum = -1;
    for (int i = t - 1; i >= 0; i--) {
        if (cnt[i] != 0) {
            sum = i;
            break;
        }
    }
    for (int i = 1; i <= t; i++) {
        if (t % i == 0) {
            int n = i;
            int m = t / i;
            int mnx = ind;
            if (n <= mnx) continue;
            int mxx = n - 1 - mnx;
            int mxy = sum - mxx;
            go(n, m, 1 + mxx, 1 + mxy);
            for (int j = 0; j <= t; j++) cnt[j] = cop[j];
        }
    }
    cout << -1;
    return 0;
}
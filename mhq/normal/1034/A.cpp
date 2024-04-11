#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxK = 1.5 * (int)1e7 + 100;
int lp[maxK];
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
const int maxN = 3 * (int)1e5 + 10;
int n;
int a[maxN];
int val[maxK];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    for (int i = 2; i < maxK; i++) {
        if (lp[i] != 0) continue;
        for (int j = i; j < maxK; j += i) lp[j] = i;
    }
    cin >> n;
    int gc = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) gc = a[i];
        else gc = gcd(gc, a[i]);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        a[i] /= gc;
        mx = max(mx, a[i]);
        while (a[i] > 1) {
            int p = lp[a[i]];
            val[p]++;
            while (a[i] % p == 0) a[i] /= p;
        }
    }
    //cout << "HRER" << " " << gc << endl;
    int ans = n + 1;
    for (int i = 1; i <= mx; i++) {
        //cout << i << endl;
        if (val[i] == 0) continue;
        ans = min(ans, n - val[i]);
    }
    if (ans == n + 1) {
        cout << -1;
    }
    else cout << ans;
    return 0;
}
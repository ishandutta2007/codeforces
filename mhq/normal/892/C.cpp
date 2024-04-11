#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2010;
int a[maxN];
bool ok;
int cnt;
int x;
int curm = (int)1e6 + 10;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //cout << mult(100000, 100000);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x = gcd(x, a[i]);
        if (a[i] == 1) ok = true;
        else cnt++;
    }
    if (ok) {
        cout << cnt;
        return 0;
    }
    if (x != 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        for (int j = i + 1; j <= n; j++) {
            cur = gcd(cur, a[j]);
            if (cur == 1) {
                curm = min(j - i + 1, curm);
            }
        }
    }
    cout << n + curm - 2;
    return 0;
}
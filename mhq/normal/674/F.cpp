#include <bits/stdc++.h>
using namespace std;
#define int unsigned int
typedef long long ll;
const int maxP = 140;
int n, p, q;
int c[maxP];
int cnt[maxP];
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> p >> q;
    p = min(p, n - 1);
    c[0] = 1;
    for (int i = 1; i <= p; i++) {
        int cur = i;
        cnt[i] = n - i + 1;
        for (int j = 1; j <= i; j++) {
            int d = gcd(cur, cnt[j]);
            cnt[j] /= d;
            cur /= d;
        }
        int t = 1;
        for (int j = 1; j <= i; j++) t *= cnt[j];
        c[i] = t;
    }
    int f = 0;
    for (int i = 1; i <= q; i++) {
        int cur = 0;
        int t = 1;
        for (int j = 0; j <= p; j++) {
            cur += c[j] * t;
            t *= i;
        }
        cur *= i;
        f ^= cur;
    }
    cout << f;
}
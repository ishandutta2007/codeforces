#include <bits/stdc++.h>
using namespace std;
int n, k;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = mult(ans, a);
        }
        a = mult(a, a);
        b /= 2;
    }
    return ans;
}
int rev(int a) {
    return pw(a, mod - 2);
}
int power[(int)1e6 + 10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= (k + 1); i++) {
        power[i] = sum(power[i - 1], pw(i, k));
    }
    int big = 1;
    if (n <= k + 1) {
        cout << power[n];
        return 0;
    }
    for (int i = 0; i <= (k + 1); i++) {
        big = mult(big, n - i);
    }
    int down = 1;
    int sgn = 1;
    for (int i = 1; i <= (k + 1); i++) {
        down = mult(down, rev(i));
    }
    int ans = 0;
    for (int i = 0; i <= (k + 1); i++) {
        int up = mult(big, rev(n - (k + 1 - i)));
        if (sgn == 1) {
            ans = sum(ans, mult(mult(up, power[k + 1 - i]), down));
        }
        else {
            ans = sub(ans, mult(mult(up, power[k + 1 - i]), down));
        }
        sgn *= -1;
        down = mult(down, k + 1 - i);
        down = mult(down, rev(i + 1));
    }
    cout << ans;
    return 0;
}
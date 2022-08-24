#include <bits/stdc++.h>

using namespace std;
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
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int n, m, k;
const int maxN = (int)1e5 + 100;
int b[maxN];
int d[50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 2; i <= 26; i++) {
        int t = (1 << i) - 1;
        d[i] = -1;
        for (int k = 2; 1LL * k * k <= t; k++) {
            if (t % k == 0) {
                d[i] = t / k;
                break;
            }
        }
        d[i] = max(d[i], 1);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        for (int j = 0; j <= 26; j++) {
            if (x == ((1 << j) - 1)) {
                cout << d[j] << endl;
                break;
            }
            if (x < (1 << j)) {
                cout << (1 << j) - 1 << endl;
                break;
            }
        }
    }
    return 0;
}
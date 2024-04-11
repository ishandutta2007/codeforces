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
int b, k;
const int maxN = (int)1e5 + 100;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> b >> k;
    int sm = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        sm += a[i];
    }
    if (b % 2 == 0) {
        if (a[k - 1] % 2 == 0) cout << "even";
        else cout << "odd";
    }
    else {
        if (sm % 2 == 0) cout << "even";
        else cout << "odd";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int x, y;
vector < int > pr;
const int mod = (int)1e9 + 7;
int ans[(1 << 23)];
int add(int a, int b) {
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
int binpw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, binpw(mult(a, a), b / 2));
    }
    else return binpw(mult(a, a), b / 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    y = y / x;
    int cop = y;
    for (int i = 2; i * i <= y; i++) {
        if (y % i == 0) {
            y /= i;
            pr.push_back(i);
            while (y % i == 0) {
                y /= i;
            }
        }
    }
    if (y != 1) {
        pr.push_back(y);
    }
    y = cop;
    int t = (1 << pr.size());
    int ans = 0;
    for (int i = 0; i < t; i++) {
        int odd = 0;
        for (int j = 0; j < pr.size(); j++) {
            if (i & (1 << j)) {
                cop /= pr[j];
                odd++;
            }
        }
        if (odd % 2 == 0) {
            ans = add(ans, binpw(2, cop - 1));
        }
        else ans = sub(ans, binpw(2, cop - 1));
        cop = y;
    }
    cout << ans;
    return 0;
}
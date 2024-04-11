#include <bits/stdc++.h>
using namespace std;
int a, b, p;
long long x;
int mult(int a, int b) {
    return (1LL * a * b) % p;
}
int pw(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b /= 2;
    }
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> a >> b >> p >> x;
    long long cnt = 0;
    for (int i = 1; i <= (p - 1); i++) {
        int n = mult(b, pw(pw(a, i), p - 2));
        long long q = (1LL * i * p - (1LL * n * (p - 1)));
        if (q < 0) q += (1LL * p * (p - 1));
        if (q % (1LL * p * (p - 1)) > x % (1LL * p * (p - 1))) cnt += (x / (1LL * p * (p - 1)));
        else cnt += (x / (1LL * p * (p - 1))) + 1;
    }
    cout << cnt;
    return 0;
}
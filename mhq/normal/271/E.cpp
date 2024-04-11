#include <bits/stdc++.h>
using namespace std;
int n, m;
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
int a[(int)1e5 + 10];
/*
    a, b -> 1, 14
    d = 13;
    d = 1;
    a a + 13
    a + 13, a + 26
    a, a + 26
    a -> a / 2
    a -> (a + 1) / 2
    1, 2
    1, 3
    2, 4
    1, 4
    3, 5
    1, 5
*/
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
    }
    int d = a[1];
    for (int i = 1; i <= n; i++) {
        d = gcd(d, a[i]);
    }
    //cout << d << '\n';
    long long ans = 0;
    vector < int > div;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            if (i == (d / i)) div.push_back(i);
            else {
                div.push_back(i);
                div.push_back(d / i);
            }
        }
    }
    for (int i = 0; i < div.size(); i++) {
        d = div[i];
        while (1) {
            ans += m - d;
            d = 2 * d;
            if (d > m) break;
        }
    }
    cout << ans;
    return 0;
}
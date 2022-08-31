/*
    28.12.2018 17:37:43
*/

#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;

int main() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long i1 = 0;
    while (i1 < n && s[i1] == s[0]) {
        ++i1;
    }
    long long i2 = n - 1;
    while (i2 >= 0 && s[i2] == s[n - 1]) {
        --i2;
    }
    i2 = n - 1 - i2;
    // cout << i1 << ' ' << i2 << '\n';
    long long ans = 0;
    if (s[0] == s[n - 1]) {
        ans = (i1 + 1) * (i2 + 1);
    } else {
        ans = i1 + i2 + 1;
    }
    if (i1 == n) {
        ans = n * (n + 1) / 2;
    }
    cout << ans % mod << '\n';
    return 0;
}
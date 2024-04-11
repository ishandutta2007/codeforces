#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
string s;
int n;
vector<int> a;
vector<int> f;
vector<int> g;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    int l = 0;
    while (l < n && s[l] == '0') ++l;
    if (l == n) return cout << n << endl, 0;
    int r = n - 1;
    while (s[r] == '0') --r;
    int mul = 1ll * (l + 1) * (n - r) % mod;
    int cur = 0;
    for (int i = l + 1; i <= r; ++i) {
        if (s[i] == '0') ++cur;
        else {
            a.push_back(cur);
            cur = 0;
        }
    }
    if (a.empty()) return cout << mul << endl, 0;
    int m = a.size();
    f.assign(m + 1, 0);
    g.assign(n + 1, 0);
    int sum = 1;
    f[m] = 1;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j <= a[i]; ++j) {
            sum = (sum + mod - g[j]) % mod;
            g[j] = f[i+1];
            sum = (sum + g[j]) % mod;
        }
        f[i] = sum;
    }
    cout << 1ll * f[0] * mul % mod << endl;
    return 0;
}
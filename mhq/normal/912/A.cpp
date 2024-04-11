#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
pair < int, int > s[maxN];
int t[maxN];
void add(int i, int d) {
    for (; i < maxN; i = (i | (i - 1)) + 1) {
        t[i] = (t[i] + d) % mod;
    }
}
int ss(int r) {
    int res = 0;
    while (r >= 1) {
        res = (res + t[r]) % mod;
        r = (r & (r - 1));
    }
    return res;
}
int sum(int l, int r) {
    return ((ss(r) - ss(l - 1)) + mod) % mod;
}
int main() {
    //freopen("input.txt", "r", stdin);
    long long a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    long long needa = 2 * x + y;
    long long needb = y + 3 * z;
    cout << max(needa -  a, 1LL * 0) + max(needb - b, 1LL * 0);
    return 0;
}
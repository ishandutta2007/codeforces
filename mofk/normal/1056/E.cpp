#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> ii;

const ii mod = ii(1000000009, 1007050321);
const ii base = ii(337, 337);

ii operator % (const ii &a, const ii &b) {
    return ii(a.first % b.first, a.second % b.second);
}
ii operator * (const ii &a, const ii &b) {
    return ii(a.first * b.first, a.second * b.second) % mod;
}
ii operator + (const ii &a, const ii &b) {
    return ii(a.first + b.first, a.second + b.second) % mod;
}
ii operator - (const ii &a, const ii &b) {
    return (ii(a.first - b.first, a.second - b.second) % mod + mod) % mod;
}

int n, m, c0, c1;
string s, t;
ii h[1000006];
ii pw[1000006];

ii get_hash(int l, int len) {
    return h[l + len - 1] - h[l - 1] * pw[len];
}

int chk(int len) {
    if (1ll * len * c0 >= m) return 0;
    if ((m - len * c0) % c1 != 0) return 0;
    int len1 = (m - len * c0) / c1;
    int ptr = 1;
    ii key0 = get_hash(1, len);
    ii key1 = ii(-1, -1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (get_hash(ptr, len) != key0) return 0;
            ptr += len;
        }
        else {
            if (key1.first == -1) key1 = get_hash(ptr, len1);
            else if (get_hash(ptr, len1) != key1) return 0;
            ptr += len1;
        }
    }
    if (key0 == key1) return 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    if (s[0] == '1') for (int i = 0; i < n; ++i) if (s[i] == '0') s[i] = '1'; else s[i] = '0';
    for (int i = 0; i < n; ++i) if (s[i] == '0') ++c0; else ++c1;

    for (int i = 1; i <= m; ++i) h[i] = h[i-1] * base + ii(t[i-1], t[i-1]);
    pw[0] = ii(1, 1);
    for (int i = 1; i <= m; ++i) pw[i] = pw[i-1] * base;

    int ans = 0;
    for (int i = 1; i < m; ++i) ans += chk(i);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1007050321, base = 521;
string s;
int n;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> s;
        n = s.size();
        int l = 0, r = n - 1;
        string t;
        while (l < r && s[l] == s[r]) t += s[l], ++l, --r;
        if (l >= r) {
            cout << s << '\n';
            continue;
        }
        int p1 = l, q1 = l - 1;
        long long key1 = 0, key2 = 0, mul = 1;
        for (int i = l; i <= r; ++i) {
            key1 = (key1 * base + s[i]) % mod;
            key2 = (key2 + s[i] * mul) % mod;
            mul = mul * base % mod;
            if (key1 == key2) q1 = i;
        }
        int p2 = r + 1, q2 = r;
        key1 = key2 = 0, mul = 1;
        for (int i = r; i >= l; --i) {
            key1 = (key1 * base + s[i]) % mod;
            key2 = (key2 + s[i] * mul) % mod;
            mul = mul * base % mod;
            if (key1 == key2) p2 = i;
        }
        string ans = t;
        if (q2 - p2 < q1 - p1) {
            for (int i = p1; i <= q1; ++i) t += s[i];
        }
        else {
            for (int i = p2; i <= q2; ++i) t += s[i];
        }
        reverse(t.begin(), t.end());
        ans += t;
        cout << ans << '\n';
    }
    return 0;
}
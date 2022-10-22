#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ok = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        ok |= (s[i] == s[j]);
    }

    if (!ok) {
        for (int i = 0; i < n; i++) {
            cout << (k % 2 ? s[(i + 1) % n] : s[i]);
        }
        cout << "\n";
        return 0;
    }

    auto nxt = [&](int x) {
        return x + 1 < n ? x + 1 : 0;
    };

    auto prv = [&](int x) {
        return x > 0 ? x - 1 : n - 1;
    };

    vector<int> le(n, inf), ri(n, inf);
    vector<int> in_bl(n);

    for (int i = 0; i < n; i++) {
        in_bl[i] = s[i] == s[prv(i)] || s[i] == s[nxt(i)];
    }

    for (int i = 0; i < 2 * n; i++) {
        int ii = i % n;
        if (in_bl[ii]) {
            le[ii] = 0;
        }
        le[ii] = min(le[ii], le[prv(ii)] + 1);
    }

    for (int i = 2 * n - 1; i >= 0; i--) {
        int ii = i % n;
        if (in_bl[ii]) {
            ri[ii] = 0;
        }
        ri[ii] = min(ri[ii], ri[nxt(ii)] + 1);
    }

    for (int i = 0; i < n; i++) {
        int j, d;
        if (le[i] < ri[i]) {
            j = ((i - le[i]) % n + n) % n;
            d = le[i];
        } else {
            j = (i + ri[i]) % n;
            d = ri[i];
        }
        if (d <= k) {
            cout << s[j];
        } else {
            cout << char(k % 2 ? s[i] ^ 'W' ^ 'B' : s[i]);
        }
    }

    cout << "\n";

    return 0;
}
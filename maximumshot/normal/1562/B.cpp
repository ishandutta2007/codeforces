#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1e5 + 5;

int pr[X];

void precalc() {
    fill(pr, pr + X, 1);
    pr[0] = 0;
    for (int p = 2; p * p < X; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < X; x += p)
            pr[x] = 0;
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    precalc();

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        string res;
        for (char c : s) {
            if (c == '1' || c == '4' || c == '6' || c == '8' || c == '9') {
                res = string(1, c);
                break;
            }
        }
        if (res.empty()) {
            for (int i = 0; i < k; i++) {
                for (int j = i + 1; j < k; j++) {
                    if (s[i] == s[j]) {
                        res = string(1, s[i]) + string(1, s[j]);
                    }
                }
            }
        }

        // 2357
        if (res.empty()) {
            for (int mask = 1; mask < (1 << k); mask++) {
                int value = 0;
                for (int i = 0; i < k; i++) {
                    if ((1 << i) & mask)
                        value = value * 10 + s[i] - '0';
                }
                if (!pr[value]) {
                    res = to_string(value);
                    break;
                }
            }
        }

        cout << (int) res.size() << "\n" << res << "\n";
    }

    return 0;
}
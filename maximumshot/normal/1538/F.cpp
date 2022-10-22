#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int MAXL = 30;

ll dp[MAXL];

void precalc() {
    for (int i = 1; i < MAXL; i++) {
        dp[i] = dp[i - 1] + 9ll * (i + dp[i - 1]);
    }
}

ll up(string s) {
    ll res = 0;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        ll add = ('9' - s[i]) * ((int) s.size() - i + dp[(int) s.size() - i - 1]);
        res += add;
    }
    return res;
}

ll down(string s) {
    return up(string(s.size(), '0')) - up(s);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        string sl = to_string(l);
        string sr = to_string(r);

        while (sl.size() < sr.size()) sl.insert(sl.begin(), '0');
        int n = (int) sr.size();

        ll res = 0;

        for (int i = 0; i < n; i++) {
            if (sl[i] != sr[i]) {
                if (i + 1 < n) {
                    res += up(sl.substr(i + 1));
                    res += n - i;
                    sl[i]++;
                    res += (sr[i] - sl[i]) * (up(string(n - i - 1, '0')) + n - i);
                    res += down(sr.substr(i + 1));
                } else {
                    res += sr[i] - sl[i];
                }
                break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
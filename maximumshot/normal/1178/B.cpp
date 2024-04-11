#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = (int) s.size();

    ll res = 0;

    vector<int> pref(n), suff(n);

    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        if (s[i] == 'v' && s[i - 1] == 'v') {
            pref[i]++;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1];
        if (s[i] == 'v' && s[i + 1] == 'v') {
            suff[i]++;
        }
    }

    for (int i = 1; i + 1 < n; i++) {
        if (s[i] == 'o') {
            res += 1ll * pref[i - 1] * suff[i + 1];
        }
    }

    cout << res << "\n";

    return 0;
}
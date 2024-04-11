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

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    ll res = 0;
    for (int i = 0, sm = 0, init = 0; ; init++) {
        while (i < n && init + sm >= 0) {
            sm += s[i] == '+' ? 1 : -1;
            i++;
        }
        res += i;
        if (init + sm >= 0)
            break;
    }
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    for (int ti = 0; ti < tt; ti++) {
        solve();
    }

    return 0;
}
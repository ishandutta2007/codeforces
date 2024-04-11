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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int best_k = -1;
    string best_s = "?";

    for (int k = 1; k <= n; k++) {
        string tmp = s.substr(k - 1);
        string pref = s.substr(0, k - 1);
        if ((n - k + 1) % 2) {
            reverse(pref.begin(), pref.end());
        }
        tmp += pref;
        if (best_k == -1 || best_s > tmp)
            best_s = tmp, best_k = k;
    }
    cout << best_s << "\n" << best_k << "\n";
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
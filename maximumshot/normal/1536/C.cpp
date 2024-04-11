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

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> dp(n);
        unordered_map<ll, int> last;
        for (int a = 0, b = 0, i = 0; i < n; i++) {
            if (s[i] == 'K') a++;
            else b++;
            int g = gcd(a, b);
            int aa = a / g;
            int bb = b / g;
            ll h = 1ll * aa * (n + 1) + bb;
            auto fnd = last.find(h);
            if (fnd == last.end()) {
                dp[i] = 1;
            } else {
                dp[i] = dp[fnd->second] + 1;
            }
            last[h] = i;
            cout << dp[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
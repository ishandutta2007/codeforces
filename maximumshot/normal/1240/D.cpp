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

const int N = 3e5 + 5;

int n;
int a[N];
int link[N];
int dp[N];
unordered_map<int, int> big_link[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        big_link[i].clear();
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int j = i - 1;

        if (big_link[j].count(a[i])) {
            j = big_link[j][a[i]];
        } else {
            j = 0;
        }

        if (j > 0) {
            dp[i] = dp[j - 1] + 1;
            link[i] = j - 1;
            swap(big_link[i], big_link[j - 1]);
        }  else {
            dp[i] = 0;
            link[i] = 0;
        }

        big_link[i][a[i]] = i;

        res += dp[i];
    }
    cout << res << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}
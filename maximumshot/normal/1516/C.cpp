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

const int X = 2e5 + 5;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int total = 0;
    for (int i = 1; i <= n; i++)
        total += a[i];

    bitset<X> dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp = dp | (dp << a[i]);

    if (total % 2 || !dp[total / 2]) {
        cout << 0 << "\n";
        return 0;
    }

    int res = -1;
    while (1) {
        int S = 0, any = -1;
        for (int i = 1; i <= n; i++) {
            S += a[i];
            if (a[i] % 2)
                any = i;
        }
        if (S % 2)
            break;
        if (any != -1) {
            res = any;
            break;
        }
        for (int i = 1; i <= n; i++)
            a[i] /= 2;
    }

    cout << "1\n" << res << "\n";

    return 0;
}
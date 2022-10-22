#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(2);
        cin >> a[0] >> a[1];
        vector<int> dp(n);
        int last0 = -1, last1 = -1;
        for (int i = 0; i < n; i++) {
            if (a[0][i] == '0' || a[1][i] == '0') last0 = i;
            if (a[0][i] == '1' || a[1][i] == '1') last1 = i;
            if (i > 0) dp[i] = dp[i - 1];
            for (int j : {last0, last1}) {
                if (j < 0) continue;
                int add = 0;
                vector<int> used(2);
                if (last0 >= j) used[0] = 1;
                if (last1 >= j) used[1] = 1;
                while (add < 2 && used[add]) add++;
                dp[i] = max(dp[i], (j > 0 ? dp[j - 1] : 0) + add);
            }
        }
        cout << dp[n - 1] << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}
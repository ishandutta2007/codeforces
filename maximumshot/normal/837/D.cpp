#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    ll x;

    vec< pii > arr;

    for(int i = 0;i < n;i++) {
        cin >> x;
        int c5 = 0;
        int c2 = 0;
        while(x % 5 == 0) {
            c5++;
            x /= 5;
        }
        while(x % 2 == 0) {
            c2++;
            x /= 2;
        }
        arr.push_back(make_pair(c2, c5));
    }

    int const S2 = 65 * 205;
    int dp[2][205][S2];

    for(int i = 0;i < 2;i++) {
        for(int j = 0;j <= k;j++) {
            for(int x = 0;x < S2;x++) {
                dp[i][j][x] = -inf;
            }
        }
    }

    dp[1][0][0] = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= k;j++) {
            for(int x = 0;x < S2;x++) {
                dp[i % 2][j][x] = -inf;
            }
        }
        for(int j = 0;j <= k;j++) {
            for(int x = 0;x < S2;x++) {
                dp[i % 2][j][x] = dp[(i + 1) % 2][j][x];
                if(j == 0) continue;
                if(x < arr[i].first) continue;
                int tmp = dp[(i + 1) % 2][j - 1][x - arr[i].first];
                if(tmp != -inf) tmp += arr[i].second;
                dp[i % 2][j][x] = max(dp[i % 2][j][x], tmp);
            }
        }
    }

    int r = 0;

    for(int x = 0;x < S2;x++) {
        if(dp[(n - 1) % 2][k][x] == -inf) continue;
        r = max(r, min(x, dp[(n - 1) % 2][k][x]));
    }

    cout << r << "\n";

    return 0;
}
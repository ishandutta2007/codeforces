#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;

int n;
int a[1005];

int main() {

    cin >> n;

    set< int > Q;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i]--;
        Q.insert(a[i]);
    }

    if((int)Q.size() < 8) {
        cout << (int)Q.size() << "\n";
        return 0;
    }

    int dp[1005][256];
    int res = 0;

    for(int mn = 1;mn < 130;mn++) {
        for(int i = 0;i <= n;i++) {
            for(int mask = 0;mask < 256;mask++) {
                dp[i][mask] = -inf;
            }
        }
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++) {
            for(int mask = 0;mask < 256;mask++) dp[i][mask] = dp[i - 1][mask];
            for(int cnt = 0, j = i;j >= 1;j--) {
                if(a[i] != a[j]) continue;
                cnt++;
                // mn .. mn + 1
                if(cnt < mn) continue;
                if(cnt > mn + 1) break;
                for(int now = 0;now < 256;now++) {
                    if(!((now >> a[i]) & 1)) continue;
                    int prv = now ^ (1 << a[i]);
                    dp[i][now] = max(
                        dp[i][now],
                        dp[j - 1][prv] + cnt
                    );
                }
            }
        }
        res = max(res, dp[n][255]);
    }

    cout << res << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;

#define vec vector
#define ALL(x) begin(x), end(x)

const int S = 1e4 + 5;
const int N = 105;
const int inf = 1e9;

int dp[N][S];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;
    vec< int > a(n);

    for(int &x : a) cin >> x;

    sort(ALL(a));


    for(int i = 0;i < N;i++) {
        for(int j = 0;j < S;j++) {
            dp[i][j] = inf;
        }
    }

    for(int x : a) {
        for(int c = n;c > 1;c--) {
            for(int s = S - 1;s >= x;s--) {
                if(dp[c - 1][s - x] == inf) continue;
                dp[c][s] = min(dp[c][s],
                    min(dp[c - 1][s - x], x)
                );
            }
        }
        dp[1][x] = min(dp[1][x], x);
    }

    int res = 0;

    for(int l = 0;l < n;l++) {
        for(int r = l;r < n;r++) {
            if(a[l] != a[r]) break;
            int cnt = r - l + 1;
            int sum = cnt * a[l];
            if(dp[cnt][sum] < a[l]) continue;
            int tmp = cnt;
            if(l > 0) {
                if(r + 1 < n) {
                    if(a[0] == a[n - 1]) {
                        tmp = n;
                    }
                }else {
                    if(a[0] == a[l - 1]) {
                        tmp += l;
                    }
                }
            }else {
                if(r + 1 < n) {
                    if(a[r + 1] == a[n - 1]) {
                        tmp += n - r - 1;
                    }
                }
            }
            res = max(res, tmp);
        }
    }

    cout << res << "\n";

    return 0;
}
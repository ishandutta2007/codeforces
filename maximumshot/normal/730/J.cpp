#include <bits/stdc++.h>

using namespace std;

#define FOR(i, p, n) for (int i = (int)(p); i < (int)(n); ++i)
#define FORD(i, p, n) for (int i = (int)(p); i >= (int)(n); --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf
#define SKP scanf("%*c")

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

int const N = 105;
int const inf = 1000 * 1000 * 1000;

int n;
int a[N];
int b[N];
int crd[N];
int total = 0;
int dp[N][N * N];
int K;
int total_sum_b = 0;

int main() {

    cin >> n;

    for(int i = 1;i <= n;i++) cin >> a[i], total += a[i];
    for(int i = 1;i <= n;i++) cin >> b[i], crd[i - 1] = b[i], total_sum_b += b[i];

    sort(crd, crd + n);
    reverse(crd, crd + n);

    for(int pr = 0, i = 0;i < n;i++) {
        pr += crd[i];
        if(pr >= total) {
            K = i + 1;
            break;
        }
    }

    cout << K << " ";

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N * N;j++)
            dp[i][j] = -inf;
    }

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int sum_b = total_sum_b;sum_b >= b[i];sum_b--) {
            for(int cnt = i;cnt >= 1;cnt--) {
                if(dp[cnt - 1][sum_b - b[i]] != -inf)
                    dp[cnt][sum_b] = max(dp[cnt][sum_b], dp[cnt - 1][sum_b - b[i]] + a[i]);
            }
        }
    }

    int rs = -inf;

    for(int sum_b = total;sum_b <= total_sum_b;sum_b++) {
        rs = max(rs, dp[K][sum_b]);
    }

    cout << total - rs << "\n";

    return 0;
}
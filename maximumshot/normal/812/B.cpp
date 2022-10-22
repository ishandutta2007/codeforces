#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 16;
int const M = 110;

int n, m;
string a[N];
bool have[N];
int dp[2][M];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    int top = -1;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        for(int j = 0;j <= m + 1;j++) {
            if(a[i][j] == '1') {
                have[i] = 1;
            }
        }
        if(top == -1 && have[i]) {
            top = i;
        }
    }

    if(top == -1) {
        puts("0");
        return 0;
    }

    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < M;j++) {
            dp[i][j] = inf;
        }
    }

    dp[0][n + 1] = 0;

    for(int i = n;i >= top;i--) {
        if(!have[i]) {
            dp[0][i] = min(dp[0][i + 1], dp[1][i + 1] + m + 1);
            dp[1][i] = min(dp[1][i + 1], dp[0][i + 1] + m + 1);
        }else {
            int le = -1;
            int ri = -1;
            for(int j = 0;j <= m + 1;j++) {
                if(a[i][j] == '1') {
                    if(le == -1) {
                        le = j;
                    }
                    ri = j;
                }
            }
            dp[0][i] = min(dp[0][i], dp[1][i + 1] + m + 1);
            dp[0][i] = min(dp[0][i], dp[0][i + 1] + 2 * ri);
            dp[1][i] = min(dp[1][i], dp[0][i + 1] + m + 1);
            dp[1][i] = min(dp[1][i], dp[1][i + 1] + 2 * (m + 1 - le));
            if(i == top) {
                cout << min(dp[0][i + 1] + ri, dp[1][i + 1] + (m + 1 - le)) + n - top << "\n";
                return 0;
            }
        }
    }

    return 0;
}
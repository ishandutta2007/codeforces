#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int n, T;
double p[MAXN], r[MAXN], pw[MAXN];
int t[MAXN];
double dp[2][MAXN];

double exp(double b, int e) {
    if (!e) return 1;
    if (e&1) return b*exp(b, e-1);
    double res = exp(b, e/2);
    return res*res;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> T;
    for (int i=0; i<n; i++) {
        int ip;
        cin >> ip >> t[i];
        p[i] = double(ip)/100;

        if (t[i] > 1) {
            pw[i] = exp(1-p[i], t[i]-2);
            r[i] = pw[i]*(1-p[i]);
        }
    }

    double ans = 0;
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        bool b = (i&1)^1;
        if (t[i] == 1 || p[i] == 1) {
            dp[b][0] = 0;
            for (int j=1; j<=T; j++) {
                dp[b][j] = dp[!b][j-1];
                ans += dp[b][j];
            }
        } else {
            double cur = 0;
            for (int j=0, k=-t[i]; j<=T; j++, k++) {
                dp[b][j] = cur;
                ans += dp[b][j];
                if (k>=0) cur -= dp[!b][k]*r[i];
                if (k>=-1) cur -= dp[!b][k+1]*p[i]*pw[i];
                cur = cur*(1-p[i])+dp[!b][j]*p[i];
                if (k>=-1) cur += dp[!b][k+1]*r[i];
            }
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
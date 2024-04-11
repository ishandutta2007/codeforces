#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXL = 1200000;
const double EPS = 1e-10;
const double INF = 1e6;

int n, l, x[MAXN], b[MAXN];
double sq[MAXL], sub[MAXN][MAXN], dp[MAXN];
int par[MAXN];

bool check(double k) {
    for (int i=1; i<=n; i++) dp[i] = -INF;
    dp[0] = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++)
            dp[j] = max(dp[j], dp[i]+k*b[j]-sub[i][j]);
    return dp[n] >= 0;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    for (int i=0; i<MAXL; i++) sq[i] = sqrt(i);

    cin >> n >> l;
    for (int i=1; i<=n; i++) cin >> x[i] >> b[i];

    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++)
            sub[i][j] = sq[abs(x[j]-x[i]-l)];

    double lo = 0, hi = INF;
    while (hi-lo > 10*EPS) {
        double mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid+EPS;
    }

    for (int i=1; i<=n; i++) dp[i] = -INF;
    dp[0] = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++) {
            double res = dp[i]+lo*b[j]-sq[abs(x[j]-x[i]-l)];
            if (res > dp[j])
                dp[j] = res, par[j] = i;
        }

    vector<int> ans;
    int cur = n;
    while (cur) {
        ans.push_back(cur);
        cur = par[cur];
    }

    for (int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << ' ';
    return 0;
}
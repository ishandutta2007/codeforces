#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

bool vis[MAXN][MAXN][MAXN];
double dp[MAXN][MAXN][MAXN];

double calc(int a, int b, int c) {
    if (vis[a][b][c]) return dp[a][b][c];
    vis[a][b][c] = 1;
    double& ret = dp[a][b][c];
    int cnt = int(bool(a)) + int(bool(b)) + int(bool(c));
    if (cnt == 1) {
        if (a) return ret = calc(a-1, b, c);
        else if (b) return ret = calc(a, b-1, c);
        else return ret = calc(a, b, c-1);
    }
    int tot = a*b+b*c+c*a;
    if (a) ret += calc(a-1, b, c) * double(c*a) / tot;
    if (b) ret += calc(a, b-1, c) * double(a*b) / tot;
    if (c) ret += calc(a, b, c-1) * double(b*c) / tot;
    return ret;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i=0; i<3; i++) {
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        vis[1][0][0] = vis[0][1][0] = vis[0][0][1] = 1;
        if (i == 0) dp[1][0][0] = 1;
        else if (i == 1) dp[0][1][0] = 1;
        else dp[0][0][1] = 1;
        
        cout << fixed << setprecision(10) << calc(a, b, c) << ' ';
    }
}
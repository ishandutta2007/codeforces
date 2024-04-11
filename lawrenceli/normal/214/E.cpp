#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int n, mat[MAXN][MAXN];
int dp[2*MAXN][MAXN][MAXN];
int dr[2] = {-1, 0};

int calc(int sum, int r1, int r2) {
    int c1 = sum - r1, c2 = sum - r2;
    if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0) return -INF;
    int& ret = dp[sum][r1][r2];
    if (ret != -INF) return ret;
    ret = -INF;
    int add = mat[r1][c1] + mat[r2][c2];
    if (r1 == r2) add /= 2;
    for (int d1=-1; d1<1; d1++)
        for (int d2=-1; d2<1; d2++)
            ret = max(ret, add + calc(sum-1, r1+d1, r2+d2));

    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mat[i][j];

    for (int i=0; i<2*MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<MAXN; k++)
                dp[i][j][k] = -INF;

    dp[0][0][0] = mat[0][0];

    cout << calc(2*n-2, n-1, n-1) << '\n';
    return 0;
}
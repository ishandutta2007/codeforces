#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 45;

int n, t[3][3];
ll dp[MAXN][3][3];

ll calc(int i, int j, int k) {
    ll& ret = dp[i][j][k];
    if (ret != -1) return ret;
    int l;
    for (int ii=0; ii<3; ii++)
        if (ii != j && ii != k)
            l = ii;

    ret = calc(i-1, j, l) + t[j][k] + calc(i-1, l, k);
    ret = min(ret, 2*calc(i-1, j, k) + calc(i-1, k, j) + t[j][l] + t[l][k]);
    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> t[i][j];
    cin >> n;

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            dp[0][i][j] = 0;

    cout << calc(n, 0, 2) << '\n';
    return 0;
}
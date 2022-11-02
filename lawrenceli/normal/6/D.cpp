#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int INF = int(1e9);

int n, a, b;
int h[15];
int dp[15][20][20]; //pos, health1, health2
piii par[15][20][20]; //backtracking

int _div(int a, int b) { //ceiling of a / b
    if (!a) return 0;
    return (a-1) / b + 1;
}

int calc(int pos, int h1, int h2) {
    int& ret = dp[pos][h1][h2];
    if (ret != -1) return ret;

    ret = INF;

    for (int i=0; i<=h[pos-1]; i++)
        for (int j=0; j<=h[pos]; j++) {
            if (j < h1) continue; //can't increase health
            int num = 0;
            num = max(num, _div(i, b));
            num = max(num, _div(j - h1, a));
            num = max(num, _div(h[pos+1] - h2, b));
            int res = calc(pos-1, i, j) + num;
            if (res < ret)
                ret = res, par[pos][h1][h2] = piii(pii(i, j), num);
        }

    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        cin >> h[i]; h[i] ++;
    }

    memset(dp, -1, sizeof(dp));
    for (int i=0; i<20; i++)
        for (int j=0; j<20; j++)
            dp[0][i][j] = INF;

    dp[0][h[0]][h[1]] = 0;

    cout << calc(n-2, 0, 0) << endl;

    int pos = n-2, h1 = 0, h2 = 0;
    while (pos > 0) {
        piii nxt = par[pos][h1][h2];
        for (int i=0; i<nxt.se; i++)
            cout << pos+1 << ' ';

        pos --, h1 = nxt.fi.fi, h2 = nxt.fi.se;
    }

    return 0;
}
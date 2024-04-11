#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MAXK = 15;
const int INF = 1e9;

int N, M, K;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN][MAXK], from[MAXN][MAXN][MAXK];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            char c; cin >> c;
            mat[i][j] = c-'0';
        }

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            for (int k=0; k<K+1; k++)
                dp[i][j][k] = -INF;

    for (int i=0; i<M; i++)
        dp[N-1][i][mat[N-1][i]%(K+1)] = mat[N-1][i];

    for (int i=N-1; i>0; i--)
        for (int k=0; k<K+1; k++)
            for (int j=0; j<M; j++)
                for (int dc=-1; dc<=1; dc+=2) {
                    int j1 = j+dc;
                    if (j1>=0 && j1<M) {
                        int res = dp[i][j][k]+mat[i-1][j1];
                        if (res > dp[i-1][j1][res%(K+1)])
                            dp[i-1][j1][res%(K+1)] = res, from[i-1][j1][res%(K+1)] = j;
                    }
                }

    int r = 0, c = -1, v = -INF;
    string s = "";
    for (int i=0; i<M; i++)
        if (dp[0][i][0] > v)
            v = dp[0][i][0], c = i;
    if (v < 0) {
        cout << "-1\n";
        return 0;
    }
    cout << v << '\n';
    while (r<N-1) {
        int nc = from[r][c][v%(K+1)];
        v -= mat[r][c];
        if (nc+1 == c) s = 'R' + s;
        else s = 'L' + s;
        c = nc;
        r++;
    }
    cout << c+1 << '\n' << s << '\n';
    return 0;
}
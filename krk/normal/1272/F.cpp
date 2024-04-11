#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Maxm = 408;
const int Inf = 1000000000;

string A, B;
int dp[Maxn][Maxn][Maxm];
bool par[Maxn][Maxn][Maxm];
ii wth[Maxn][Maxn][Maxm];

void Solve(int i, int j, int k)
{
    if (dp[i][j][k] == 0) return;
    ii prv = wth[i][j][k];
    int nk = par[i][j][k]? k - 1: k + 1;
    Solve(prv.first, prv.second, nk);
    if (par[i][j][k]) printf("(");
    else printf(")");
}

int main()
{
    cin >> A >> B;
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxm, Inf);
    dp[0][0][0] = 0;
    for (int i = 0; i <= A.length(); i++)
        for (int j = 0; j <= B.length(); j++) {
            for (int k = 0; k < Maxm; k++) if (dp[i][j][k] < Inf) {
                if (k + 1 < Maxm) {
                    int ni = i < A.length() && A[i] == '('? i + 1: i;
                    int nj = j < B.length() && B[j] == '('? j + 1: j;
                    if (dp[ni][nj][k + 1] > dp[i][j][k] + 1) {
                        dp[ni][nj][k + 1] = dp[i][j][k] + 1;
                        par[ni][nj][k + 1] = true;
                        wth[ni][nj][k + 1] = ii(i, j);
                    }
                }
                if (k > 0) {
                    int ni = i < A.length() && A[i] == ')'? i + 1: i;
                    int nj = j < B.length() && B[j] == ')'? j + 1: j;
                    if (dp[ni][nj][k - 1] > dp[i][j][k] + 1) {
                        dp[ni][nj][k - 1] = dp[i][j][k] + 1;
                        par[ni][nj][k - 1] = false;
                        wth[ni][nj][k - 1] = ii(i, j);
                    }
                }
            }
            for (int k = Maxm - 1; k >= 0; k--) if (dp[i][j][k] < Inf) {
                if (k + 1 < Maxm) {
                    int ni = i < A.length() && A[i] == '('? i + 1: i;
                    int nj = j < B.length() && B[j] == '('? j + 1: j;
                    if (dp[ni][nj][k + 1] > dp[i][j][k] + 1) {
                        dp[ni][nj][k + 1] = dp[i][j][k] + 1;
                        par[ni][nj][k + 1] = true;
                        wth[ni][nj][k + 1] = ii(i, j);
                    }
                }
                if (k > 0) {
                    int ni = i < A.length() && A[i] == ')'? i + 1: i;
                    int nj = j < B.length() && B[j] == ')'? j + 1: j;
                    if (dp[ni][nj][k - 1] > dp[i][j][k] + 1) {
                        dp[ni][nj][k - 1] = dp[i][j][k] + 1;
                        par[ni][nj][k - 1] = false;
                        wth[ni][nj][k - 1] = ii(i, j);
                    }
                }
            }
        }
    Solve(A.length(), B.length(), 0);
    printf("\n");
    return 0;
}
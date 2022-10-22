#include <bits/stdc++.h>
using namespace std;

const int Maxm = 1005;
const int Maxn = 52;
const int Maxl = 26;
const int Inf = 1000000000;

string C;
string A, B;
int nxt1[Maxn][Maxl], nxt2[Maxn][Maxl];
bool term1[Maxn], term2[Maxn];
int dp[Maxm][Maxn][Maxn];

void Prepare(const string &S, int nxt[][Maxl], bool term[])
{
    term[S.length()] = true;
    for (int i = 0; i <= S.length(); i++) {
        for (int j = 0; j < Maxl; j++) {
            string my = S.substr(0, i) + string(1, 'a' + j);
            int z = min(my.length(), S.length());
            while (z > 0 && S.substr(0, z) != my.substr(int(my.length()) - z))
                z--;
            nxt[i][j] = z;
        }
    }
}

int main()
{
    cin >> C;
    cin >> A >> B;
    Prepare(A, nxt1, term1);
    Prepare(B, nxt2, term2);
    fill((int*)dp, (int*)dp + Maxm * Maxn * Maxn, -Inf);
    dp[0][0][0] = 0;
    for (int i = 0; i < C.length(); i++)
        for (int j = 0; j <= A.length(); j++)
            for (int k = 0; k <= B.length(); k++) if (dp[i][j][k] > -Inf)
                for (int l = 0; l < Maxl; l++) if (C[i] == '*' || C[i] == 'a' + l) {
                    int nj = nxt1[j][l], nk = nxt2[k][l];
                    int cand = dp[i][j][k];
                    if (term1[nj]) cand++;
                    if (term2[nk]) cand--;
                    dp[i + 1][nj][nk] = max(dp[i + 1][nj][nk], cand);
                }
    int res = -Inf;
    for (int j = 0; j <= A.length(); j++)
        for (int k = 0; k <= B.length(); k++)
            res = max(res, dp[C.length()][j][k]);
    printf("%d\n", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;
const int Maxm = 252;

int n, q;
char str[Maxn];
int nxt[Maxn][Maxl];
vector <int> V[3];
int dp[Maxm][Maxm][Maxm];

void Forw(int a, int b, int c)
{
    for (int i = a; i <= V[0].size(); i++)
        for (int j = b; j <= V[1].size(); j++)
            for (int k = c; k <= V[2].size(); k++) if (dp[i][j][k] < Maxn) {
                int p = dp[i][j][k];
                if (i + 1 <= V[0].size() && nxt[p + 1][V[0][i]] < Maxn)
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], nxt[p + 1][V[0][i]]);
                if (j + 1 <= V[1].size() && nxt[p + 1][V[1][j]] < Maxn)
                    dp[i][j + 1][k] = min(dp[i][j + 1][k], nxt[p + 1][V[1][j]]);
                if (k + 1 <= V[2].size() && nxt[p + 1][V[2][k]] < Maxn)
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], nxt[p + 1][V[2][k]]);
            }
}

void Backw(int a, int b, int c)
{
    for (int i = a; i <= V[0].size(); i++)
        for (int j = b; j <= V[1].size(); j++)
            for (int k = c; k <= V[2].size(); k++)
                dp[i][j][k] = Maxn;
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str);
    for (int j = 0; j < Maxl; j++)
        nxt[n][j] = Maxn;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < Maxl; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][str[i] - 'a'] = i;
    }
    fill((int*)dp, (int*)dp + Maxm * Maxm * Maxm, Maxn);
    dp[0][0][0] = -1;
    while (q--) {
        char typ; int ind; scanf(" %c %d", &typ, &ind); ind--;
        if (typ == '+') {
            char ch; scanf(" %c", &ch);
            V[ind].push_back(ch - 'a');
            if (ind == 0) Forw(int(V[0].size()) - 1, 0, 0);
            else if (ind == 1) Forw(0, int(V[1].size()) - 1, 0);
            else if (ind == 2) Forw(0, 0, int(V[2].size()) - 1);
        } else {
            if (ind == 0) Backw(V[0].size(), 0, 0);
            else if (ind == 1) Backw(0, V[1].size(), 0);
            else if (ind == 2) Backw(0, 0, V[2].size());
            V[ind].pop_back();
        }
        printf("%s\n", dp[V[0].size()][V[1].size()][V[2].size()] < n? "YES": "NO");
    }
    return 0;
}
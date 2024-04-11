#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

ld C[Maxn][Maxn];
int n, m;
vector <int> my[Maxn];
int has[Maxn];
bool extr[Maxn];
map <int, vector <int> > M;
ld dp[Maxn][Maxn];

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int siz; scanf("%d", &siz);
        my[i].resize(siz);
        for (int j = 0; j < siz; j++) {
            scanf("%d", &my[i][j]);
            M[my[i][j]].push_back(i);
        }
    }
    int N = 0;
    for (auto it = M.rbegin(); it != M.rend(); it++)
        if (it->second.size() <= n) {
            n -= it->second.size();
            for (int i = 0; i < it->second.size(); i++)
                has[it->second[i]]++;
        } else {
            N = it->second.size();
            for (int i = 0; i < it->second.size(); i++)
                extr[it->second[i]] = true;
            break;
        }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= n; j++)
            if (!extr[i])
                dp[i + 1][j] += dp[i][j] / C[my[i].size()][has[i]];
            else {
                dp[i + 1][j] += dp[i][j] / C[my[i].size()][has[i]];
                if (j < n)
                    dp[i + 1][j + 1] += dp[i][j] / ld(N - j) * ld(n - j) / C[my[i].size()][has[i] + 1];
            }
    cout << fixed << setprecision(12) << dp[m][n] << endl;
    return 0;
}
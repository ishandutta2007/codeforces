#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;

const int Maxn = 10;

vector <ii> seq;
int H[Maxn][Maxn];
ld dp[Maxn][Maxn];

int main()
{
    for (int i = 0; i < Maxn; i++)
        if (i % 2 == 0)
            for (int j = 0; j < Maxn; j++)
                seq.push_back(ii(i, j));
        else for (int j = Maxn - 1; j >= 0; j--)
                seq.push_back(ii(i, j));
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            scanf("%d", &H[i][j]);
    for (int i = 1; i < seq.size(); i++) {
        ii rc = seq[i];
        ld coef = 0, val = 0;
        for (int j = 1; j <= 6; j++)
            if (j <= i) {
                ii c1 = ii(seq[i - j]);
                ii c2 = ii(c1.first - H[c1.first][c1.second], c1.second);
                val += ld(1 + min(dp[c1.first][c1.second], dp[c2.first][c2.second])) / 6.0l;
            } else { val += 1.0l / 6.0l; coef += 1.0l / 6.0l; }
        dp[rc.first][rc.second] = val / (1.0l - coef);
    }
    cout << fixed << setprecision(10) << dp[Maxn - 1][0] << endl;
    return 0;
}
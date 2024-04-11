#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 12;
const int Maxd = 2;

int T;
string n;
ll dp[Maxn][Maxd][Maxd];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        reverse(n.begin(), n.end());
        fill((ll*)dp, (ll*)dp + Maxn * Maxd * Maxd, 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < n.length(); i++)
            for (int c1 = 0; c1 < Maxd; c1++)
                for (int c2 = 0; c2 < Maxd; c2++) if (dp[i][c1][c2])
                    for (int a = 0; a < 10; a++)
                        for (int b = 0; b < 10; b++) {
                            int r = a + b + c1;
                            if (n[i] != r % 10 + '0') continue;
                            dp[i + 1][c2][r / 10] += dp[i][c1][c2];
                        }
        cout << dp[n.length()][0][0] - 2ll << endl;
    }
    return 0;
}
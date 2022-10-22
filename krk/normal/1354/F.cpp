#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef long long ll;

const int Maxn = 77;
const int Inf = 2000000005;

int T;
int n, k;
iii ba[Maxn];
int dp[Maxn][Maxn];
bool par[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ba[i].first.second, &ba[i].first.first);
            ba[i].second = i + 1;
        }
        sort(ba, ba + n);
        fill((int*)dp, (int*)dp + Maxn * Maxn, -Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++) if (dp[i][j] >= 0) {
                int cand = dp[i][j] + (k - 1) * ba[i].first.first;
                if (cand > dp[i + 1][j]) {
                    dp[i + 1][j] = cand;
                    par[i + 1][j] = false;
                }
                cand = dp[i][j] + ba[i].first.first * j + ba[i].first.second;
                if (cand > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = cand;
                    par[i + 1][j + 1] = true;
                }
            }
        vector <int> imp, notimp;
        int i = n, j = k;
        while (i > 0) {
            if (!par[i][j])
                notimp.push_back(ba[i - 1].second);
            else {
                imp.push_back(ba[i - 1].second);
                j--;
            }
            i--;
        }
        reverse(imp.begin(), imp.end());
        vector <int> res;
        for (int i = 0; i < k - 1; i++)
            res.push_back(imp[i]);
        for (int i = 0; i < notimp.size(); i++) {
            res.push_back(notimp[i]);
            res.push_back(-notimp[i]);
        }
        res.push_back(imp[k - 1]);
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
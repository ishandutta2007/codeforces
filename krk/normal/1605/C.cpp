#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 2000015;

int T;
int n;
char str[Maxn];
ii dp[Maxn];
vector <ii> BIT[Maxm];
int m;

void Insert(const ii &p, int val)
{
    for (int i = p.first + n + 1; i < m; i += i & -i) {
        while (!BIT[i].empty() && BIT[i].back().first >= p.second)
            BIT[i].pop_back();
        BIT[i].push_back(ii(p.second, val));
    }
}

int Get(const ii &p)
{
    int res = -1;
    for (int i = p.first + n; i > 0; i -= i & -i) {
        int ind = lower_bound(BIT[i].begin(), BIT[i].end(), ii(p.second, 0)) - BIT[i].begin() - 1;
        if (ind >= 0) res = max(res, BIT[i][ind].second);
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        m = 2 * n + 5;
        for (int i = 0; i < m; i++)
            BIT[i].clear();
        dp[0] = ii(0, 0);
        int res = Maxn;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (str[i] == 'a') { dp[i].first++; dp[i].second++; }
            else if (str[i] == 'b') dp[i].first--;
            else if (str[i] == 'c') dp[i].second--;
            int got = Get(dp[i]);
            if (got != -1) res = min(res, i - got);
            Insert(dp[i - 1], i - 1);
        }
        printf("%d\n", res < Maxn? res: -1);
    }
    return 0;
}
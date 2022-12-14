#include <cstdio>
#include <queue>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXD = 505, MAXS = 5005;
typedef pair<int, int> pii;
int d, s;
int dp[MAXS][MAXD];
pii tr[MAXS][MAXD];
queue<pii> q;
int main()
{
    scanf("%d%d", &d, &s);
    memset(tr, 0xff, sizeof(tr));
    memset(dp, 0xff, sizeof(dp));
    for (int i = 1; i <= 9; ++i) {
        if (i == s && i % d == 0) {
            printf("%d\n", i);
            return 0;
        }
        dp[i][i % d] = i;
        q.emplace(i, i % d);
    }
    bool ok = false;
    while (!q.empty() && !ok) {
        pii fr = q.front();
        q.pop();
        for (int i = 0; i <= 9; ++i) {
            int x = fr.first + i;
            if (x >= MAXS || x > s)
                continue;
            int y = (fr.second * 10 % d + i) % d;
            if (dp[x][y] != -1)
                continue;
            if (x == s && y == 0)
                ok = true;
            dp[x][y] = i;
            tr[x][y] = fr;
            q.emplace(x, y);
        }
    }
    if (!ok) {
        puts("-1");
        return 0;
    }
    vector<int> ans;
    int x = s, y = 0;
    while (x != -1) {
        ans.push_back(dp[x][y]);
        int x2 = tr[x][y].first, y2 = tr[x][y].second;
        x = x2, y = y2;
    }
    for (auto i = ans.rbegin(); i != ans.rend(); ++i)
        printf("%d", *i);
    putchar('\n');
    return 0;
}
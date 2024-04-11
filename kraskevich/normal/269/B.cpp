#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;


const int N = 5000 + 10;
const int inf = 1000 * 1000;
int dp[N][N];
vector<int> at_type[N];
int n, m;

void solve()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = inf;
    dp[0][0] = 0;


    scanf("%d%d", & n, & m);
    for (int i = 0; i < n; ++i)
    {
        int type;
        double x;
        scanf("%d%lf", & type, & x);
        at_type[type].push_back(i + 1);
    }

    for (int type = 1; type <= m; ++type)
    {
        for (int i = 1; i <= n; ++i)
           dp[type - 1][i] = min(dp[type - 1][i], dp[type - 1][i - 1]);
        for (int start = 0; start < at_type[type].size(); ++start)
            for (int fin = start; fin < at_type[type].size(); ++fin)
            {
                int sx = at_type[type][start];
                int fx = at_type[type][fin];
                dp[type][fx] = min(dp[type][fx], dp[type - 1][sx] + start + (int)at_type[type].size() - 1 - fin);
            }
        for (int x = 0; x <= n; ++x)
            dp[type][x] = min(dp[type][x], dp[type - 1][x] + (int)at_type[type].size());
    }

    printf("%d", *min_element(dp[m], dp[m] + n + 1));
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}
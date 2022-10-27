#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 1e7 + 10;
using ll = long long;
const ll INF = 1e18 + 7;
ll dp[M];
int h[M];
ll cost[M];
int tot;
int n, m;
int qsize;
vector <int> block_h[N];
vector <int> block_cost[N];
int l[M];
int r[M];
int st[M];
int top = 0;
pair <long long, int> stk[M];

int main () {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        int k;
        scanf("%d", &k);
        block_h[i].resize(k);
        block_cost[i].resize(k);
        for (int &j : block_h[i])
            scanf("%d", &j);
        for (int &j : block_cost[i])
            scanf("%d", &j);
    }

    scanf("%d", &qsize);

    for (; qsize -- ;) {
        int id, mul;
        scanf("%d %d", &id, &mul);
        for (int j = 0 ; j < int(block_cost[id].size()) ; ++ j) {
            ++ tot;
            cost[tot] = 1LL * mul * block_cost[id][j];
            h[tot] = block_h[id][j];
        }
    }


    for (int i = m ; i >= 1 ; -- i) {
        while (top > 0 && st[top] - h[st[top]] >= i) {
            l[st[top]] = i;
            -- top;
        }
        st[++ top] = i;
    }
    while (top > 0) l[st[top --]] = 0;

    for (int i = 1 ; i <= m ; ++ i) {
        while (top > 0 && st[top] + h[st[top]] <= i) {
            r[st[top]] = i;
            -- top;
        }
        st[++ top] = i;
    }

    while (top > 0) r[st[top --]] = m + 1;

    stk[++ top] = make_pair(INF, int(1e8));

    for (int i = 1 ; i <= m ; ++ i) {
        dp[i] = min(dp[l[i]] + cost[i], stk[top].first);
        dp[i] = min(dp[i], INF);
        while (stk[top].second <= i) -- top;
        if (dp[i - 1] + cost[i] < stk[top].first && r[i] - 1 > i) stk[++ top] = make_pair(dp[i - 1] + cost[i], r[i] - 1);
    }

    printf("%lld\n", dp[m]);
}
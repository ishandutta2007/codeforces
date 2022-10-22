#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int Inf = 1000000000;

int n, c;
int a[Maxn], b[Maxn];
int dp[Maxn][2];
priority_queue <iii> Q;

void checkPos(const ii &u, int cand)
{
    if (cand < dp[u.first][u.second]) {
        dp[u.first][u.second] = cand;
        Q.push(iii(-dp[u.first][u.second], u));
    }
}

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 1; i + 1 <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i + 1 <= n; i++)
        scanf("%d", &b[i]);
    fill((int*)dp, (int*)dp + Maxn * 2, Inf);
    dp[1][0] = 0;
    Q.push(iii(-dp[1][0], ii(1, 0)));
    while (!Q.empty()) {
        int d = -Q.top().first;
        ii v = Q.top().second; Q.pop();
        if (dp[v.first][v.second] != d) continue;
        if (v.second) {
            checkPos(ii(v.first, 0), d);
            if (v.first < n) checkPos(ii(v.first + 1, 1), d + b[v.first]);
            if (v.first > 1) checkPos(ii(v.first - 1, 1), d + b[v.first - 1]);
        } else {
            checkPos(ii(v.first, 1), d + c);
            if (v.first < n) checkPos(ii(v.first + 1, 0), d + a[v.first]);
            if (v.first > 1) checkPos(ii(v.first - 1, 0), d + a[v.first - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", dp[i][0], i + 1 <= n? ' ': '\n');
    return 0;
}
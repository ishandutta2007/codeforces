#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxm = 10;
const int Maxd = 4;

ll dp[Maxn][Maxm];
int n;
int best[Maxd][3];

void Insert(int best[], int x)
{
    if (x > best[0]) best[2] = best[1], best[1] = best[0], best[0] = x;
    else if (x > best[1]) best[2] = best[1], best[1] = x;
    else if (x > best[2]) best[2] = x;
}

void Play(int r, int c, vector <ii> V)
{
    do {
        ll mx = dp[r][c];
        int cur = c;
        for (int i = 0; i < V.size(); i++) {
            cur++;
            if (cur >= Maxm) { mx += 2 * V[i].second; cur = 0; }
            else mx += V[i].second;
        }
        dp[r + 1][cur] = max(dp[r + 1][cur], mx);
    } while (next_permutation(V.begin(), V.end()));
}

int main()
{
    fill((ll*)dp, (ll*)dp + Maxn * Maxm, -Inf);
    dp[0][0] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        fill((int*)best, (int*)best + Maxd * 3, 0);
        int k; scanf("%d", &k);
        while (k--) {
            int c, d; scanf("%d %d", &c, &d);
            Insert(best[c], d);
        }
        for (int j = 0; j < Maxm; j++) if (dp[i][j] >= 0) {
            Play(i, j, {});
            if (best[3][0] > 0) Play(i, j, {ii(0, best[3][0])});
            if (best[2][0] > 0) Play(i, j, {ii(0, best[2][0])});
            if (best[1][0] > 0) Play(i, j, {ii(0, best[1][0])});
            if (best[2][0] > 0 && best[1][0] > 0) Play(i, j, {ii(0, best[2][0]), ii(1, best[1][0])});
            if (best[1][0] > 0 && best[1][1] > 0) Play(i, j, {ii(0, best[1][0]), ii(1, best[1][1])});
            if (best[1][0] > 0 && best[1][1] > 0 && best[1][2] > 0)
                Play(i, j, {ii(0, best[1][0]), ii(1, best[1][1]), ii(2, best[1][2])});
        }
    }
    ll mx = 0;
    for (int j = 0; j < Maxm; j++)
        mx = max(mx, dp[n][j]);
    cout << mx << endl;
    return 0;
}
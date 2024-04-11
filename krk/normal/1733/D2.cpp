#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const ll Inf = 1000000000000000000ll;

int T;
int n, x, y;
char A[Maxn];
char B[Maxn];
vector <int> seq;
ll dp[Maxn][Maxn];

ll solveGreedy()
{
    if (seq.empty() || seq.size() > 2 || seq[1] - seq[0] > 1) return ll(y) * ll(seq.size() / 2);
    if (seq[0] >= 2 || seq[1] + 2 < n) return min(ll(x), 2ll * y);
    else if (seq[0] >= 1 && seq[1] + 1 < n) return min(ll(x), 3ll * y);
    else return x;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);
        scanf("%s", A);
        scanf("%s", B);
        seq.clear();
        for (int i = 0; i < n; i++)
            if (A[i] != B[i])
                seq.push_back(i);
        if (seq.size() % 2) { printf("-1\n"); continue; }
        if (x >= y) { printf("%I64d\n", solveGreedy()); continue; }
        for (int i = 0; i <= seq.size(); i++)
            for (int j = 0; j <= i; j++)
                dp[i][j] = Inf;
        dp[0][0] = 0;
        for (int i = 0; i < seq.size(); i++)
            for (int j = 0; j <= i; j++) if (dp[i][j] < Inf) {
                if (i + 1 < seq.size())
                    dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + ll(x) * (seq[i + 1] - seq[i]));
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
        ll res = Inf;
        for (int j = 0; j <= seq.size(); j++)
            res = min(res, dp[seq.size()][j] + ll(j / 2) * y);
        printf("%I64d\n", res);
    }
    return 0;
}
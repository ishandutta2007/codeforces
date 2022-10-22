#include <bits/stdc++.h>
using namespace std;

const int Maxn = 8192;
const int Inf = 1000000000;

int n;
int dp[Maxn];
int my[Maxn][Maxn], mlen[Maxn];

void Check(int val, int best)
{
    if (dp[val] <= best) return;
    if (dp[val] >= Inf)
        dp[val] = Maxn - 1;
    while (dp[val] > best) {
        my[dp[val]][mlen[dp[val]]++] = val;
        dp[val]--;
    }
}

int main()
{
    scanf("%d", &n);
    fill(dp, dp + Maxn, Inf);
    Check(0, 0);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        while (mlen[a] > 0) {
            int lst = my[a][--mlen[a]];
            Check((lst ^ a), a);
        }
    }
    vector <int> res;
    for (int i = 0; i < Maxn; i++)
        if (dp[i] < Inf)
            res.push_back(i);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}
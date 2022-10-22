#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int mn;
map <int, int> M;
int dp[Maxn];

void Set(int key, int val)
{
    mn = min(mn, val);
    auto it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, val));
    else it->second = min(it->second, val);
}

int Get(int key)
{
    auto it = M.find(key);
    return it == M.end()? Inf: it->second;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        M.clear();
        mn = Inf;
        int cur = 0;
        fill(dp, dp + n + 1, Inf);
        dp[0] = 0;
        Set(cur, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + int(a[i] != 0));
            cur ^= a[i];
            dp[i + 1] = min(dp[i + 1], min(Get(cur) + i, mn + i + 1));
            Set(cur, dp[i + 1] - (i + 1));
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
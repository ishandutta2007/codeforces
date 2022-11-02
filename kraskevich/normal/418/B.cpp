#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const long long INF = (long long)2e18 + 100ll;
const int N = 20;

long long dp[1 << N];
int n, m;
long long b;

struct man {
    long long k, x;
    int mask;
};

man f[111];

bool cmp(man a, man b)
{
    return a.k < b.k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
    {
        f[i].mask = 0;
        cin >> f[i].x >> f[i].k;
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++){
            int x;
            cin >> x;
            x--;
            f[i].mask |= (1 << x);
        }
    }
    sort(f, f + n, cmp);
    long long res = INF;
    for (int i = 0; i < (1 << m); i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int pos = 0; pos < n; pos++) {
        for (int mask = 0; mask < (1 << m); mask++)
            dp[mask | f[pos].mask] = min(dp[mask | f[pos].mask], dp[mask] + f[pos].x);
        int a = (1 << m) - 1;
        if (dp[a] < INF)
            res = min(res, dp[a] + f[pos].k * b);
    }
    if (res == INF)
        res = -1;
    cout << res;

    return 0;
}
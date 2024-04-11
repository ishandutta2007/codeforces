#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;

const int N = 100 * 1000 + 5;
const int LEN = 305;

int a[N];
vector<int> at[N];
int ptr[N];
int n, m, s, e;
int res = 0;
int dp[N][LEN];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        at[x].push_back(i);
    }
    fill(ptr, ptr + N, 0);
    for (int pos = 0; pos < N; pos++)
        for (int len = 0; len < LEN; len++)
            dp[pos][len] = N;
    dp[0][0] = 0;
    for (int pos = 1; pos <= n; pos++) {
        for (int len = 0; len < LEN; len++)
            dp[pos][len] = dp[pos - 1][len];
        for (int len = 1; len < LEN; len++)
        {
            int j = dp[pos - 1][len - 1];
            int v = upper_bound(at[a[pos]].begin(), at[a[pos]].end(), j) - at[a[pos]].begin();
            if (v == at[a[pos]].size())
                continue;
            dp[pos][len] = min(dp[pos][len], at[a[pos]][v]);
        }
    }
    for (int pos = 1; pos <= n; pos++)
        for (int len = 1; len < LEN; len++)
        {
            if (dp[pos][len] == N)
                continue;
            if (pos + dp[pos][len] + e * len <= s)
                res = max(res, len);
        }
    cout << res;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;
const int N = 5555;
set<int> bad;
int a[N];
int dp[N];
int g[N];

int func(int n)
{
    int res = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            int delta = bad.count(i) ? -1 : 1;
            while (n % i == 0)
            {
                n /= i;
                res += delta;
            }
        }
    if (n > 1)
    {
        if (bad.count(n))
            res--;
        else
            res++;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int pr;
        cin >> pr;
        bad.insert(pr);
    }
    fill(dp, dp + n + 1, 0);
    dp[0] = 0;
    g[0] = a[0];
    for (int i = 1; i < n; i++)
        g[i] = __gcd(a[i], g[i - 1]);
    for (int i = 0; i < n; i++)
        g[i] = func(g[i]);
    for (int i = 0; i < n; i++)
        cerr << g[i] << " ";
    cerr << endl;
    reverse(a, a + n);
    reverse(g, g + n);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            dp[j + 1] = max(dp[j + 1], dp[i] - g[i] * (j - i + 1));
    /*for (int i = 0; i < n; i++)
        cerr << dp[i] << " ";
    cerr << endl;*/
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i] - g[i] * (n - i));
    int add = 0;
    for (int i = 0; i < n; i++)
        add += func(a[i]);
    cout << res + add;

    return 0;
}
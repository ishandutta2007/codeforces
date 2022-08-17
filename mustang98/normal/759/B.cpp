#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int n;
vector<int> t;
int dp[max_n];
bool vis[max_n];

int f(int cur)
{
    if (cur == -1)
    {
        return 0;
    }
    if (vis[cur])
    {
        return dp[cur];
    }
    int ans1, ans2, ans3;
    ans1 = 20 + f(cur - 1);
    int time2 = t[cur] - 90 + 1;
    int prev2 = lower_bound(t.begin(), t.end(), time2) - t.begin() - 1;
    ans2 = 50 + f(prev2);

    int time3 = t[cur] - 1440 + 1;
    int prev3 = lower_bound(t.begin(), t.end(), time3) - t.begin() - 1;
    ans3 = 120 + f(prev3);

    int ans = min(ans1, min(ans2, ans3));
    dp[cur] = ans;
    vis[cur] = true;
    return ans;
}

int main()
{
    //ifstream cin("input.txt");
    scanf("%d", &n);
    int a;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        t.push_back(a);
    }
    f(n - 1);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", dp[i] - sum);
        sum = dp[i];
    }
}
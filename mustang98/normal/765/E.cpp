#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;

vector<int> v[max_n];
vector<int> ch[max_n];
int dp[max_n];
int root, rd = 1;

int dfs1(int cur, int pr)
{
    //cout << cur + 1 << endl;
    if (v[cur].size() == 1)
    {
        dp[cur] = 1;
        return 1;
    }
    for (int to : v[cur])
    {
        if (to == pr) continue;
        dfs1(to, cur);
    }
    int res1 = -1, res2 = -1;
    bool ismin = false;
    for (int to : v[cur])
    {
        if (to == pr) continue;
        int val = dp[to];
        if (val == -1)
        {
            if (ismin)
            {
                cout << -1;
                exit(0);
            }
            ismin = true;
            continue;
        }
        if (val == res1 || val == res2) continue;
        if (res1 == -1)
        {
            res1 = val;
            continue;
        }
        if (res2 == -1)
        {
            res2 = val;
            continue;
        }
        cout << -1;
        exit(0);
    }
    if (ismin && res1 != -1 && res2 != -1)
    {
        cout << -1;
        exit(0);
    }
    if (ismin)
    {
        dp[cur] = -1;
        return -1;
    }
    if (res2 == -1)
    {
        dp[cur] = res1 + 1;
    }
    else
    {
        dp[cur] = -1;
    }
    return dp[cur];
}

int ans = -1;
void dfs2(int cur, int pr, int dep)
{
    if (v[cur].size() == 1)
    {
        ans = dep + 1;
        return;
    }
    int min1 = -1, res1 = -1, res2 = -1;
    for (int to : v[cur])
    {
        if (to == pr) continue;
        int val = dp[to];
        if (val == -1)
        {
            min1 = to;
            continue;
        }
        if (val == res1 || val == res2) continue;
        if (res1 == -1)
        {
            res1 = val;
            continue;
        }
        if (res2 == -1)
        {
            res2 = val;
            continue;
        }
    }
    if (min1 == -1)
    {
        if (res2 == -1 || res2 == dep)
        {
            ans = res1 + dep + 1;
            return;
        }
        if (res1 == dep)
        {
            ans = res2 + dep + 1;
            return;
        }
        cout << -1;
        exit(0);
    }
    if (res1 == -1 || res1 == dep)
    {
        dfs2(min1, cur, dep + 1);
        return;
    }
    cout << -1;
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    for (int i = 0; i < n; ++i)
    {
        if (v[i].size() == 1)
        {
            root = i;
            break;
        }
    }
    dfs1(v[root][0], root);
    /*for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ' ' << dp[i] << endl;
    }*/
    dfs2(v[root][0], root, 1);
    ans--;
    while(ans % 2 == 0)
    {
        ans /= 2;
    }
    cout << ans << endl;
    return 0;
}
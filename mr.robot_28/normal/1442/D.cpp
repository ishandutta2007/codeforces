#include<bits/stdc++.h>
using namespace std;
int n, k;
vector <vector <int> > t;
vector <long long> sum;
long long ans = 0;
long long max(long long a, long long b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}
void build(int l, int r, long long *dp1)
{
    if(l == r)
    {
        long long sum1 = 0;
        ans = max(ans, dp1[k]);
        for(int i = 0; i < min(k, t[l].size()); i++)
        {
            sum1 += t[l][i];
            ans = max(ans, sum1 + dp1[k - i - 1]);
        }
        return;
    }
    long long dp3[k + 1];
    long long dp4[k + 1];
    for(int i = 0; i <= k; i++)
    {
        dp3[i] = dp4[i] = dp1[i];
    }
    int midd = (r + l) / 2;
    for(int j = l; j <= midd; j++)
    {
        if(t[j].size() <= k)
        {
        for(int p = k - t[j].size(); p >= 0; p--)
        {
            dp3[p + t[j].size()] = max(dp3[p + t[j].size()], dp3[p] + sum[j]);
        }
        }
    }
    build(midd + 1, r, dp3);
    for(int j = r; j > midd; j--)
    {
        if(t[j].size() <= k)
        {
        for(int p = k - t[j].size(); p >= 0; p--)
        {
            dp4[p + t[j].size()] = max(dp4[p + t[j].size()], dp4[p] + sum[j]);
        }
        }
    }
    build(l, midd, dp4);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    t.resize(n);
    sum.resize(n);
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        sum[i] = 0;
        t[i].resize(c);
        for(int j = 0; j < c; j++)
        {
            cin >> t[i][j];
            sum[i] += t[i][j];
        }
    }
    long long dp1[k + 1];
    for(int i = 0; i <= k; i++)
    {
        dp1[i] = -1e14;
    }
    dp1[0] = 0;
    build(0, n - 1, dp1);
    cout << ans << "\n";
    return 0;
}
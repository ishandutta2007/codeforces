#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int max_n = 4005;

int m[max_n];
int sum[max_n];
int n;

struct a
{
    short l, r, k;
};

bool operator < (const a &a1, const a &b1)
{
    if (a1.l == b1.l)
        if (a1.r == b1.r)
            return a1.k < b1.k;
        else return a1.r < b1.r;
    else return a1.l < b1.l;
}

int dp[2150][150][150];
int vis[2150][150][150];
int maxl = 0;
// dist -    
int func(short l, int dist, short k, bool igor)
{
    int r = l - dist;
    if (vis[l][dist][k])
    {
        return dp[l][dist][k];
    }
    int dif1 = 0, ans, dif2 = 0;
    if (n - r - l < k)
    {
        return 0;
    }
    if (n - r - l == k)
    {
        dif1 = sum[n - r - 1];
        if (l)
        {
            dif1 -= sum[l - 1];
        }
        if (igor)
        {
            ans = dif1;
        }
        else
        {
            ans = -dif1;
        }
    }
    else if (igor)
    {
        dif1 = sum[l + k - 1] + func(l + k, dist + k, k, false);
        if (l) dif1 -= sum[l - 1];
        dif2 = sum[l + k] + func(l + k + 1, dist + k + 1, k + 1, false);
        if (l) dif2 -= sum[l - 1];
        ans = max(dif1, dif2);
    }
    else
    {
        dif1 = func(l, dist - k, k, true) - sum[n - r - 1];
        dif1 += sum[n - r - k - 1];
        dif2 = func(l, dist - k - 1, k + 1, true) - sum[n - r - 1];
        dif2 += sum[n - r - k - 2];
        ans = min(dif1, dif2);
    }
    vis[l][dist][k] = true;
    dp[l][dist][k] = ans;
    return ans;
}

int main()
{
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", m + i);
        //m[i] = rand() % 100000;
        s += m[i];
        sum[i] = s;
    }
    printf("%d", func(0, 0, 1, true));
    //cout << endl;
    //cout << maxl;
    return 0;
}
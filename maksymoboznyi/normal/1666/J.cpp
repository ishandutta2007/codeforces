#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <random>
#include <list>
#include <bitset>

using namespace std;

long long int dp[222][222];

int opt[222][222];

long long int c[222][222];

long long int pc[222][222];

long long int matsum(int l, int r, int u, int d)
{
    if (l > r)
        return 0;
    if (u > d)
        return 0;

    return pc[r][d] + pc[l-1][u-1] - pc[l-1][d] - pc[r][u-1];
}

int n;
long long int f(int l,int k,int r)
{
    long long int d = dp[l][k-1] + dp[k+1][r];

    d += 2 * matsum(l, k-1, k+1,r);

    d += matsum(l,k-1,k,k);
    d += matsum(k+1,r,k,k);


    d += matsum(l,k-1,1,l-1);
    d += matsum(k+1,r,1,l-1);

    d += matsum(l,k-1,r+1,n);
    d += matsum(k+1,r,r+1,n);

    return d;
}

int ans[222];

void go(int l,int r)
{
    int k = opt[l][r];

    if (l != k)
    {
        ans[opt[l][k-1]] = k;
        go(l, k-1);
    }

    if (k != r)
    {
        ans[opt[k+1][r]] = k;
        go(k+1, r);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin >> c[i][j];
        }
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            pc[i][j] = c[i][j] + pc[i-1][j] + pc[i][j-1] - pc[i-1][j-1];
        }
    }


    for (int len=1;len<=n;len++)
    {
        for(int l=1;l<=n;l++)
        {
            int r = l + len - 1;
            if (r > n)
                break;

            if (len == 1)
            {
                dp[l][r] = 0;
                opt[l][r] = l;
            } else {
                dp[l][r] = 1e18;
                for (int k=l;k<=r;k++)
                {
                    long long int fk = f(l,k,r);
                    if (fk <= dp[l][r]){
                        dp[l][r] = fk;
                        opt[l][r] = k;
                    }
                }
            }
        }
    }

    go(1,n);

    for (int i=1;i<=n;i++)
        cout << ans[i] << ' ';

    return 0;
}
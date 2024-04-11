#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef vector<int> vi;
typedef vector<pair<int ,int> > vii;
const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;
int dp[1 << 24] , sum;
int p[2] , a[25], k;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
        scanf("%d", &p[i]);
    dp[0] = 1;
    for(int mask = 1; mask < (1 << n); mask++)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            if((mask >> i)&1)
            {
                dp[mask] += dp[(mask ^ (1 << i))];
                if(dp[mask] >= mod)
                    dp[mask] -= mod;
                sum += a[i];
            }
        }
        for(int i = 0; i < k; i++)
            if(sum == p[i])
                dp[mask] = 0;
    }
    printf("%d", dp[(1 << n) - 1]);
}
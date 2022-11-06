#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second

using namespace std;
const int N = 5005;
int dp[N], n;
pair<int, int> tab[N];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &tab[i].ff, &tab[i].ss);
    }
    sort(tab + 1, tab + 1 + n);
    dp[1] = tab[1].ss;
    for(int i=2; i<=n; i++)
    {
        if(dp[i - 1] <= tab[i].ss)
            dp[i] = tab[i].ss;
        else dp[i] = tab[i].ff;
    }
    printf("%d", dp[n]);
    return 0;
}
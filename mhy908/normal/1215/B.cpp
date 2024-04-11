#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int n;
LL dp[200010][5];
LL ans1, ans2;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp<0){
            dp[i][1]=dp[i-1][2]+1;
            dp[i][2]=dp[i-1][1];
            ans1+=dp[i][1];
            ans2+=dp[i][2];
        }
        else{
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2]+1;
            ans2+=dp[i][2];
            ans1+=dp[i][1];
        }
    }
    printf("%lld %lld", ans1, ans2);
}
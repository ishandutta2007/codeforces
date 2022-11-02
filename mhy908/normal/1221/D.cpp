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
multiset<LL> s;
int n, q;
pll in[300010];
LL dp[300010][5];
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%lld %lld", &in[i].F, &in[i].S);
        }
        in[0].F=-llinf;
        dp[0][0]=0;
        dp[0][1]=0;
        dp[0][2]=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=2; j++){
                dp[i][j]=llinf;
                for(int k=0; k<=2; k++){
                    if(in[i-1].F+k==in[i].F+j)continue;
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+in[i].S*j);
                }
            }
        }
        printf("%lld\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
}
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=9000000000000000000;
const int inf=2000000000;
int n, m, re;
LL dp[100010];
pair<pii, LL> pr[500010];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        int a, b;
        LL c;
        scanf("%d %d %lld", &a, &b, &c);
        dp[a]-=c;
        dp[b]+=c;
    }
    int pv1=1, pv2=1;
    for(; pv1<=n; pv1++)if(dp[pv1]<0)break;
    for(; pv2<=n; pv2++)if(dp[pv2]>0)break;
    while(1){
        if(pv1>n&&pv2>n)break;
        if(-dp[pv1]>dp[pv2]){
            pr[++re]=mp(mp(pv1, pv2), dp[pv2]);
            //printf("%d %d %d", pv1, pv2, dp[pv2]);
            dp[pv1]+=dp[pv2];
            dp[pv2]=0;
            for(; pv2<=n; pv2++)if(dp[pv2]>0)break;
        }
        else if(-dp[pv1]<dp[pv2]){
            pr[++re]=mp(mp(pv1, pv2), -dp[pv1]);
            //printf("%d %d %d", pv1, pv2, dp[pv1]);
            dp[pv2]+=dp[pv1];
            dp[pv1]=0;
            for(; pv1<=n; pv1++)if(dp[pv1]<0)break;
        }
        else{
            pr[++re]=mp(mp(pv1, pv2), dp[pv2]);
            //printf("%d %d %d", pv1, pv2, dp[pv1]);
            dp[pv2]=0;
            dp[pv1]=0;
            for(; pv1<=n; pv1++)if(dp[pv1]<0)break;
            for(; pv2<=n; pv2++)if(dp[pv2]>0)break;
        }
    }
    printf("%d\n", re);
    for(int i=1; i<=re; i++){
        printf("%d %d %lld\n", pr[i].F.F, pr[i].F.S, pr[i].S);
    }
}
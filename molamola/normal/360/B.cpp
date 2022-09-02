#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

const int N_ = 2020;

int dp[N_];
int n,k;
int inp[N_];

bool check(ll x)
{
    int i,j,re=0;
    for(i=1;i<=n;i++)dp[i]=1;
    for(i=2;i<=n;i++){
        for(j=i-1;j;j--){
            if(x*(i-j) >= abs(inp[i]-inp[j]))dp[i]=max(dp[i],dp[j]+1);
        }
        re=max(re,dp[i]);
        if(i-re>k)return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)scanf("%d",inp+i);
    ll st=0, en=2e9, mi, ans=0;
    while(st<=en){
        mi = (st+en)>>1;
        if(check(mi))ans=mi,en=mi-1;
        else st=mi+1;
    }
    printf("%lld",ans);
    return 0;
}
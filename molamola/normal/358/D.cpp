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

int n;
int a[3030],b[3030],c[3030];
int dp[3030][2];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)scanf("%d",b+i);
    for(i=1;i<=n;i++)scanf("%d",c+i);
    dp[1][0]=a[1],dp[1][1]=b[1];
    for(i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
        dp[i][1]=max(dp[i-1][0]+c[i],dp[i-1][1]+b[i]);
    }
    printf("%d\n",dp[n][0]);
    return 0;
}
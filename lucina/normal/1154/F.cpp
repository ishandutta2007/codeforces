#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
const int inf=1e9;
int n,m,k,a[maxn],s[2005],dp[2005],b[2005],x,y;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x<=k)
        b[x]=max(b[x],y);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++){
        s[i]=s[i-1]+a[i];
        dp[i]=inf;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],dp[i-j]+s[i]-s[i-j+b[j]]);
        }
    }
    printf("%d\n",dp[k]);
}
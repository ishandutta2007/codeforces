#include<bits/stdc++.h>
using namespace std;
int n,q,a[200005],b[200005];
long long dp[500005];
char s[200005];
const int mod=1e9+7;
int main(){
    dp[0]=1;
    scanf("%d %d %s",&n,&q,s+1);
    for(int i=1;s[i]!='\0';i++){
        a[i]=a[i-1];
        b[i]=b[i-1];
        if(s[i]=='1') a[i]++;
        if(s[i]=='0') b[i]++;
    }
    int l,r,x,y;
    long long fuck=1;
    for(int i=1;i<=200000;i++){
        fuck=fuck*2;
        if(fuck>mod)
            fuck=fuck%mod;
        dp[i]=fuck;
    }
    long long ans=1,t=1;
    for(int j=1;j<=q;j++){
        scanf("%d%d",&l,&r);
        x=a[r]-a[l-1];
        y=b[r]-b[l-1];
        ans=((dp[x]*dp[y])-dp[y])%mod;
        if(ans<0)
            ans+=mod;
        printf("%lld\n",ans);
    }
}
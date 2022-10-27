#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,f=1048581;
int s[maxn],a[maxn],dp[2][f],n;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    dp[0][0]=1;
    /*for(int i=1;i<=n;i++){
        printf("%lld\n",s[i]);
    }*/
    for(int i=1;i<=n;i++){
        ans+=(dp[i&1][s[i]]);
        dp[i&1][s[i]]++;
    }
    printf("%lld\n",ans);
}
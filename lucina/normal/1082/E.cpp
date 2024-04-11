#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],s[maxn],ma,c,sum,ans,l[maxn],dp[maxn];


int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    s[i]=s[i-1]+(a[i]==c);
    }
    sum=s[n];
    ans=max(ans,sum);
    for(int i=1;i<=n;i++){
        if(a[i]!=c){
            dp[i]=dp[l[a[i]]]-(s[i]-s[l[a[i]]]);
            dp[i]=max(dp[i],0);
            dp[i]++;
            ans=max(ans,sum+dp[i]);
            l[a[i]]=i;
        }
    }
    printf("%d\n",ans);


}
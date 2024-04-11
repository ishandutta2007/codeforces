#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],dp[200],x,k,r;
long long ans;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        x%=k;
        dp[x]++;
    }
    for(int i=0;i<k;i++){
        if((i+i)%k==0){
            ans+=(2*(dp[i]/2));
        }
        else{
            ans+=(min(dp[i],dp[k-i]));
        }
    }
    printf("%lld\n",ans);

}
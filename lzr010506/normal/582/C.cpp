#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=400000;
int num[N],mma[N],dp[N],dpc[N];
int main(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",num+i),num[i+n]=num[i];
    for(int d=1;d<n;d++){
        if(n%d==0){
            memset(mma,0,sizeof(mma));
            for(int i=1;i<=d;i++)
                for(int j=i;j<=n;j+=d)
                    mma[i]=max(mma[i],num[j]);
            memset(dp,0,sizeof(dp));
            memset(dpc,0,sizeof(dpc));
            for(int i=1;i<=2*n;i++)
                if(num[i]==mma[(i-1)%d+1])
                    dp[i]=min(n-1,dp[i-1]+1);
            for(int i=1;i<=n/d;i++) if(__gcd(i,n/d)==1) dpc[i]++;
            for(int i=1;i<=n/d;i++) dpc[i]+=dpc[i-1];
            for(int i=n;i<n*2;i++) ans+=dpc[dp[i]/d];
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
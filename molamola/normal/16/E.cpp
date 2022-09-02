#include<stdio.h>

double dp[1<<18];
double inp[18][18],ans[18];
int n;
inline int NumberOfSetBits(int i)
{
    i=i-((i>>1)&0x55555555);
    i=(i&0x33333333)+((i>>2)&0x33333333);
    return(((i+(i>>4))&0x0F0F0F0F)*0x01010101)>>24;
}
int main(){
    scanf("%d",&n);
    int i,j,b;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lf",inp[i]+j);
    dp[0]=1;
    for(b=0;b<1<<n;b++){
        int s=NumberOfSetBits(b);
        s = (n-s)*(n-s-1)/2;
        for(i=0;i<n;i++){
            if(b&1<<i)continue;
            for(j=i+1;j<n;j++){
                if(b&1<<j)continue;
                dp[b|1<<i] += dp[b] * inp[j][i] / s;
                dp[b|1<<j] += dp[b] * inp[i][j] / s;
            }
        }
    }
    for(i=0;i<n;i++)printf("%f ",dp[1<<i ^ ((1<<n)-1)]);
    return 0;
}
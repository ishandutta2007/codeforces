#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=2e5+10;
int n,m,k,c[2005][2005];
int main(){
   scanf("%d%d%d",&n,&m,&k);
    c[1][1]=1,c[0][1],c[1][0]=1,c[0][0]=1;
    for(int i=1;i<=2001;i++){
        for(int j=0;j<=i;j++){
            if(j==i||j==0){
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
                c[i][j]%=mod;
            }
        }
    }
    long long ans=m;
    for(int i=1;i<=k;i++){
        ans*=(m-1);
        ans%=mod;
    }
    ans*=(c[n-1][k]);
    ans%=mod;
    printf("%lld\n",ans);
}
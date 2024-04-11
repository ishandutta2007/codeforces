#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int d[2014][2014];
const int mod=1000000007;

void solve(int n){
    int k,i,j,l,ans=0,t; 
    scanf("%d",&k);
    For(i,k+1){
        For(j,n+1){
            d[i][j]=0;
        }
    }
    For(i,n) d[1][i+1]=1;
    for(i=1;i<k;i++){
        for(j=1;j<n+1;j++){
            for(l=1;l<=n/j;l++){
                d[i+1][l*j]+=d[i][j];
                d[i+1][l*j]%=mod;
            }
        }
    }
    For(i,n){
        ans+=d[k][i+1];
        ans%=mod;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
int n,m,k;
while(scanf("%d",&n)!=EOF){
solve(n);
}
return 0;
}
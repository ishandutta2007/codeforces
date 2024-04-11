#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

double min(double x,double y){
    return x<y?x:y;
}


void solve(int n){
    int i,d[100100],k,sb[100100],mod=1000000007,l,r;
    scanf("%d",&k);
    For(i,100100) d[i]=0;
    d[0]=1;
    for(i=0;i<100100;i++){
        if(i+1<100100){
            d[i+1]+=d[i];
            d[i+1]%=mod;
        }
        if(i+k<100100){
            d[i+k]+=d[i];
            d[i+k]%=mod;
        }
    }
    sb[0]=0;
    for(i=1;i<100100;i++){
        sb[i]=sb[i-1]+d[i];
        sb[i]%=mod;
    }
    For(i,n){
        scanf("%d%d",&l,&r);
        printf("%d\n",(sb[r]-sb[l-1]+mod)%mod);
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
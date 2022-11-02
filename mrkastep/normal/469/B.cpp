#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

long long int max(long long int x,long long int y){
    return x>y?x:y;
}

void solve(int p,int q,int l,int r){
    int i,j,a,b,ans=0;;
    bool t;
    bool x[1005],y[1005];
    For(i,1005){
        x[i]=y[i]=false;
    }
    For(i,p){
        scanf("%d%d",&a,&b);
        for(j=a;j<=b;j++){
            x[j]=true;
        }
    }
    For(i,q){
        scanf("%d%d",&a,&b);
        for(j=a;j<=b;j++){
            y[j]=true;
        }
    }
    for(i=l;i<=r;i++){
        t=false;
        for(j=0;j<1001&&j+i<=1000;j++){
            if(y[j]&&x[i+j]){
                t=true;
            }
        }
        if(t) ans++;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d%d%d%d",&n,&m,&k,&l)!=EOF){
        solve(n,m,k,l);
    }
    return 0;
}
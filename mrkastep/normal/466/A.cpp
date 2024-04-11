#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n,int m,int a,int b){
    int ans;
    if(b/m>=a) ans=n*a;
    else{
        ans=(n/m)*b;
        if((n%m)*a>b) ans+=b;
        else ans+=(n%m)*a;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,c;
    while(scanf("%d%d%d%d",&n,&m,&k,&c)!=EOF){
        solve(n,m,k,c);
    }
    return 0;
}
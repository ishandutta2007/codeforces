#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,ans=0,p,q;
    For(i,n){
        scanf("%d%d",&p,&q);
        if(q-p>=2) ans++;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
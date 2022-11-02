#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int t,c,p,m=-1,ans=0,i;
    scanf("%d%d",&t,&c);
    For(i,c){
        scanf("%d",&p);
        if(p>t) m=i;
    }
    if(m==-1) ans++;
    for(i=i;i<n;i++){
        scanf("%d",&p);
        if(p>t) m=i;
        if(i-c+1>m) ans++;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
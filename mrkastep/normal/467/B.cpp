#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define For(i,n) for(i=0;i<(n);i++)

int a[1001];

int od(int x){
    int s=0,t=x;
    while(t>0){
        s+=t%2;
        t/=2;
    }
    return s;
}

void solve(int n,int m,int k){
    int i,ans=0,f;
    For(i,m){
        scanf("%d",&a[i]);
    }
    scanf("%d",&f);
    For(i,m){
        if(od(a[i]^f)<=k) ans++;
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
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        solve(n,m,k);
    }
    return 0;
}
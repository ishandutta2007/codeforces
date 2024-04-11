#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int a[100];


void solve(int n){
    int i,t=0,m,p=0,s=0;
    For(i,n){
        scanf("%d",&m);
        if(m==1){
            s++;
            if(t==0) p++;
        }
        t=m;
    }
    if(s!=0){
        printf("%d",s+p-1);
        return;
    }
    printf("%d",0);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}
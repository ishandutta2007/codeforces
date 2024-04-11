#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int a[100];


void solve(int n){
    int i,m;
    char c;
    scanf("%c",&c);
    For(i,n){
        scanf("%c",&c);
        a[i]=c-'0';
    }
    m=0;
    i=0;
    while(i<n&&a[i]==1){
        i++;
    }
    if(i!=n){
        printf("%d ",i+1);
    }
    else printf("%d",n);
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
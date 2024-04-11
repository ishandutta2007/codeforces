#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int a[100000],t[100001],ans[100001];

void solve(int n,int m){
    int i,s,l,j;
    For(i,n) scanf("%d",&a[i]);
    ans[n]=0;
    For(i,100001) t[i]=0;
    for(i=n-1;i>-1;i--){
        ans[i]=ans[i+1];
        if(t[a[i]]==0) ans[i]++;
        t[a[i]]=1;
    }
    For(i,m){
        scanf("%d",&l);
        printf("%d\n",ans[l-1]);
    }
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
    solve(n,m);
    }
    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int z[150000],ans[150000];


void solve(int n,int k){
    int i,m;
    For(i,n) scanf("%d",&z[i]);
    ans[0]=0;
    For(i,k){
        ans[0]+=z[i];
    }
    m=0;
    for(i=1;i<n-k+1;i++){
        ans[i]=ans[i-1]-z[i-1]+z[i-1+k];
        if(ans[i]<ans[m]) m=i;
    }
    printf("%d\n",m+1);
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
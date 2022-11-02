#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

int a[2014];

bool srt(int x,int y){
    return a[x]<a[y]?true:false;
}

void solve(int n){
    int i,ind[2014],t,p;
    For(i,n){
        scanf("%d",&a[i]);
        ind[i]=i;
    }
    std::sort(ind,ind+n,srt);
    for(i=0;i<n-1&&a[ind[i]]!=a[ind[i+1]];i++);
    if(i==n-1){
        printf("NO");
        return;
    }
    t=i;
    for(i=0;i<n-1&&(a[ind[i]]!=a[ind[i+1]]||i==t);i++);
    if(i==n-1){
        printf("NO");
        return;
    }
    printf("YES\n");
    p=i;
    For(i,n){
        printf("%d ",ind[i]+1);
    }
    printf("\n");
    For(i,t) printf("%d ",ind[i]+1);
    printf("%d %d ",ind[i+1]+1,ind[i]+1);
    i+=2;
    for(i=i;i<n;i++) printf("%d ",ind[i]+1);
    printf("\n");
    For(i,p) printf("%d ",ind[i]+1);
    printf("%d %d ",ind[i+1]+1,ind[i]+1);
    i+=2;
    for(i=i;i<n;i++) printf("%d ",ind[i]+1);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){

        solve(n);
    }
    return 0;
}
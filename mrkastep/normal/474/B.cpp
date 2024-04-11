#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

double min(double x,double y){
    return x<y?x:y;
}


void solve(int n){
    int i,m,sb[100100],t,l,r;
    For(i,n){
        scanf("%d",&sb[i]);
        if(i!=0) sb[i]+=sb[i-1];
    }
    scanf("%d",&m);
    For(i,m){
        scanf("%d",&t);
        l=0;
        r=n-1;
        while(r-l>1){
            if(sb[(l+r)/2]>=t) r=(l+r)/2;
            else l=(l+r)/2;
        }
        if(sb[l]>=t) printf("%d\n",l+1);
        else printf("%d\n",r+1);
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

long long int max(long long int x,long long int y){
    return x>y?x:y;
}

void solve(int n){
    int i,t,y;
    bool p[101],x;
    For(i,n) p[i]=false;
    scanf("%d",&y);
    For(i,y){
        scanf("%d",&t);
        p[t-1]=true;
    }
    scanf("%d",&y);
    For(i,y){
        scanf("%d",&t);
        p[t-1]=true;
    }
    x=true;
    For(i,n) x=x&&p[i];
    if(x) printf("I become the guy.");
    else printf("Oh, my keyboard!");
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
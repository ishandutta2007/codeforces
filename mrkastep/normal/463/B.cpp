#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,m,x;
    m=0;
    For(i,n){
        scanf("%d",&x);
        if(x>m) m=x;
    }
    printf("%d",m);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}
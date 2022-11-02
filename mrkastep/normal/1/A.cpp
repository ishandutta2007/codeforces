#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

void solve(int n,int m,int a){
    int x,y;
    if(n%a==0) x=n/a;
    else x=n/a+1;
    if(m%a==0) y=m/a;
    else y=m/a+1;
    printf("%I64d",(long long int)x*y);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
    solve(n,m,k);
    }
    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define For(i,n) for(i=0;i<(n);i++)

int n,m;

int code(int v){
    long long int t=1,s=0,x=v;
    while(v/t>0){
        s+=v/t;
        t*=m;
    }
    return s;
}

void solve(int n){
    int a=n,b=1,c;
    while(a-b>1){
        c=(a+b)/2;
        if(code(c)>n) a=c;
        else b=c;
    }
    if(code(b)>=n){
        printf("%d",b);
        return;
    }
    printf("%d",a);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//  int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        solve(n);
    }
    return 0;
}
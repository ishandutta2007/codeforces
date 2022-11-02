#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

int f(int n){
    int c=1,i;
    For(i,n) c*=i+1;
    return c;
}

int cnk(int n,int k){
    return f(n)/(f(k)*f(n-k));
}

int mod(int x){
    return x<0?-x:x;
}

void solve(int n){
    int i,k;
    scanf("%d",&k);
    printf("%d\n",(6*n-1)*k);
    For(i,n){
        printf("%d %d %d %d\n",(6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k);
    }
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
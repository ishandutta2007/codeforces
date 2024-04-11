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

void solve(long long int n){
    int i,rh,ans=0;
    long long int rt;
    rt=(-1+(int)sqrt((double)(24*n+1)))/6;
    rt-=10;
    while(3*(rt+1)*(rt+1)+(rt+1)<=2*n||rt<0){
        rt++;
    }
    rh=-(n%3)+3;
    rh%=3;
    while(rt%3!=rh&&rt>=0){
        rt--;
    }
    for(i=1;i<rt+1;i++){
        if(i%3==rh) ans++;
    }
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    long long int n,m,k,l;
    while(scanf("%I64d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
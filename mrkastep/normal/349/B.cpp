#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

void solve(int v){
    int i,d[10],l,t=0,mx,j,m;
    For(i,9) scanf("%d",&d[i+1]);
    m=1;
    for(i=2;i<10;i++) m=d[m]>=d[i]?i:m;
    l=v/d[m];
    v%=d[m];
    if(l==0) printf("-1");
    For(j,l){
        mx=m;
        for(i=m;i<10;i++){
            if(d[i]-d[m]<=v) mx=i;
        }
        printf("%d",mx);
        v-=d[mx]-d[m];
    }
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
int n,m,k;
while(scanf("%d",&n)!=EOF){
solve(n);
}
return 0;
}
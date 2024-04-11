#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

int d[50050][6],t[50050][6];

void solve(int n){
    int m,i,j;
    scanf("%d",&m);
    For(i,n) d[i][0]=0;
    For(i,n){
        For(j,m){
            scanf("%d",&t[i][j+1]);
        }
    }
    For(i,n){
        For(j,m){
            d[i][j+1]=max(d[i][j],d[i-1][j+1])+t[i][j+1];
        }
    }
    For(i,n) printf("%d ",d[i][m]);
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
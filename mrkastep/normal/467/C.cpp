#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

long long int a[5005][5005],sb[5005];
int p[5005];

long long int max(long long int x,long long int y){
    return x>y?x:y;
}

void solve(int n,int m,int k){
    int i,j;
    for(i=1;i<n+1;i++){
        for(j=1;j<k+1;j++){
            a[i][j]=-1;
        }
    }
    for(i=1;i<n+1;i++){
        a[i][0]=0;
    }
    For(i,n){
        scanf("%d",&p[i]);
    }
    sb[m-1]=0;
    for(i=1;i<m+1;i++){
        sb[m]+=p[i-1];
    }
    for(i=m+1;i<n+1;i++){
        sb[i]=sb[i-1]-p[i-m-1]+p[i-1];
    }
    a[m][1]=sb[m];
    for(j=1;j<k+1;j++){
        for(i=m;i<n+1;i++){
            if(a[i][j]==-1){
                a[i][j]=max(a[i-1][j],a[i-m][j-1]+sb[i]);
            }
        }
    }
    printf("%I64d",a[n][k]);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        solve(n,m,k);
    }
    return 0;
}
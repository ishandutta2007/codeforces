#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[505][505],n,m,b[505][505];
void inver(int i,int j){
    a[i][j]^=1;
    a[i+1][j]^=1;
    a[i][j+1]^=1;
    a[i+1][j+1]^=1;
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&b[i][j]);
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]!=b[i][j]){
                inver(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=b[i][j]){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
}
/*
    Lucina
*/
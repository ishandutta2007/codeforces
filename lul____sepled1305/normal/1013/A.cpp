#include<stdio.h>
int n,i,j,k;
int main(){
    scanf("%d",&n);
    int stone[3][n+1];
    for(i=1;i<=n;i++){
        scanf("%d",&stone[1][i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&stone[2][i]);
    }
    for(i=1;i<=n;i++){
        j=j+stone[1][i];
    }
    for(i=1;i<=n;i++){
        k=k+stone[2][i];
    }
    if(k>j){
        printf("NO");
    }
    else{
        printf("YES");
    }
}
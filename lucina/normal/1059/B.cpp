#include<stdio.h>
int n,m,b[2000][2000],i,j,k,l;
char a[2000][2000];
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
        for(j=0;j<m;j++){
            if(a[i][j]=='#')
                b[i][j]=1;
        }

    }
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
    if(a[i][j]=='#'&&a[i][j+1]=='#'&&a[i][j+2]=='#'&&a[i+1][j]=='#'&&a[i+1][j+2]=='#'&&a[i+2][j]=='#'&&a[i+2][j+1]=='#'&&a[i+2][j+2]=='#'){
        for(k=0;k<3;k++)
            for(l=0;l<3;l++)
            if(l!=1||k!=1)
            b[i+k][j+l]=0;
    }

    }
    bool check=true;
    for(i=0;i<n&&check;i++)
    for(j=0;j<m&&check;j++){
        if(b[i][j]==1){
            printf("NO");
            check=false;
            break;
        }
    }
    if(check)
        printf("YES");

}
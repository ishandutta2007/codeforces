#include<cstdio>
const int N=1002;
bool f[N][N];
int n,i,j,ans;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(!f[i-1][j]&&!f[i][j-1]){
        f[i][j]=1;
        ans++;
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%c",f[i][j]?'C':'.');
        printf("\n");
    }
}
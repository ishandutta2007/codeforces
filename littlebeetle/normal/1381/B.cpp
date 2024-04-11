#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4002;
int f[N][N],g[N][N],T,n,a[N],pre[N],i,j;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<=n*2+1;i++)
            for(j=0;j<=n*2+1;j++)
                f[i][j]=g[i][j]=0;
        for(i=1;i<=n*2;i++){
            scanf("%d",a+i);
            pre[i]=0;
            for(j=i-1;j;j--)
                if(a[j]>a[i]){
                    pre[i]=j;
                    break;
                }
        }
        f[n*2+1][0]=g[n*2+1][0]=1;
        for(i=n*2;i;i--){
            for(j=0;j<=n*2;j++){
                f[i][j]+=f[i+1][j];
                g[i][j]+=g[i+1][j];
                if(f[i][j]){
                    g[i-1][n*2-i+1-j]++;
                    g[pre[i]][n*2-i+1-j]--;
                }
                if(g[i][j]){
                    f[i-1][n*2-i+1-j]++;
                    f[pre[i]][n*2-i+1-j]--;
                }
            }
        }
        printf("%s\n",f[1][n]?"YES":"NO");
    }
    return 0;
}
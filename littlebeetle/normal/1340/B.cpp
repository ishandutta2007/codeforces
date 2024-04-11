#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2002;

const int p[]={1110111,10010,1011101,1011011,111010,1101011,1101111,1010010,1111111,1111011};
int n,m,x,i,j,k,s;
int a[N][N];
int w[N][10];
void init(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        for(k=0;k<=9;k++){
            s=0;
            for(j=1;j<=10000000;j*=10){
                if(p[k]/j%10==1&&x/j%10==0)
                    s++;
                if(p[k]/j%10==0&&x/j%10==1){
                    s=-1;
                    break;
                }              
            }
            w[i][k]=s;
        }
    }
}
void dfs(int x,int y){
    printf("%d",a[x][y]);
    if(x<n)
        dfs(x+1,y-w[x][a[x][y]]);
}
void work(){
    memset(a,-1,sizeof(a));
    a[n+1][0]=0;
    for(i=n;i;i--)
        for(j=0;j<=m;j++)
            for(k=9;k>=0;k--)
                if(w[i][k]>=0&&j>=w[i][k]&&a[i+1][j-w[i][k]]>=0){
                    a[i][j]=k;
                    break;
                }
    if(a[1][m]>=0)
        dfs(1,m);
    else
        printf("-1");
    
}
int main(){
    init();
    work();
    return 0;
}
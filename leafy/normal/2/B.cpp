#include<cstdio>
#include<algorithm>
using namespace std;
const int Inf=0x7FFFFFFF;
int n,t,num[1002][1002][2],f[1002][1002][2];
void Print(int i,int j,int k) {
    if(i==1&&j==1) {                //
        putchar(k? 'D':'R');
        return ;            //
    }
    if(i==1)
        Print(i,j-1,0);
    else if(j==1)
        Print(i-1,j,1);
    else if(f[i][j][t]==f[i][j-1][t]+num[i][j][t])
        Print(i,j-1,0);
    else
        Print(i-1,j,1);
    if(i!=n||j!=n)
        putchar(k? 'D':'R');    //(n,n)
}
int main() {
    int ans;
    scanf("%d",&n);
    for(int i=1,k;i<=n;++i)
        for(int j=1;j<=n;++j) {        //
            scanf("%d",&k);
            if(!k) {
                num[i][j][0]=num[i][j][1]=1;
                t=i;    //0
            }
            else {
                for(;!(k%2);k/=2)
                    ++num[i][j][0];
                for(;!(k%5);k/=5)
                    ++num[i][j][1];
            }
        }
    for(int i=1;i<=n;++i)
        f[0][i][0]=f[i][0][0]=f[0][i][1]=f[i][0][1]=Inf;    //min
    f[1][1][0]=num[1][1][0];
    f[1][1][1]=num[1][1][1];
    for(int k=0;k<2;++k)
        for(int i=1;i<=n;++i)
            for(int j=i==1? 2:1;j<=n;++j)
                f[i][j][k]=min(f[i][j-1][k],f[i-1][j][k])+num[i][j][k];
    ans=min(f[n][n][0],f[n][n][1]);
    if(t&&ans>1) {            //2
        printf("1\n");
        for(int i=1;i<t;++i)
            putchar('D');
        for(int i=1;i<n;++i)
            putchar('R');
        for(int i=t;i<n;++i)
            putchar('D');
    }
    else {                    //1
        printf("%d\n",ans);
        t=!(f[n][n][0]<f[n][n][1]);
        Print(n,n,0);
    }
    return 0;
}
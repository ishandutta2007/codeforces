#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,K,f[1010][1010][11][2];
char A[1010],B[1010];
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s%s",A+1,B+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=1;k<=K;k++)
            {
                if(i>0) f[i][j][k][0]=max(f[i][j][k][0],f[i-1][j][k][0]);
                if(j>0) f[i][j][k][0]=max(f[i][j][k][0],f[i][j-1][k][0]);
                if(i>0&&j>0&&A[i]==B[j])
                {
                    f[i][j][k][1]=max(f[i][j][k][1],f[i-1][j-1][k][1]+1);
                    f[i][j][k][1]=max(f[i][j][k][1],f[i-1][j-1][k-1][0]+1);
                    f[i][j][k][0]=max(f[i][j][k][0],f[i][j][k][1]);
                }
            }
    printf("%d\n",f[n][m][K][0]);
    return 0;
}
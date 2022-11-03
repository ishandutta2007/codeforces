#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int ninf=(int)0x80000000;
char a[maxn],b[maxn];
int n,f[maxn][4],t[4];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    t[0]=0,t[1]=1,t[2]=0,t[3]=2;
    while(T--)
    {
        scanf("%d%s%s",&n,a+1,b+1);
        f[0][0]=0,f[0][1]=f[0][2]=f[0][3]=ninf;
        for(i=1;i<=n;i++)
        {
            f[i][0]=f[i][1]=f[i][2]=f[i][3]=ninf;
            // for(j=0;j<=2;j++)
            // {
            //     k=j;
            //     if(k==a[i]-'0' || k==b[i]-'0') k++;
            //     if(k==a[i]-'0' || k==b[i]-'0') k++;
            //     f[i][0]=max(f[i][0],f[i-1][j]+k);
            //     f[i][k]=max(f[i][k],f[i-1][j]);
            // }
            for(j=0;j<=3;j++)
            {
                k=j|(1<<(a[i]-'0'))|(1<<(b[i]-'0'));
                f[i][0]=max(f[i][0],f[i-1][j]+t[k]);
                f[i][k]=max(f[i][k],f[i-1][j]);
            }
            // printf("%d %d %d %d\n",f[i][0],f[i][1],f[i][2],f[i][3]);
        }
        printf("%d\n",f[n][0]);
    }
    return 0;
}
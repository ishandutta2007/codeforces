//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
const int P=998244353;int n,cn[26],f[2][205][205][3][3],g[405][405];
int main()
{
    read(n);for(int i=0;i<26;i++) read(cn[i]);
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) f[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i?1:24)*(j?1:24);
    for(int i=3,w=1;i<=n;i++,w^=1)
    {
        memset(f[w],0,sizeof(f[w]));for(int u=0;u<=n/2+1;u++) for(int v=0;v<=n/2+1;v++)
            for(int x=0;x<3;x++) for(int y=0;y<3;y++) for(int z=0;z<3;z++) if((x^z)||!x)
            {
                if(x==z) f[w][u][v][y][z]=(f[w][u][v][y][z]+23ll*f[w^1][u][v][x][y])%P;
                else f[w][u+(z==1)][v+(z==2)][y][z]=(f[w][u+(z==1)][v+(z==2)][y][z]+(z?1ll:24ll)*f[w^1][u][v][x][y])%P;
            }
    }
    for(int i=n/2+1;~i;i--) for(int j=n/2+1;~j;j--)
    {
        g[i][j]=(1ll*g[i+1][j]+g[i][j+1]-g[i+1][j+1]+P)%P;
        for(int x=0;x<3;x++) for(int y=0;y<3;y++) g[i][j]=(g[i][j]+f[n&1][i][j][x][y])%P;
    }
    int rs=g[0][0];for(int i=0;i<26;i++) rs=(rs-g[cn[i]+1][0]+P)%P;
    for(int i=0;i<26;i++) for(int j=i+1;j<26;j++) rs=(rs+g[cn[i]+1][cn[j]+1])%P;
    return printf("%d\n",rs),0;
}
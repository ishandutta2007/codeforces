#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
int p[2*N];
int f[2*N][N],g[2*N][N];
int mxf[2*N][N],mxg[2*N][N];
int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=2*n;i++) p[i]=read();

        for(int i=0;i<=2*n;i++) for(int j=0;j<=n;j++) f[i][j]=g[i][j]=mxf[i][j]=mxg[i][j]=0;

        f[1][0]=g[1][0]=1;
        mxf[1][0]=mxg[1][0]=1;


        for(int i=2;i<=2*n;i++)
        {
            int mx=0;
            int len=0;
            for(int j=1;i-j>=1;j++){
                mx=max(mx,p[i-j]);
                if(mx>p[i]) break ;
                len=j;
            }
            for(int j=1;j<=i-1;j++){
                f[i][j]=(mxg[i-1][i-1-j]-mxg[i-len-1][i-1-j]>0);
            }

            for(int j=1;j<=i-1;j++){
                g[i][j]=(mxf[i-1][i-1-j]-mxf[i-len-1][i-1-j]>0);
            }
            for(int j=0;j<=i;j++) mxf[i][j]=mxf[i-1][j]+f[i][j];
            for(int j=0;j<=i;j++) mxg[i][j]=mxg[i-1][j]+g[i][j];
        }
    //    cerr<<f[4][1]<<endl;


        bool ok=0;
        for(int i=1;i<=2*n;i++)
        {
            if(f[i][n]||g[i][n]){
                ok=1; break ;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}
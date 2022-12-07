#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=2010;
LL ans;
int n,m;
char a[MAXN][MAXN];
bool p[MAXN];
int L[MAXN][MAXN],R[MAXN][MAXN],U[MAXN][MAXN],D[MAXN][MAXN];
bool u[MAXN][MAXN],d[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=2;i<n;i++)
    {
        bool ok=true;
        for(int j=1;j<=m;j++)
            if(a[i][j]=='#') ok=false;
        if(ok) ans++;
    }
    for(int i=2;i<m;i++)
    {
        bool ok=true;
        for(int j=1;j<=n;j++)
            if(a[j][i]=='#') ok=false;
        if(ok) ans++;
    }
    for(int i=2;i<m;i++) p[i]=(a[1][i]=='#')?false:true;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
            p[j]&=((a[i][j]=='#')?false:true);
        bool ok=(a[i][1]=='#')?false:true;
        for(int j=2;j<m;j++)
        {
            ok&=((a[i][j]=='#')?false:true);
            if(ok&&p[j]) ans++;
        }
    }
    for(int i=2;i<m;i++) p[i]=(a[n][i]=='#')?false:true;
    for(int i=n-1;i>1;i--)
    {
        for(int j=2;j<m;j++)
            p[j]&=((a[i][j]=='#')?false:true);
        bool ok=(a[i][1]=='#')?false:true;
        for(int j=2;j<m;j++)
        {
            ok&=((a[i][j]=='#')?false:true);
            if(ok&&p[j]) ans++;
        }
    }
    for(int i=2;i<m;i++) p[i]=(a[1][i]=='#')?false:true;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
            p[j]&=((a[i][j]=='#')?false:true);
        bool ok=(a[i][m]=='#')?false:true;
        for(int j=m-1;j>1;j--)
        {
            ok&=((a[i][j]=='#')?false:true);
            if(ok&&p[j]) ans++;
        }
    }
    for(int i=2;i<m;i++) p[i]=(a[n][i]=='#')?false:true;
    for(int i=n-1;i>1;i--)
    {
        for(int j=2;j<m;j++)
            p[j]&=((a[i][j]=='#')?false:true);
        bool ok=(a[i][m]=='#')?false:true;
        for(int j=m-1;j>1;j--)
        {
            ok&=((a[i][j]=='#')?false:true);
            if(ok&&p[j]) ans++;
        }
    }
    for(int i=1;i<=m;i++) u[1][i]=(a[1][i]=='#')?false:true;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=m;j++)
            u[i][j]=(u[i-1][j])&((a[i][j]=='#')?false:true);
    for(int i=1;i<=m;i++) d[n][i]=(a[n][i]=='#')?false:true;
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=m;j++)
            d[i][j]=(d[i+1][j])&((a[i][j]=='#')?false:true);
    for(int i=2;i<n;i++)
    {
        L[i][2]=1;
        for(int j=3;j<m;j++)
            L[i][j]=(a[i][j]=='#')?j:L[i][j-1];
        R[i][m-1]=m;
        for(int j=m-2;j>1;j--)
            R[i][j]=(a[i][j]=='#')?j:R[i][j+1];
    }
    for(int i=2;i<n;i++)
    {
        LL con=0;
        for(int j=2;j<m;j++)
        {
            if(a[i][j]=='#') continue;
            if(a[i][j-1]=='#'||j==2)
            {
                con=0;
                for(int k=L[i][j]+1;k<R[i][j];k++)
                    if(u[i][k]) con++;
                for(int k=L[i][j]+1;k<R[i][j]-1;k++)
                    if(u[i][k]&&u[i][k+1]) ans--;
                ans+=con*(con-1)/2;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        LL con=0;
        for(int j=2;j<m;j++)
        {
            if(a[i][j]=='#') continue;
            if(a[i][j-1]=='#'||j==2)
            {
                con=0;
                for(int k=L[i][j]+1;k<R[i][j];k++)
                    if(d[i][k]) con++;
                for(int k=L[i][j]+1;k<R[i][j]-1;k++)
                    if(d[i][k]&&d[i][k+1]) ans--;
                ans+=con*(con-1)/2;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        LL con=0;
        for(int j=2;j<m;j++)
        {
            if(a[i][j]=='#') continue;
            if(a[i][j-1]=='#'||j==2)
            {
                con=0;
                for(int k=R[i][j]-1;k>L[i][j];k--)
                {
                    if(u[i][k]) ans+=con;
                    if(d[i][k]) con++;
                }
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        LL con=0;
        for(int j=2;j<m;j++)
        {
            if(a[i][j]=='#') continue;
            if(a[i][j-1]=='#'||j==2)
            {
                con=0;
                for(int k=R[i][j]-1;k>L[i][j];k--)
                {
                    if(d[i][k]) ans+=con;
                    if(u[i][k]) con++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) l[i][1]=(a[i][1]=='#')?false:true;
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
            l[j][i]=(l[j][i-1])&((a[j][i]=='#')?false:true);
    for(int i=1;i<=n;i++) r[i][m]=(a[i][m]=='#')?false:true;
    for(int i=m-1;i>=1;i--)
        for(int j=1;j<=n;j++)
            r[j][i]=(r[j][i+1])&((a[j][i]=='#')?false:true);
    for(int i=2;i<m;i++)
    {
        U[2][i]=1;
        for(int j=3;j<n;j++)
            U[j][i]=(a[j][i]=='#')?j:U[j-1][i];
        D[n-1][i]=n;
        for(int j=n-2;j>1;j--)
            D[j][i]=(a[j][i]=='#')?j:D[j+1][i];
    }
    for(int i=2;i<m;i++)
    {
        LL con=0;
        for(int j=2;j<n;j++)
        {
            if(a[j][i]=='#') continue;
            if(a[j-1][i]=='#'||j==2)
            {
                con=0;
                for(int k=U[j][i]+1;k<D[j][i];k++)
                    if(l[k][i]) con++;
                for(int k=U[j][i]+1;k<D[j][i]-1;k++)
                    if(l[k][i]&&l[k+1][i]) ans--;
                ans+=con*(con-1)/2;
            }
        }
    }
    for(int i=2;i<m;i++)
    {
        LL con=0;
        for(int j=2;j<n;j++)
        {
            if(a[j][i]=='#') continue;
            if(a[j-1][i]=='#'||j==2)
            {
                con=0;
                for(int k=U[j][i]+1;k<D[j][i];k++)
                    if(r[k][i]) con++;
                for(int k=U[j][i]+1;k<D[j][i]-1;k++)
                    if(r[k][i]&&r[k+1][i]) ans--;
                ans+=con*(con-1)/2;
            }
        }
    }
    for(int i=2;i<m;i++)
    {
        LL con=0;
        for(int j=2;j<n;j++)
        {
            if(a[j][i]=='#') continue;
            if(a[j-1][i]=='#'||j==2)
            {
                con=0;
                for(int k=D[j][i]-1;k>U[j][i];k--)
                {
                    if(l[k][i]) ans+=con;
                    if(r[k][i]) con++;
                }
            }
        }
    }
    for(int i=2;i<m;i++)
    {
        LL con=0;
        for(int j=2;j<n;j++)
        {
            if(a[j][i]=='#') continue;
            if(a[j-1][i]=='#'||j==2)
            {
                con=0;
                for(int k=D[j][i]-1;k>U[j][i];k--)
                {
                    if(r[k][i]) ans+=con;
                    if(l[k][i]) con++;
                }
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
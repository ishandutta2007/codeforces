//Author:mxh1999
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define maxn 210
const int mo=51123987;
int s[maxn];
int next[maxn][3];
int f[151][55][55][55];
int n,m,ans;
int pos[3];

inline bool ok(int a,int b,int c)
{
    if (a+b+c==n && abs(a-b)<=1 && abs(b-c)<=1 && abs(a-c)<=1)  return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    m=(n+2)/3;
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch<'a' || ch>'z')    ch=getchar();
        s[i]=ch-'a';
    }
    pos[0]=pos[1]=pos[2]=n+1;
    for (int i=n;i>0;i--)
    {
        pos[s[i]]=i;
        for (int j=0;j<3;j++)   next[i][j]=pos[j];
    }
    f[1][0][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int a=0;a<=m;a++)
            for (int b=0;b<=m;b++)
                for (int c=0;c<=m;c++)
                if (f[i][a][b][c])
                {
                    if (ok(a,b,c))
                    {
                        ans=(ans+f[i][a][b][c])%mo;
                        continue;
                    }
                    if (next[i][0]<=n)  f[next[i][0]][a+1][b][c]=(f[next[i][0]][a+1][b][c]+f[i][a][b][c])%mo;
                    if (next[i][1]<=n)  f[next[i][1]][a][b+1][c]=(f[next[i][1]][a][b+1][c]+f[i][a][b][c])%mo;
                    if (next[i][2]<=n)  f[next[i][2]][a][b][c+1]=(f[next[i][2]][a][b][c+1]+f[i][a][b][c])%mo;
                }
    printf("%d\n",ans);
    return 0;
}
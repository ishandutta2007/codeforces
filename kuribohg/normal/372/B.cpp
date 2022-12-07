#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[51][51];
int aa[41][41],S[41][41][41][41];
int n,m,Q,p,q,r,s;
int Query(int x1,int y1,int x2,int y2)
{
    return aa[x2][y2]-aa[x1-1][y2]-aa[x2][y1-1]+aa[x1-1][y1-1];
}
int GetAns(int a,int b,int c,int d)
{
    return S[c][d][c][d]-S[a-1][d][c][d]-S[c][b-1][c][d]+S[a-1][b-1][c][d];
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='1') aa[i][j]=1;
            else aa[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            aa[i][j]+=aa[i][j-1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            aa[i][j]+=aa[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=i;k<=n;k++)
                for(int l=j;l<=m;l++)
                    if(Query(i,j,k,l)==0) S[i][j][k][l]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                    S[i][j][k][l]+=S[i][j][k][l-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                    S[i][j][k][l]+=S[i][j][k-1][l];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                    S[i][j][k][l]+=S[i][j-1][k][l];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                    S[i][j][k][l]+=S[i-1][j][k][l];
    while(Q--)
    {
        scanf("%d%d%d%d",&p,&q,&r,&s);
        printf("%d\n",GetAns(p,q,r,s));
    }
    return 0;
}
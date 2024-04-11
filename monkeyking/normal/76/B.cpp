#include <bits/stdc++.h>
using namespace std;
const int inf=1039074182;
inline void chmin(int &x,const int &b){x=(x<b?x:b);}
int n,m;
int a[100005];
int b[100005];
int dp[100005][2];

inline int getpos(int i,int j)
{
    if(j==0) return upper_bound(b,b+m,a[i])-b-1;
    else return lower_bound(b,b+m,a[i])-b;
}

inline int calcDis(int i,int d)
{
    int j=getpos(i,d);
    return abs(a[i]-b[j]);
}

inline int getCost(int i1,int d1,int i2,int d2)
{
    int p1=getpos(i1,d1),p2=getpos(i2,d2);
    return (p1!=p2?0:calcDis(i1,d1)!=calcDis(i2,d2));
}

int main()
{
    scanf("%d%d%*d%*d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",b+i);
    }
    a[0]=-inf;
    b[0]=-inf;
    a[++n]=inf;
    b[++m]=inf;
    n++;
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int nj=0;nj<2;nj++)
            {
                if(calcDis(i,nj)<=calcDis(i,!nj)) chmin(dp[i+1][nj],dp[i][j]+getCost(i-1,j,i,nj));
            }
        }
    }
    cout<<min(dp[n][0],dp[n][1])<<endl;
    return 0;
}
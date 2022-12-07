#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int INF=1000000000;
int n,L[2010],R[2010];
LL H,x[2010],LenL[2010],LenR[2010];
double p,f[2010][2010][2][2];
double getf(int l,int r,int ls,int rs)
{
    if(l>r) return 0;
    if(f[l][r][ls][rs]>=0) return f[l][r][ls][rs];
    f[l][r][ls][rs]=0;
    if(ls==0) f[l][r][ls][rs]+=0.5*p*(min(x[l]-x[l-1],H)+getf(l+1,r,0,rs));
    else f[l][r][ls][rs]+=0.5*p*(min(x[l]-x[l-1]-H,H)+getf(l+1,r,0,rs));
    if(rs==0) f[l][r][ls][rs]+=0.5*(1-p)*(min(LenR[l],x[r+1])-x[l]+getf(min(r,R[l])+1,r,1,rs));
    else f[l][r][ls][rs]+=0.5*(1-p)*(min(LenR[l],x[r+1]-H)-x[l]+getf(min(r,R[l])+1,r,1,rs));
    if(rs==0) f[l][r][ls][rs]+=0.5*(1-p)*(min(x[r+1]-x[r],H)+getf(l,r-1,ls,0));
    else f[l][r][ls][rs]+=0.5*(1-p)*(min(x[r+1]-x[r]-H,H)+getf(l,r-1,ls,0));
    if(ls==0) f[l][r][ls][rs]+=0.5*p*(x[r]-max(LenL[r],x[l-1])+getf(l,max(l,L[r])-1,ls,1));
    else f[l][r][ls][rs]+=0.5*p*(x[r]-max(LenL[r],x[l-1]+H)+getf(l,max(l,L[r])-1,ls,1));
    return f[l][r][ls][rs];
}
int main()
{
    scanf("%d%I64d%lf",&n,&H,&p);
    for(int i=1;i<=n;i++) scanf("%I64d",&x[i]);
    x[0]=-INF,x[n+1]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int ii=0;ii<2;ii++)
                for(int jj=0;jj<2;jj++)
                    f[i][j][ii][jj]=-1;
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)
    {
        int o=i;
        while(o<n&&x[o+1]-x[o]<H) o++;
        R[i]=o,LenR[i]=x[o]+H;
    }
    for(int i=1;i<=n;i++)
    {
        int o=i;
        while(o>1&&x[o]-x[o-1]<H) o--;
        L[i]=o,LenL[i]=x[o]-H;
    }
    printf("%.010lf\n",getf(1,n,0,0));
    return 0;
}
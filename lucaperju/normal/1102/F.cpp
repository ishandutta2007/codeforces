#include <bits/stdc++.h>
using namespace std;
int d[17][17][(1<<16)+5];
bool verif (int msk, int pz)
{
    --pz;
    return (msk>>pz)&1;
}
int v[17][10004],dst[17][17],dst1[17][17];
int main()
{
    int msk,i,j,mx=-999999999,pz,k=0,pas=1<<20,cur=1,a,b,aa,bb,cc,dd,rez,n,m,st,dr,rezf=0;
    int mn=-mx;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    for(i=1;i<=n;++i)
        d[i][i][1<<(i-1)]=-mx;
    if(n==1)
    {
        for(i=2;i<=m;++i)
            mn=min(mn,abs(v[1][i]-v[1][i-1]));
        cout<<mn;
        return 0;
    }
    for(i=1;i<=n;++i)
        for(int ii=1;ii<=n;++ii)
        {
            if(i==ii)
                continue;
            mn=-mx;
            for(j=1;j<=m;++j)
                mn=min(mn,abs(v[i][j]-v[ii][j]));
            dst[i][ii]=mn;
        }
    for(msk=1;msk<(1<<n);++msk)
    {
        for(st=1;st<=n;++st)
        {
            if(verif(msk,st))
            for(dr=1;dr<=n;++dr)
            {
                if(verif(msk,dr))
                for(j=1;j<=n;++j)
                {
                    if(!verif(msk,j))
                    {
                        int nmsk=msk+(1<<(j-1));
                        d[st][j][nmsk]=max(d[st][j][nmsk],min(d[st][dr][msk],dst[dr][j]));
                        cur=2;
                    }
                }
            }
        }
    }
    for(i=1;i<=n;++i)
    {
        for(int ii=1;ii<=n;++ii)
        {
            if(i==ii)
                continue;
            mn=-mx;
            for(j=1;j<m;++j)
                mn=min(mn,abs(v[i][j]-v[ii][j+1]));
            dst1[i][ii]=mn;
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            rezf=max(rezf,min(d[i][j][(1<<n)-1],dst1[i][j]));
    cout<<rezf;
}